#include <GL/glut.h>

void segitiga() {
    // Persegi panjang putih
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.40, -0.15); // Mengubah nilai x dan y agar berada di tengah
    glVertex2f(0.40, -0.35); // Mengubah nilai x dan y agar berada di tengah
    glVertex2f(-0.40, -0.35); // Mengubah nilai x dan y agar berada di tengah
    glVertex2f(-0.40, -0.15); // Mengubah nilai x dan y agar berada di tengah
    glEnd();

    // Persegi panjang merah
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.40, -0.35); // Mengubah nilai x dan y agar berada di tengah
    glVertex2f(-0.40, -0.55); // Mengubah nilai x dan y agar berada di tengah
    glVertex2f(0.40, -0.55); // Mengubah nilai x dan y agar berada di tengah
    glVertex2f(0.40, -0.35); // Mengubah nilai x dan y agar berada di tengah
    glEnd();
}

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Warna hitam
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    segitiga();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 0.0, 0.0, 0.0); // Mengatur ulang jendela tampilan agar bendera berada di tengah
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("OpenGL Segitiga dan Persegi Terbalik");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop(); 
    return 0;
}
