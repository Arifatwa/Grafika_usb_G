#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void display() {
    // Set background color
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw four circles using for loop
    for (int i = 0; i < 4; i++) {
        // Set color
        glColor3f(1.0 * i / 4.0, 0.0, 0.0);

        // Draw circle
        glBegin(GL_LINE_LOOP);
        glVertex2f(0.0, 0.0);
        glVertex2f(1.0, 0.0);
        glVertex2f(1.0, 1.0);
        glVertex2f(0.0, 1.0);
        glEnd();
    }

    // Swap buffers
    glutSwapBuffers();
}

void reshape(int w, int h) {
    // Set viewport
    glViewport(0, 0, w, h);

    // Set projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);

    // Set modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Circle");

    // Initialize OpenGL
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);

    // Set callback functions
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // Enter main loop
    glutMainLoop();
}