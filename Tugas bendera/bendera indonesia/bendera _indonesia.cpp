#include <GL/glut.h>

void segitiga() {

    // persegi panjang putih
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.80, 0.30);
    glVertex2f(0.80, 0.50);
    glVertex2f(0.10, 0.50);
    glVertex2f(0.10, 0.30);
    glEnd();

    // persegi panjang merah
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.10, 0.50);
    glVertex2f(0.10, 0.70);
    glVertex2f(0.80, 0.70);
    glVertex2f(0.80, 0.50);
    glEnd();


    glEnd(); // Selesai menggambar persegi panjang
}




void display() {
    glClearColor(0.6, 0.8, 1.0, 1.0); // Mengatur warna latar belakang menjadi biru muda (RGBA: 0.6, 0.8, 1.0, 1.0)

    glClear(GL_COLOR_BUFFER_BIT); // Membersihkan layar dengan warna latar belakang yang baru

    glLoadIdentity();
    segitiga();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(80, 80, 80, 80);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("OpenGL Segitiga dan Persegi");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}