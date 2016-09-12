#include <windows.h>
#include <gl/glut.h>

#include <stdlib.h>

/* GLUT callback Handlers */
float angulo;

static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	angulo += 0.04f;
	
	
	glPushMatrix();
		
		/*Sol*/
		glTranslatef(0, 0, -40);
		glRotatef(angulo, 0, 1, 0);
		glColor3f(1, 1, 0);
		glutSolidSphere(3, 16, 16);

		/*Mercurio*/
		glPushMatrix();
			glTranslatef(0, 0, -4.5);
			glRotatef(-angulo, 0, 1, 0);
			glColor3f(0.5,0.5,0.5);
			glutSolidSphere(.5, 16, 16);
		glPopMatrix();

		/*Venus*/
		glPushMatrix();
			glTranslatef(0, 0, -6.5);
			glRotatef(-angulo, 0, 1, 0);
			glColor3f(1, .5, 0);
			glutSolidSphere(.7, 16, 16);
		glPopMatrix();

		/*Tierra*/
		glPushMatrix();
			glTranslatef(0, 0, -8.5);
			glRotatef(-angulo, 0, 1, 0);
			glColor3f(0, 0, 1);
			glutSolidSphere(1, 16, 16);
			
			/*Luna*/
			glPushMatrix();
				glRotatef(angulo * 3, 0, 0, 1);
				glTranslatef(1.3, 1.3, 1.3);				
				glColor3f(0.5, 0.5, 0.5);
				glutSolidSphere(.5, 16, 16);
			glPopMatrix();

		glPopMatrix();

		/*Marte*/
		glPushMatrix();
			glTranslatef(0, 0, -11);
			glRotatef(-angulo, 0, 1, 0);
			glColor3f(1, .3, 0);
			glutSolidSphere(.85, 16, 16);

			/*Luna*/
			glPushMatrix();
				glRotatef(angulo * 3, 0, 0, 1);
				glTranslatef(1.3, 1.3, 1.3);
				glColor3f(.8, 0.5, 0.5);
				glutSolidSphere(.3, 16, 16);
			glPopMatrix();

			/*Luna*/
			glPushMatrix();
				glRotatef(angulo * 3, 0, 0, 1);
				glTranslatef(-2, 2, 2);
				glColor3f(0.8, 0.5, 0.5);
				glutSolidSphere(.2, 16, 16);
			glPopMatrix();

		glPopMatrix();

		/*Jupiter*/
		glPushMatrix();
			glTranslatef(0, 0, -14.5);
			glRotatef(-angulo, 0, 1, 0);
			glColor3f(1, .1, 0);
			glutSolidSphere(1.5, 16, 16);

			/*Luna*/
			glPushMatrix();
				glRotatef(angulo * 3, 0, 0, 1);
				glTranslatef(1.2, 1, -2);
				glColor3f(0.5, 1, 0.5);
				glutSolidSphere(.2, 16, 16);
			glPopMatrix();

			/*Luna*/
			glPushMatrix();
				glRotatef(angulo * 3, 0, 0, 1);
				glTranslatef(2, -2, 2);
				glColor3f(0.8, 0.5, 0.5);
				glutSolidSphere(.2, 16, 16);
			glPopMatrix();

			/*Luna*/
			glPushMatrix();
				glRotatef(angulo * 3, 0, 0, 1);
				glTranslatef(-1.5, -1, 1.8);
				glColor3f(0.8, 0.5, 0.5);
				glutSolidSphere(.2, 16, 16);
			glPopMatrix();

			/*Luna*/
			glPushMatrix();
				glRotatef(angulo * 3, 0, 0, 1);
				glTranslatef(-1, 2, 2);
				glColor3f(0.8, 0.5, 0.5);
				glutSolidSphere(.2, 16, 16);
			glPopMatrix();
		glPopMatrix();

		/*Saturno*/
		glPushMatrix();
			glTranslatef(0, 0, -18);
			glRotatef(-angulo, 0, 1, 0);
			glColor3f(.5, .09, 0);
			glutSolidSphere(1.6, 16, 16);

			/*Luna*/
			glPushMatrix();
				glRotatef(angulo * 3, 0, 0, 1);
				glTranslatef(1.2, 1, -2);
				glColor3f(0.5, 1, 0.5);
				glutSolidSphere(.2, 16, 16);
			glPopMatrix();

			/*Luna*/
			glPushMatrix();
				glRotatef(angulo * 3, 0, 0, 1);
				glTranslatef(2, -2, 2);
				glColor3f(0.8, 0.5, 0.5);
				glutSolidSphere(.2, 16, 16);
			glPopMatrix();

			/*Luna*/
			glPushMatrix();
				glRotatef(angulo * 3, 0, 0, 1);
				glTranslatef(-1.5, -1, 1.8);
				glColor3f(0.8, 0.5, 0.5);
				glutSolidSphere(.2, 16, 16);
			glPopMatrix();

			/*Luna*/
			glPushMatrix();
				glRotatef(angulo * 3, 0, 0, 1);
				glTranslatef(-1, 2, 2);
				glColor3f(0.8, 0.5, 0.5);
				glutSolidSphere(.2, 16, 16);
			glPopMatrix();		

		glPopMatrix();

		/*Uranus*/
		glPushMatrix();
			glTranslatef(0, 0, -21);
			glRotatef(-angulo, 0, 1, 0);
			glColor3f(0, 0, .9);
			glutSolidSphere(1.1, 16, 16);

			/*Luna*/
			glPushMatrix();
				glRotatef(-angulo * 3, 0, 0, 1);
				glTranslatef(-1.2, 1, -2);
				glColor3f(0.5, 1, 0.5);
				glutSolidSphere(.2, 16, 16);
			glPopMatrix();

			/*Luna*/
			glPushMatrix();
				glRotatef(angulo * 3, 0, 0, 1);
				glTranslatef(-1.6, 2, .82);
				glColor3f(0.8, 0.5, 0.5);
				glutSolidSphere(.2, 16, 16);
			glPopMatrix();

			/*Luna*/
			glPushMatrix();
				glRotatef(-angulo * 3, 0, 0, 1);
				glTranslatef(-1.5, -1, 1.8);
				glColor3f(0.8, 0.5, 0.5);
				glutSolidSphere(.2, 16, 16);
			glPopMatrix();

			/*Luna*/
			glPushMatrix();
				glRotatef(-angulo * 3, 0, 0, 1);
				glTranslatef(-1, 2, 2);
				glColor3f(0.8, 0.5, 0.5);
				glutSolidSphere(.2, 16, 16);
			glPopMatrix();

		glPopMatrix();

		/*Neptune*/
		glPushMatrix();
			glTranslatef(0, 0, -23.5);
			glRotatef(-angulo, 0, 1, 0);
			glColor3f(0, 0, .5);
			glutSolidSphere(1.1, 16, 16);
		glPopMatrix();


		

	glPopMatrix();

	glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
	case 'q':
		exit(0);
		break;
	}

	glutPostRedisplay();
}

static void idle(void)
{
	glutPostRedisplay();
}

const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("GLUT Shapes");

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);

	glClearColor(1, 1, 1, 1);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	glutMainLoop();

	return EXIT_SUCCESS;
}