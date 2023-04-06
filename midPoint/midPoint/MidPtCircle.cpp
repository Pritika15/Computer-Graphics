
#include <gl/glut.h>
#include <stdio.h>

void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0f, 1.0f, 0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void draw_pixel(int x, int y)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void reflection(int x, int y, int xc, int yc)
{
	draw_pixel(-x + xc, y + yc);
	draw_pixel(x + xc, y + yc);
	draw_pixel(y + xc, x + yc);
	draw_pixel(y + xc, -x + yc);
	draw_pixel(x + xc, -y + yc);
	draw_pixel(-x + xc, -y + yc);
	draw_pixel(-y + xc, -x + yc);
	draw_pixel(-y + xc, x + yc);
}


void circle(int r, int xc, int yc)
{
	int p = 1 - r;
	int x = 0;
	int y = r;
	reflection(x, y, xc, yc);
	while (x <= y)
	{

		if (p < 0)
		{
			p = p + 2 * x + 3;
			x++;
		}
		else {
			p = p + 2 * (x - y) + 5;
			y--;
			x++;
		}
		reflection(x, y, xc, yc);
	}

}


void draw1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	circle(100, 320, 240);
	glFlush();

}




int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(" MidPoint Circle");
	myInit();
	glutDisplayFunc(draw1);
	glutMainLoop();
	return 0;
}
