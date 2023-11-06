#include <Windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);

void titik(int x, int y) {
    float r = 1.0;
    float g = 0.0;
    float b = 0.0;

    glColor3f(r, g, b);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex3i(x, y, 0);
    glEnd();
}

void garis(int x1, int y1, int x2, int y2) {
    float r = 0.0;
    float g = 0.0;
    float b = 1.0;

    glColor3f(r, g, b);
    glBegin(GL_LINES);
    glVertex3i(x1, y1, 0);
    glVertex3i(x2, y2, 0);
    glEnd();
}

void poligon(int x[], int y[], int n) {
    float r = 0.0;
    float g = 1.0;
    float b = 0.0;

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++) {
        glVertex3i(x[i], y[i], 0);
    }
    glEnd();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Titik, Garis, dan Poligon");
    init(); //memanggil fungsi init
    glutDisplayFunc(display); //memanggil fungsi display
    glutMainLoop(); //untuk menjalankan program
    return 0;
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);

    //aktifkan mode garis
    glEnable(GL_LINE_SMOOTH);

    //atur ketebalan garis
    glLineWidth(2.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    //menggambar segitiga menggunakan triangle strip
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3i(1, 4, 0);
    glVertex3i(5, 8, 0);
    glVertex3i(6, -8, 0);
    glEnd();

    //menggambar segitiga menggunakan triangle fan
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3i(1, 4, 0);
    glVertex3i(5, 8, 0);
    glVertex3i(6, -8, 0);
    glEnd();

    //menggambar segi empat menggunakan quad strip
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.2, 0.6, 0.8);
    glVertex3i(-7, 4, 0);
    glVertex3i(-5, 3, 0);
    glVertex3i(6, -8, 0);
    glVertex3i(2, 6, 0);
    glEnd();

    glutSwapBuffers();
}
