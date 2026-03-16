#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    /* Bagian atas mobil */
    glTranslatef(0.15, 0.25, 0.0);
    glBegin(GL_QUADS);
        glColor3f(0.576f, 0.02f, 0.0f);
        glVertex2f(-0.4, -0.1); 
        glVertex2f(0.4, -0.1);  
        glVertex2f(0.2, 0.2);   
        glVertex2f(-0.2, 0.2);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    /* Bagian bawah mobil */
    glTranslatef(0.035, 0.0, 0.0);
    glColor3f(0.576f, 0.02f, 0.0f);
    glRectf(-0.50, -0.15, 0.70, 0.15);
    glPopMatrix();
    
    glPushMatrix();
    /* Jendela Mobil 1 */
    glTranslatef(0.05, 0.25, 0.0);
	glBegin(GL_QUADS);
	 	glColor3f(0.584f, 0.733f, 0.918f);
        glVertex2f(-0.26, -0.1); 
		glVertex2f(0.08, -0.1);  
		glVertex2f(0.08, 0.15);   
		glVertex2f(-0.1, 0.15); 
    glEnd();
    glPopMatrix();
    
    /* Jendela Mobil 2*/
    glPushMatrix();
	glTranslatef(0.25, 0.25, 0.0);
	glBegin(GL_QUADS);
    	glColor3f(0.584f, 0.733f, 0.918f);
		glVertex2f(0.26, -0.1);
    	glVertex2f(-0.08, -0.1);
    	glVertex2f(-0.08, 0.15);
    	glVertex2f(0.1, 0.15);
	glEnd();
	glPopMatrix();

    /* Roda Depan */
	glPushMatrix();
#define PI 3.1415926535898
	glLineWidth(9.0);
	glTranslatef(-0.25, -0.15, 0.0);
    glBegin(GL_LINE_LOOP);
        GLint circle_points = 100;
        int i;
        float angle;
        float radius = 0.12;
        for (i = 0; i < circle_points; i++) {
            glColor3f(0.0f, 0.0f, 0.0f);
			angle = 2 * PI * i / circle_points;
            glVertex2f(radius * cos(angle), radius * sin(angle));
        }
    glEnd();
    glPopMatrix();
    
    /* garis dalam ban */
    glLineWidth(7.0);
    glTranslatef(-0.25, -0.15, 0.0);
	glBegin(GL_LINES);
	for(int i = 0; i < 8; i++) {   
    	glColor3f(0.0f, 0.0f, 0.0f);
		angle = 2 * PI * i / 8;
	glVertex2f(0,0);  
    glVertex2f(radius * cos(angle), radius * sin(angle)); 
	}
	glEnd();
	glPopMatrix();

	/* Roda Belakang */
	glPushMatrix();
#define PI 3.1415926535898
	glLineWidth(9.0);
	glTranslatef(0.78, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        for (i = 0; i < circle_points; i++) {
            glColor3f(0.0f, 0.0f, 0.0f);
			angle = 2 * PI * i / circle_points;
            glVertex2f(radius * cos(angle), radius * sin(angle));
        }
    glEnd();
    glPopMatrix();
    
    /* garis dalam ban */
    glLineWidth(7.0);
    glTranslatef(0.78, 0.0, 0.0);
	glBegin(GL_LINES);
	for(int i = 0; i < 8; i++) {   
    	glColor3f(0.0f, 0.0f, 0.0f);
		angle = 2 * PI * i / 8;
	glVertex2f(0,0);  
    glVertex2f(radius * cos(angle), radius * sin(angle)); 
	}
	glEnd();
	glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(740,500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Nouvella Rahma Fitrah Legarsi");
    glutDisplayFunc(RenderScene);
    glClearColor(1.0f, 0.973f, 0.906f, 1.0f);
    glutMainLoop();
    return 0;
}
