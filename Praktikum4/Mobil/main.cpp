#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>s

// ==========================
// VARIABEL KAMERA
// ==========================

float angle = 0.0f;
float deltaAngle = 0.0f;

float x = 0.0f;
float y = 5.0f;
float z = 20.0f;

float lx = 0.0f;
float ly = 0.0f;
float lz = -1.0f;

float ratio;

int deltaMove = 0;
int h, w;

// ==========================
// LIGHTING
// ==========================

const GLfloat light_ambient[]  = {0.5f, 0.5f, 0.5f, 1.0f};
const GLfloat light_diffuse[]  = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_position[] = {0.0f, 20.0f, 10.0f, 1.0f};

const GLfloat mat_ambient[]    = {0.7f, 0.7f, 0.7f, 1.0f};
const GLfloat mat_diffuse[]    = {0.8f, 0.8f, 0.8f, 1.0f};
const GLfloat mat_specular[]   = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat high_shininess[] = {100.0f};

// ==========================
// RESHAPE
// ==========================

void Reshape(int w1, int h1)
{
    if (h1 == 0)
        h1 = 1;

    w = w1;
    h = h1;

    ratio = 1.0f * w / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);

    gluPerspective(45.0f, ratio, 0.1f, 1000.0f);

    glMatrixMode(GL_MODELVIEW);
}

void orientMe(float ang)
{
    lx = sin(ang);
    lz = -cos(ang);

    glLoadIdentity();

    gluLookAt(
        x, y, z,
        x + lx, y + ly, z + lz,
        0.0f, 1.0f, 0.0f
    );
}

void moveMeFlat(int i)
{
    x = x + i * (lx) * 0.03f;
    z = z + i * (lz) * 0.03f;

    glLoadIdentity();

    gluLookAt(
        x, y, z,
        x + lx, y + ly, z + lz,
        0.01f, 1.0f, 0.0f
    );
}

// ==========================
// GRID
// ==========================

void Grid()
{
    double i;

    const float Z_MIN = -50;
    const float Z_MAX = 50;

    const float X_MIN = -50;
    const float X_MAX = 50;

    const float gap = 1.5f;

    glColor3f(0.5f, 0.5f, 0.5f);

    glBegin(GL_LINES);

    for (i = Z_MIN; i < Z_MAX; i += gap)
    {
        glVertex3f(i, 0, Z_MIN);
        glVertex3f(i, 0, Z_MAX);
    }

    for (i = X_MIN; i < X_MAX; i += gap)
    {
        glVertex3f(X_MIN, 0, i);
        glVertex3f(X_MAX, 0, i);
    }

    glEnd();
}

// ==========================
// BALOK DASAR
// ==========================

void Balok(float panjang, float tinggi, float lebar)
{
    glPushMatrix();
    glScalef(panjang, tinggi, lebar);
    glutSolidCube(1);
    glPopMatrix();
}

// ==========================
// RODA
// ==========================

void Roda(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    // Putar roda agar menghadap ke samping
    glRotatef(0, 90, 1, 0); 
    glColor3f(0.1f, 0.1f, 0.1f); // Warna 
    GLUquadricObj *quadric = gluNewQuadric();
    // gluCylinder(obj, baseRadius, topRadius, height, slices, stacks)
    glTranslatef(0, 0, -0.25); 
    gluCylinder(quadric, 0.6, 0.6, 0.5, 30, 30);
    
    // velg luar
    gluDisk(quadric, 0, 0.6, 30, 1);
    
    // velg dalam
    glTranslatef(0, 0, 0.5);
    gluDisk(quadric, 0, 0.6, 30, 1);

    gluDeleteQuadric(quadric);
    glPopMatrix();
}

// ==========================
// MOBIL 
// ==========================

void Mobil()
{
    // BODY BAWAH 
    glPushMatrix();
    glColor3f(0.8f, 0.1f, 0.1f);
    glTranslatef(0, 1.5, 0);
    Balok(6, 1.2, 3);
    glPopMatrix();

    // KABIN ATAS
    glPushMatrix();
    glColor3f(0.6f, 0.0f, 0.0f);
    glTranslatef(-0.5, 2.6, 0); 
    Balok(3, 1.0, 2.8);
    glPopMatrix();

    // KACA DEPAN 
    glPushMatrix();
    glColor3f(0.5f, 0.8f, 1.0f);
    glTranslatef(1.0, 2.6, 0); 
    Balok(0.1, 0.8, 2.6); 
    glPopMatrix();

    // POSISI RODA 
    // Format: Roda(X, Y, Z)
    Roda( 2.0f, 1.0f,  1.5f);
    Roda( 2.0f, 1.0f, -1.5f);
    Roda(-2.0f, 1.0f,  1.5f);
    Roda(-2.0f, 1.0f, -1.5f);

    // LAMPU DEPAN 
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.8f);
    glTranslatef(3.0, 1.5, 1.0);
    glutSolidSphere(0.2, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.8f);
    glTranslatef(3.0, 1.5, -1.0);
    glutSolidSphere(0.2, 20, 20);
    glPopMatrix();
}

// ==========================
// DISPLAY
// ==========================

void display()
{
    if (deltaMove)
        moveMeFlat(deltaMove);

    if (deltaAngle)
    {
        angle += deltaAngle;
        orientMe(angle);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(
        x, y, z,
        x + lx, y + ly, z + lz,
        0.0f, 1.0f, 0.0f
    );

    // GRID
    Grid();

    // MOBIL
    Mobil();

    glutSwapBuffers();
    glFlush();
}

// ==========================
// KEYBOARD
// ==========================

void pressKey(int key, int xx, int yy)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
            deltaAngle = -0.01f;
            break;

        case GLUT_KEY_RIGHT:
            deltaAngle = 0.01f;
            break;

        case GLUT_KEY_UP:
            deltaMove = 1;
            break;

        case GLUT_KEY_DOWN:
            deltaMove = -1;
            break;
    }
}

void releaseKey(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
            if (deltaAngle < 0.0f)
                deltaAngle = 0.0f;
            break;

        case GLUT_KEY_RIGHT:
            if (deltaAngle > 0.0f)
                deltaAngle = 0.0f;
            break;

        case GLUT_KEY_UP:
            if (deltaMove > 0)
                deltaMove = 0;
            break;

        case GLUT_KEY_DOWN:
            if (deltaMove < 0)
                deltaMove = 0;
            break;
    }
}

// ==========================
// LIGHTING
// ==========================

void lighting()
{
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

// ==========================
// INIT
// ==========================

void init()
{
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.2f, 0.6f, 1.0f, 1.0f);
}

// ==========================
// MAIN
// ==========================

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Nouvella Rahma Fitrah Legarsi");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(Reshape);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutIgnoreKeyRepeat(1);
    lighting();
    init();
    glutMainLoop();

    return 0;
}
