#include <Windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif 
#include <stdlib.h>
#include <math.h>

void init(void);
void display(void);


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("laelia glLineStrip");
    init(); //memanggil fungsi init
    glutDisplayFunc(display); //memanggil fungsi display
    glutMainLoop(); //untuk menjalankan program
    return 0;
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);

    //aktifkan mode garis
    glEnable(GL_LINE_SMOOTH);

    //atur ketebalan garis
    glLineWidth(2.0);
}

void ngon(int n, float cx, float cy, float radius, float rotAngle) {
    double angle, angleInc;
    int k;

    if (n < 3)return;
    angle = rotAngle * 3.14159265 / 180;
    angleInc = 2 * 3.14159265 / n;
    
    //titik pertama
    glVertex2f(radius * cos(angle) + cy, radius * sin(angle) + cy);
    
    //titik berikutnya
    for (k = 0; k < n; k++) {
        angle += angleInc;
        glVertex2f(radius * cos(angle) + cy, radius * sin(angle) + cy);
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_STRIP);
        /* glVertex2f(40 * cos(2 * 3.14159265 * 1 / 6), 40 * sin(2 * 3.14159265 * 1 / 6));
        glVertex2f(40 * cos(2 * 3.14159265 * 2 / 6), 40 * sin(2 * 3.14159265 * 2 / 6));
        glVertex2f(40 * cos(2 * 3.14159265 * 3 / 6), 40 * sin(2 * 3.14159265 * 3 / 6));
        glVertex2f(40 * cos(2 * 3.14159265 * 4 / 6), 40 * sin(2 * 3.14159265 * 4 / 6));
        glVertex2f(40 * cos(2 * 3.14159265 * 5 / 6), 40 * sin(2 * 3.14159265 * 5 / 6));
        glVertex2f(40 * cos(2 * 3.14159265 * 6 / 6), 40 * sin(2 * 3.14159265 * 6 / 6)); */
    ngon(6, 10, 0, 40, 180);
    // 6 adalah seginya,40 adlh radiusnya, 180 adlh derajat
    glEnd(); 

    



    glutSwapBuffers();
}
