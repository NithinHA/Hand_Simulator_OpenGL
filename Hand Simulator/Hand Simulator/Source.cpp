#include<stdlib.h>
#include <GL/glut.h>
#include <algorithm>

using namespace std;

GLfloat cameraDistance = 12, cameraAngle = 0;

int arm_angles[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
enum { Palm_y, Palm_z, Last_b, Last_m, Last_t, Ring_b, Ring_m, Ring_t, Middle_b, Middle_m, Middle_t, Index_b, Index_m, Index_t, Thumb_b, Thumb_t };

int handShape = 0;
int scene = 0;


void change_angle(int angle, int delta, int minimum = 0, int maximum = 180) {
	//arm_angles[angle] = (arm_angles[angle] + delta) % 360;
	int tempAngle = (arm_angles[angle] + delta) % 360;
	if (tempAngle >= minimum && tempAngle <= maximum)
		arm_angles[angle] = tempAngle;

	//arm_angles[angle] = max(arm_angles[angle], minimum);
	//arm_angles[angle] = min(arm_angles[angle], maximum);
}


void createSphere() {
	glutWireSphere(0.5f, 10, 10);
}

void drawstring(float x, float y, float z, const char *s) {
	unsigned int i;
	glRasterPos2f(x, y);

	for (i = 0; i < strlen(s); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
}

void FrontPage() {
	int temp = 10;
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0, 0.0, 20, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
//	glColor3f(1, 0, 0);
//	glBegin(GL_POLYGON);
//	glVertex2f(0, 0);
//	glVertex2f(0, temp);
//	glVertex2f(temp, temp);
//	glVertex2f(temp, 0);
//	glEnd();
//
//	/*glColor3f(0, 0, 1);
//	drawstring(20.0, 90.0, 0.0, "NAME OF THE COLLEGE ");
//	glColor3f(0.7, 0, 1);
//	drawstring(21, 82, 0.0, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
//	glColor3f(1, 0.5, 0);
//	drawstring(38, 70, 0.0, "A MINI PROJECT ON");
//	glColor3f(1, 0, 0);
//	drawstring(40, 60, 0.0, "PROJECT TITLE");
//	glColor3f(1, 0.5, 0);
//	drawstring(20, 50, 0.0, "BY:");
//	glColor3f(0.5, 0, 0.5);
//	drawstring(10, 40, 0.0, "NAME FIRST           (USN)");
//	drawstring(10, 34, 0.0, "NAME SECOND         (USN)");
//	glColor3f(1, 0.5, 0);
//	drawstring(68, 50, 0.0, "GUIDES:");
//	glColor3f(0.5, 0.2, 0.2);
//	drawstring(63, 40, 0.0, "GUIDE NAME FIRST");
//	drawstring(63, 34, 0.0, "GUIDE NAME SECOND");
//	glColor3f(1, 0.1, 1);
//	drawstring(32, 10, 0.0, "PRESS ENTER TO START");
//	glFlush();*/
//
//	glutSwapBuffers();
//
}

void MainScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	GLfloat x = cameraDistance * sin(cameraAngle);
	GLfloat z = cameraDistance * cos(cameraAngle);
	gluLookAt(x, 0.0, z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	{
		glPushMatrix();

		glRotatef((GLfloat)arm_angles[Palm_y], 0., 1., 0.);						//For palm rotation
		glRotatef((GLfloat)arm_angles[Palm_z], 0., 0., 1.);						//For palm rotation
		glTranslatef(1., 0., 0.);

		/////PALM/////
		glPushMatrix();
		if (handShape == 1)											/////SHAPE CHECK/////
			glScalef(4, 1, 4);
		else
			glScalef(4.0, 0.4, 4.0);
		glColor3f(1.0f, 1.0f, 1.0f);

		if (handShape == 1)											/////SHAPE CHECK/////
			glutWireSphere(0.5f, 20, 6);
		else
			glutWireCube(1.);
		glPopMatrix();

		{/////LAST FINGER/////
			glPushMatrix();
			if (handShape == 1)										/////SHAPE CHECK/////
				glTranslatef(1.5, 0., 1.5);
			else
				glTranslatef(2., 0., 1.5);
			glRotatef((GLfloat)arm_angles[Last_b], 0., 0., 1.);					//rotate bottom part of last finger
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			if (handShape == 1)										/////SHAPE CHECK/////
				glScalef(2, 1, 1);
			else
				glScalef(2.0, 0.4, 1.0);
			glColor3f(1, 1, 0);
			if (handShape == 1)										/////SHAPE CHECK/////
				createSphere();
			else
				glutWireCube(1.);
			glPopMatrix();

			glTranslatef(1., 0., 0.);
			glRotatef((GLfloat)arm_angles[Last_m], 0., 0., 1.);					//rotate middle part of last finger
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			if (handShape == 1)										/////SHAPE CHECK/////
				glScalef(2, 1, 1);
			else
				glScalef(2.0, 0.4, 1.0);
			glColor3f(1, 0.75, 0);
			if (handShape == 1)										/////SHAPE CHECK/////	
				createSphere();
			else
				glutWireCube(1.);
			glPopMatrix();

			glTranslatef(0.85, 0., 0.);
			glRotatef((GLfloat)arm_angles[Last_t], 0., 0., 1.);					//rotate top part of last finger
			glTranslatef(0.85, 0., 0.);

			glPushMatrix();
			if (handShape == 1)										/////SHAPE CHECK/////
				glScalef(1.5, 1, 1);
			else
				glScalef(1.5, 0.4, 1.0);
			glColor3f(1, 0.75, 0.2);
			if (handShape == 1)										/////SHAPE CHECK/////
				createSphere();
			else
				glutWireCube(1.);
			glPopMatrix();

			glPopMatrix();
		}

		{/////RING FINGER/////
			glPushMatrix();

			glTranslatef(2., 0., 0.5);
			glRotatef((GLfloat)arm_angles[Ring_b], 0., 0., 1.);					//rotate bottom part of ring finger
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			if (handShape == 1)										/////SHAPE CHECK/////
				glScalef(2, 1, 1);
			else
				glScalef(2.0, 0.4, 1.0);
			glColor3f(0, 1, 1);
			if (handShape == 1)										/////SHAPE CHECK/////
				createSphere();
			else
				glutWireCube(1.);
			glPopMatrix();

			glTranslatef(1., 0., 0.);
			glRotatef((GLfloat)arm_angles[Ring_m], 0., 0., 1.);					//rotate middle part of ring finger
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			if (handShape == 1)										/////SHAPE CHECK/////
				glScalef(2, 1, 1);
			else
				glScalef(2.0, 0.4, 1.0);
			glColor3f(0, 1, 0.75);
			if (handShape == 1)										/////SHAPE CHECK/////
				createSphere();
			else
				glutWireCube(1.);
			glPopMatrix();

			glTranslatef(0.85, 0., 0.);
			glRotatef((GLfloat)arm_angles[Ring_t], 0., 0., 1.);					//rotate top part of ring finger
			glTranslatef(0.85, 0., 0.);

			glPushMatrix();
			if (handShape == 1)										/////SHAPE CHECK/////
				glScalef(1.5, 1, 1);
			else
				glScalef(1.5, 0.4, 1.0);
			glColor3f(0.2, 1, 0.75);
			if (handShape == 1)										/////SHAPE CHECK/////
				createSphere();
			else
				glutWireCube(1.);
			glPopMatrix();

			glPopMatrix();
		}

		{/////MIDDLE FINGER/////
			glPushMatrix();

			glTranslatef(2., 0., -0.5);
			glRotatef((GLfloat)arm_angles[Middle_b], 0., 0., 1.);				//rotate bottom part of middle finger
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			if (handShape == 1)										/////SHAPE CHECK/////
				glScalef(2, 1, 1);
			else
				glScalef(2.0, 0.4, 1.0);
			glColor3f(1, 0, 1);
			if (handShape == 1)										/////SHAPE CHECK/////
				createSphere();
			else
				glutWireCube(1.);
			glPopMatrix();

			glTranslatef(1., 0., 0.);
			glRotatef((GLfloat)arm_angles[Middle_m], 0., 0., 1.);				//rotate middle part of middle finger
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			if (handShape == 1)										/////SHAPE CHECK/////
				glScalef(2, 1, 1);
			else
				glScalef(2.0, 0.4, 1.0);
			glColor3f(0.75, 0, 1);
			if (handShape == 1)										/////SHAPE CHECK/////
				createSphere();
			else
				glutWireCube(1.);
			glPopMatrix();

			glTranslatef(0.85, 0., 0.);
			glRotatef((GLfloat)arm_angles[Middle_t], 0., 0., 1.);				//rotate top part of middle finger
			glTranslatef(0.85, 0., 0.);

			glPushMatrix();
			if (handShape == 1)										/////SHAPE CHECK/////
				glScalef(1.5, 1, 1);
			else
				glScalef(1.5, 0.4, 1.0);
			glColor3f(0.75, 0.2, 1);
			if (handShape == 1)										/////SHAPE CHECK/////
				createSphere();
			else
				glutWireCube(1.);
			glPopMatrix();

			glPopMatrix();
		}

		{/////INDEX FINGER/////
			glPushMatrix();

			if (handShape == 1)										/////SHAPE CHECK/////
				glTranslatef(1.5, 0., -1.5);
			else
				glTranslatef(2., 0., -1.5);
			glRotatef((GLfloat)arm_angles[Index_b], 0., 0., 1.);				//rotate bottom part of index finger
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			if (handShape == 1)										/////SHAPE CHECK/////
				glScalef(2, 1, 1);
			else
				glScalef(2.0, 0.4, 1.0);
			glColor3f(0.2, 0, 1);
			if (handShape == 1)										/////SHAPE CHECK/////
				createSphere();
			else
				glutWireCube(1.);
			glPopMatrix();

			glTranslatef(1., 0., 0.);
			glRotatef((GLfloat)arm_angles[Index_m], 0., 0., 1.);				//rotate middle part of index finger
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			if (handShape == 1)										/////SHAPE CHECK/////
				glScalef(2, 1, 1);
			else
				glScalef(2.0, 0.4, 1.0);
			glColor3f(0, 0.2, 1);
			if (handShape == 1)										/////SHAPE CHECK/////
				createSphere();
			else
				glutWireCube(1.);
			glPopMatrix();

			glTranslatef(0.85, 0., 0.);
			glRotatef((GLfloat)arm_angles[Index_t], 0., 0., 1.);				//rotate top part of index finger
			glTranslatef(0.85, 0., 0.);

			glPushMatrix();
			if (handShape == 1)										/////SHAPE CHECK/////
				glScalef(1.5, 1, 1);
			else
				glScalef(1.5, 0.4, 1.0);
			glColor3f(0.2, 0.2, 1);
			if (handShape == 1)										/////SHAPE CHECK/////
				createSphere();
			else
				glutWireCube(1.);
			glPopMatrix();

			glPopMatrix();
		}

		{/////THUMB/////
			glPushMatrix();

			if (handShape == 1) {									/////SHAPE CHECK/////
				glTranslatef(0, 0, -1.8);
				glRotatef(60, 0, 1, 0);
				glRotatef((GLfloat)arm_angles[Thumb_b], 0.5, 0., 1.);				//rotate bottom part of thumb
			}
			else {
				glTranslatef(1, 0., -2.);
				glRotatef(90., 0., 1., 0.);
				glRotatef((GLfloat)arm_angles[Thumb_b], 0., 0., 1.);
			}

			glTranslatef(1., 0., 0.);

			glPushMatrix();
			if (handShape == 1)										/////SHAPE CHECK/////
				glScalef(1.5, 1, 1);
			else
				glScalef(2.0, 0.4, 1.0);
			glColor3f(1, 0, 0.2);
			if (handShape == 1)										/////SHAPE CHECK/////
				createSphere();
			else
				glutWireCube(1.);
			glPopMatrix();
			if (handShape == 1) {
				glTranslatef(0.5, 0., 0.);
				glRotatef((GLfloat)arm_angles[Thumb_t], 0.5, 0., 1.);				//rotate top part of thumb
			}
			else {
				glTranslatef(1., 0., 0.);
				glRotatef((GLfloat)arm_angles[Thumb_t], 0., 0., 1.);				//rotate top part of thumb
			}
			glTranslatef(1., 0., 0.);
			glPushMatrix();
			if (handShape == 1)										/////SHAPE CHECK/////
				glScalef(1.5, 1, 1);
			else
				glScalef(2.0, 0.4, 1.0);
			glColor3f(1, 0.2, 0);
			if (handShape == 1)										/////SHAPE CHECK/////
				createSphere();
			else
				glutWireCube(1.);
			glPopMatrix();

			glPopMatrix();
		}

		glPopMatrix();
	}

	glutSwapBuffers();
}

//void init()
//{
//	glClearColor(1.0, 0.5, 0.0, 0.0);
//	//glClearColor(0.3, 0.0, 0.3, 0.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0, 10, 0, 10);
//}

void reshape(GLsizei w, GLsizei h) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 300.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display() {
	if (scene == 0) {

		FrontPage();
	}
	else {
		MainScene();
	}
}


void specialKeys(int key, int x, int y) {
	GLfloat distanceDelta = 1.0, angleDelta = 5 * 3.14159 / 180.0;
	if (key == GLUT_KEY_UP) {
		cameraDistance -= distanceDelta;
		cameraDistance = max((GLfloat)2.0, cameraDistance);
	}
	if (key == GLUT_KEY_DOWN) {
		cameraDistance += distanceDelta;
	}
	if (key == GLUT_KEY_LEFT) {
		cameraAngle -= angleDelta;
	}
	if (key == GLUT_KEY_RIGHT) {
		cameraAngle += angleDelta;
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	int delta = 5;

	switch (key) {

		/////PALM/////
	case 'l':
		change_angle(Palm_y, delta, -180, 0);
		break;
	case 'j':
		change_angle(Palm_y, -delta, -180, 0);
		break;
	case 'i':
		change_angle(Palm_z, delta, -90, 90);
		break;
	case 'k':
		change_angle(Palm_z, -delta, -90, 90);
		break;

		/////LAST FINGER/////
	case 'z':
		change_angle(Last_b, delta, 0, 90);
		break;
	case 'a':
		change_angle(Last_m, delta, 0, 100);
		break;
	case 'q':
		change_angle(Last_t, delta, 0, 80);
		break;
	case '1':
		arm_angles[Last_b] = 0;
		arm_angles[Last_m] = 0;
		arm_angles[Last_t] = 0;
		break;

		/////RING FINGER/////
	case 'x':
		change_angle(Ring_b, delta, 0, 90);
		break;
	case 's':
		change_angle(Ring_m, delta, 0, 100);
		break;
	case 'w':
		change_angle(Ring_t, delta, 0, 80);
		break;
	case '2':
		arm_angles[Ring_b] = 0;
		arm_angles[Ring_m] = 0;
		arm_angles[Ring_t] = 0;
		break;

		/////MIDDLE FINGER/////
	case 'c':
		change_angle(Middle_b, delta, 0, 90);
		break;
	case 'd':
		change_angle(Middle_m, delta, 0, 100);
		break;
	case 'e':
		change_angle(Middle_t, delta, 0, 80);
		break;
	case '3':
		arm_angles[Middle_b] = 0;
		arm_angles[Middle_m] = 0;
		arm_angles[Middle_t] = 0;
		break;

		/////INDEX FINGER/////
	case 'v':
		change_angle(Index_b, delta, 0, 90);
		break;
	case 'f':
		change_angle(Index_m, delta, 0, 100);
		break;
	case 'r':
		change_angle(Index_t, delta, 0, 80);
		break;
	case '4':
		arm_angles[Index_b] = 0;
		arm_angles[Index_m] = 0;
		arm_angles[Index_t] = 0;
		break;

		/////THUMB/////
	case 'b':
		change_angle(Thumb_b, delta, 0, 90);
		break;
	case 'g':
		change_angle(Thumb_t, delta, 0, 100);
		break;
	case '5':
		arm_angles[Thumb_b] = 0;
		arm_angles[Thumb_t] = 0;
		break;

		//////////////////Change Scene//////////////////
	case 'm':
		scene = 1;
	}

	glutPostRedisplay();
}



void Menu(int value) {
	switch (value) {
	case 1:
		handShape = 0;
		break;
	case 2:
		handShape = 1;
		break;

	case 3:
		exit(0);
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char * argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(900, 900);
	glutCreateWindow("Hand Simulation");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);

	//Menu function

	int sub1 = glutCreateMenu(Menu);
	glutAddMenuEntry("Cuboidal", 1);
	glutAddMenuEntry("Spherical", 2);
	glutCreateMenu(Menu);
	glutAddSubMenu("Shape", sub1);

	glutAddMenuEntry("Exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	////

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glutMainLoop();
}