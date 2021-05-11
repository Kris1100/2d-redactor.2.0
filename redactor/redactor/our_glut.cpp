#include "our_glut.h"
void Display(void) {
	glColor3ub(255, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(50, 150);
	glVertex2f(50, 50);
	glVertex2f(150, 50);
	glVertex2f(150, 150);
	glEnd();
	glFinish();
}
void Reshape(GLint w, GLint h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
}
void main_pr(int argc, char* argv[]) {
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(512, 512);
	glutDisplayFunc(Display);
}