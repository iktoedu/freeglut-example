#include <iostream>
#include <GL/freeglut.h>

#define X1   -200
#define X2   200
#define Y1   -200
#define Y2   200

using namespace std;

void Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glLoadIdentity();
    gluOrtho2D(X1, X2, Y1, Y2);
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.5f, 0.0f);

    glLineWidth(1);

    glBegin(GL_LINES);
        glVertex2f(X1, 0);
        glVertex2f(X2, 0);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0, Y1);
        glVertex2f(0, Y2);
    glEnd();

    glLineWidth(5);

    glBegin(GL_LINE_LOOP);
        glVertex2f(-100, -100);
        glVertex2f(100, -100);
        glVertex2f(100, 100);
        glVertex2f(-100, 100);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);

    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("FreeGLUT example");

    glutReshapeFunc(Reshape);
    glutDisplayFunc(Draw);

    glClearColor(1, 1, 1, 1);

    glutMainLoop();

    return 0;
}
