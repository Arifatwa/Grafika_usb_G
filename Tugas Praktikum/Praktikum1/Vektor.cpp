#include <Windows.h>
#ifdef _APPLE_


#else
#include <GL/glut.h>
#endif // _APPLE_
#include<stdio.h>
#include <stdlib.h>
#include <math.h> // Tambahkan header math.h
#include <stdlib.h>

class GLintPoint
{
public:
    GLint x, y;
};

class Point2
{
public:
    float x, y;
    void set(float dx, float dy)
    {
        x = dx;
        y = dy;
    }
    void set(Point2& p)
    {
        x = p.x;
        y = p.y;
    }
    Point2(float xx, float yy)
    {
        x = xx;
        y = yy;
    }
    Point2()
    {
        x = y = 0;
    }
};

GLintPoint CP;

float lerp(float a, float b, float t)
{
    return a + (b - a) * t;
}

Point2 Tween(Point2 A, Point2 B, float t)
{
    Point2 P;
    P.x = lerp(A.x, B.x, t);
    P.y = lerp(A.y, B.y, t);
    return P;
}

void myInit(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 400.0);
}

void moveTo(GLint x, GLint y)
{
    CP.x = x;
    CP.y = y;
}

void lineTo(GLint x, GLint y)
{
    glBegin(GL_LINES);
    glVertex2i(CP.x, CP.y);
    glVertex2i(x, y);
    glEnd();
    glutSwapBuffers();
    CP.x = x;
    CP.y = y;
}

void drawTween(Point2 A[], Point2 B[], int n, float t)
{
    for (int i = 0; i < n; i++)
    {
        Point2 P;
        P = Tween(A[i], B[i], t);
        if (i == 0)
            moveTo(static_cast<GLint>(P.x), static_cast<GLint>(P.y));
        else
            lineTo(static_cast<GLint>(P.x), static_cast<GLint>(P.y));
    }
}

void myDisplay(void)
{
    int x;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);

    Point2 A[24];
    A[0].set(5, 160);
    A[1].set(10, 150);
    A[2].set(75, 180);
    A[3].set(100, 120);
    A[4].set(110, 130);
    A[5].set(90, 190);
    A[6].set(90, 250);
    A[7].set(130, 290);
    A[8].set(120, 300);
    A[9].set(90, 270);
    A[10].set(80, 270);
    A[11].set(90, 280);
    A[12].set(90, 300);
    A[13].set(95, 310);
    A[14].set(75, 310);
    A[15].set(70, 300);
    A[16].set(70, 280);
    A[17].set(75, 270);
    A[18].set(60, 270);
    A[19].set(30, 300);
    A[20].set(20, 290);
    A[21].set(65, 250);
    A[22].set(65, 190);
    A[23].set(5, 160);

    Point2 B[24];
    B[0].set(700, 100);
    B[1].set(710, 100);
    B[2].set(730, 100);
    B[3].set(750, 100);
    B[4].set(760, 100);
    B[5].set(750, 170);
    B[6].set(750, 230);
    B[7].set(770, 170);
    B[8].set(780, 170);
    B[9].set(755, 250);
    B[10].set(735, 250);
    B[11].set(740, 260);
    B[12].set(740, 290);
    B[13].set(735, 290);
    B[14].set(720, 290);
    B[15].set(725, 280);
    B[16].set(716, 260);
    B[17].set(720, 250);
    B[18].set(705, 250);
    B[19].set(685, 320);
    B[20].set(675, 320);
    B[21].set(700, 230);
    B[22].set(710, 170);
    B[23].set(700, 100);

    glColor3f(1, 0, 0);
    drawTween(A, B, 24, 0.0);

    glColor3f(0, 0, 1);
    for (x = 1; x <= 9; x += 1)
    {
        drawTween(A, B, 24, 0.1f * x);
    }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Laeliaa");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}