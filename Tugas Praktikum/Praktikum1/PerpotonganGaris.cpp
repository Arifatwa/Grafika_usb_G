#include <Windows.h>
#ifdef _APPLE_


#else
#include <GL/glut.h>
#endif // _APPLE_
#include<stdio.h>
#include <stdlib.h>
#include <math.h> // Tambahkan header math.h
#include <stdlib.h>

void init(void);
void display(void);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("My First OpenGL Application");
    init();
    glutDisplayFunc(display);  // Register the display callback function
    glutMainLoop();  // Enter the GLUT event loop
    return 0;
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);  // Set the background color to black
    //glColor3f(0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 10, 0, 10);
}



void display(void) {
    //garis ab
    float ax = 1;
    float ay = 1;
    float bx = 5;
    float by = 5;
    //garis cd
    float cx = 1;
    float cy = 3;
    float dx = 5;
    float dy = 1;

    float m1, m2, c1, c2, ex, ey;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(ax, ay);
    glVertex2f(bx, by);

    glVertex2f(cx, cy);
    glVertex2f(dx, dy);
    glEnd();

    m1 = (by - ay) / (bx - ax);
    c1 = ay - (m1 * ax);

    //cd
    m2 = (dy - cy) / (dx - cx);
    c2 = cy - (m2 * cx);

    //tent titik potong
    ex = (c2 - c1) / (m1 - m2);
    ey = (m1 * ex) + c1;
    printf(" %f, %f", ex, ey);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(ex, ey);
    glEnd();
    glFlush();
    glutSwapBuffers();
}