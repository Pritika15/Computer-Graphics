
#include <stdio.h>
#include <math.h>
#include <gl/glut.h>


void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480);
}
void drawDot(GLint x, GLint y, GLfloat r, GLfloat g, GLfloat b)
{
    glColor3f(r, g, b);
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void symmetricPixels(int x, int y, int xc, int yc, float r, float g, float b)
{
    drawDot(xc + x, yc + y, r, g, b);
    drawDot(xc - x, yc + y, r, g, b);
    drawDot(xc + x, yc - y, r, g, b);
    drawDot(xc - x, yc - y, r, g, b);
}
void Ellipse(int a, int b, int xc, int yc, float r, float g, float bl)
{
    int aSq, bSq, twoASq, twoBSq, d, dx, dy, x, y;
    aSq = a * a;
    bSq = b * b;
    twoASq = 2 * aSq;
    twoBSq = 2 * bSq;
    d = bSq - b * aSq + aSq / 4;
    dx = 0;
    dy = twoASq * b;
    x = 0;
    y = b;
    symmetricPixels(x, y, xc, yc, r, g, bl);
    while (dx < dy)
    {
        x++;
        dx += twoBSq;
        if (d >= 0)
        {
            y--;
            dy -= twoASq;
        }
        if (d < 0)
            d += bSq + dx;
        else
            d += bSq + dx - dy;
        symmetricPixels(x, y, xc, yc, r, g, bl);
    }
    d = (int)(bSq * (x + 0.5) * (x + 0.5) + aSq * (y - 1) * (y - 1) -
        aSq * bSq);
    while (y > 0)
    {
        y--;
        dy -= twoASq;
        if (d <= 0)
        {
            x++;
            dx += twoBSq;
        }
        if (d > 0)
            d += aSq - dy;
        else
            d += aSq - dy + dx;
        symmetricPixels(x, y, xc, yc, r, g, bl);
    }
    glFlush();
}
void display1()
{
    Ellipse(100, 50, 320, 240, 1.0, 1.0, 0.0);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(" Ellipse Drawing ");
    init();
    glutDisplayFunc(display1);
    glutMainLoop();
    return 0;
}
