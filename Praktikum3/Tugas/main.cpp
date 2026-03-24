#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0;
static int wrist = 0, wristRotate = 0;

int fingerBase[5] = {0};
int fingerMid[5]  = {0};

/* ================= FUNGSI JARI ================= */
void drawFinger(int idx, float x, float y, float z, float length, float width) {
    glPushMatrix();
    glTranslatef(x, y, z);

    // RUAS 1
    glRotatef((GLfloat)fingerBase[idx], 0, 0, 1);
    glTranslatef(length / 4.0, 0, 0);

    glPushMatrix();
    glScalef(length / 2.0, width, width);
    glutWireCube(1.0);
    glPopMatrix();

    // RUAS 2
    glTranslatef(length / 4.0, 0, 0);
    glRotatef((GLfloat)fingerMid[idx], 0, 0, 1);
    glTranslatef(length / 4.0, 0, 0);

    glPushMatrix();
    glScalef(length / 2.0, width, width);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();
}

/* ================= DISPLAY ================= */
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // 1. SHOULDER (Bahu)
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // 2. ELBOW (Siku)
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(0.8, 0.0, 0.0);
    
    glPushMatrix();
    glScalef(1.6, 0.4, 0.8);
    glutWireCube(1.0);
    glPopMatrix();

    // 3. WRIST (Pergelangan)
    glTranslatef(0.8, 0.0, 0.0);
    glRotatef((GLfloat)wristRotate, 1.0, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
    
    // TELAPAK TANGAN 
    glPushMatrix();
    glScalef(0.6, 0.4, 0.9);
    glutWireCube(1.0);
    glPopMatrix();

    // 4. JARI-JARI 
    float p = 0.3; 

    
    drawFinger(3, p, 0.0, -0.3, 0.4, 0.08); // Kelingking
    drawFinger(2, p, 0.0, -0.1, 0.5, 0.09); // Manis
    drawFinger(1, p, 0.0,  0.1, 0.6, 0.10); // Tengah
    drawFinger(0, p, 0.0,  0.3, 0.5, 0.09); // Telunjuk

    // IBU JARI 
    glPushMatrix();
    glTranslatef(-0.1, 0.0, 0.4); 
    glRotatef(-40, 0, 1, 0); 
    glRotatef(-20, 0, 0, 1);
    drawFinger(4, 0, 0, 0, 0.4, 0.11);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

/* ================= KEYBOARD ================= */
void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 's': shoulder = (shoulder+5)%360; break;
        case 'S': shoulder = (shoulder-5)%360; break;
        case 'e': elbow = (elbow+5)%360; break;
        case 'E': elbow = (elbow-5)%360; break;
        case 'w': if(wrist<90) wrist+=5; break;
        case 'W': if(wrist>-90) wrist-=5; break;
        case 'r': wristRotate = (wristRotate+5)%360; break;
        case 'R': wristRotate = (wristRotate-5)%360; break;
        case '1': if(fingerBase[0]<90) fingerBase[0]+=5; break;
        case '!': if(fingerBase[0]>0)  fingerBase[0]-=5; break;
        case 'q': if(fingerMid[0]<90) fingerMid[0]+=5; break;
        case 'Q': if(fingerMid[0]>0)  fingerMid[0]-=5; break;
        case '2': if(fingerBase[1]<90) fingerBase[1]+=5; break;
        case '@': if(fingerBase[1]>0)  fingerBase[1]-=5; break;
        case 'a': if(fingerMid[1]<90) fingerMid[1]+=5; break;
        case 'A': if(fingerMid[1]>0)  fingerMid[1]-=5; break;
        case '3': if(fingerBase[2]<90) fingerBase[2]+=5; break;
        case '#': if(fingerBase[2]>0)  fingerBase[2]-=5; break;
        case 'z': if(fingerMid[2]<90) fingerMid[2]+=5; break;
        case 'Z': if(fingerMid[2]>0)  fingerMid[2]-=5; break;
        case '4': if(fingerBase[3]<90) fingerBase[3]+=5; break;
        case '$': if(fingerBase[3]>0)  fingerBase[3]-=5; break;
        case 'x': if(fingerMid[3]<90) fingerMid[3]+=5; break;
        case 'X': if(fingerMid[3]>0)  fingerMid[3]-=5; break;
        case '5': if(fingerBase[4]<90) fingerBase[4]+=5; break;
        case '%': if(fingerBase[4]>0)  fingerBase[4]-=5; break;
        case 'c': if(fingerMid[4]<90) fingerMid[4]+=5; break;
        case 'C': if(fingerMid[4]>0)  fingerMid[4]-=5; break;
        case 27: exit(0);
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
    glutInitWindowSize(800, 600);
    glutCreateWindow("Nouvella Rahma Fitrah Legarsi");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
