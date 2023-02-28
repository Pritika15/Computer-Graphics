#include <gl/glut.h>
#include <stdio.h>

#include<cmath>


int X1, Y1, X2, Y2;
void myInit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}
void print(int a, int b)
{
	printf(" (%d, %d)\n", a, b);
}
void linedda(int X1, int Y1, int X2, int Y2)
{
	float dy, dx, step, x, y, k, Xin, Yin;
	dx = X2 - X1;
	dy = Y2 - Y1;

	if (abs(dx) > abs(dy))
	{
		step = abs(dx);
	}
	else
		step = abs(dy);

	Xin = dx / step;
	Yin = dy / step;

	x = X1;
	y = Y1;
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();

	for (k = 1; k <= step; k++)
	{
		x = x + Xin;
		y = y + Yin;

		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
		print(x, y);
	}
}
void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	linedda(100, 100, 100, 300);
	linedda(100, 300, 300, 300);
	linedda(300, 300, 300, 250);
	linedda(300, 250, 100, 250);
	linedda(300, 250, 300, 200);
	linedda(300, 200, 100, 200);
	linedda(300, 150, 100, 150);
	linedda(300, 200, 300, 150);
	
	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(" Line Drawing using DDA");
	myInit();
	glutDisplayFunc(draw);
	
	glutMainLoop();
	return 0;
}