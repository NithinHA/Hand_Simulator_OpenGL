#include<stdlib.h>
#include <GL/glut.h>
#include <algorithm>

using namespace std;

GLfloat cameraDistance = 12, cameraAngle = 0;

int arm_angles[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
enum { Palm_y, Palm_z, Last_b, Last_m, Last_t, Ring_b, Ring_m, Ring_t, Middle_b, Middle_m, Middle_t, Index_b, Index_m, Index_t, Thumb_b, Thumb_t };



void change_angle(int angle, int delta, int minimum = 0, int maximum = 180) {

	int tempAngle = (arm_angles[angle] + delta) % 360;
	if (tempAngle >= minimum && tempAngle <= maximum)
		arm_angles[angle] = tempAngle;
	
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	GLfloat x = cameraDistance * sin(cameraAngle);
	GLfloat z = cameraDistance * cos(cameraAngle);
	gluLookAt(x, 0.0, z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	{
		glPushMatrix();

		glRotatef((GLfloat)arm_angles[Palm_y], 0., 1., 0.);			//For palm rotation
		glRotatef((GLfloat)arm_angles[Palm_z], 0., 0., 1.);			//For palm rotation
		glTranslatef(1., 0., 0.);
		
		/////PALM/////
		glPushMatrix();
		glScalef(4.0, 0.4, 4.0);
		glColor3f(1.0f, 1.0f, 1.0f);
		
		//glutWireIcosahedron();
		glutWireCube(1.);
		glPopMatrix();
		
		{/////LAST FINGER/////
			glPushMatrix();

			glTranslatef(2., 0., 1.5);
			glRotatef((GLfloat)arm_angles[Last_b], 0., 0., 1.);				//rotate bottom part of last finger
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			glScalef(2.0, 0.4, 1.0);
			glColor3f(1, 1, 0);
			glutWireCube(1.);       
			glPopMatrix();

			glTranslatef(1., 0., 0.);
			glRotatef((GLfloat)arm_angles[Last_m], 0., 0., 1.);				//rotate middle part of last finger
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			glScalef(2.0, 0.4, 1.0);
			glColor3f(1, 0.75, 0);
			glutWireCube(1.);
			glPopMatrix();

			glTranslatef(0.85, 0., 0.);
			glRotatef((GLfloat)arm_angles[Last_t], 0., 0., 1.);				//rotate top part of last finger
			glTranslatef(0.85, 0., 0.);

			glPushMatrix();
			glScalef(1.5, 0.4, 1.0);
			glColor3f(1, 0.75, 0.2);
			glutWireCube(1.);
			glPopMatrix();

			glPopMatrix();
		}

		{/////RING FINGER/////
			glPushMatrix();

			glTranslatef(2., 0., 0.5);
			glRotatef((GLfloat)arm_angles[Ring_b], 0., 0., 1.);				//rotate bottom part of ring finger
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			glScalef(2.0, 0.4, 1.0);
			glColor3f(0, 1, 1);
			glutWireCube(1.);  
			glPopMatrix();

			glTranslatef(1., 0., 0.);
			glRotatef((GLfloat)arm_angles[Ring_m], 0., 0., 1.);				//rotate middle part of ring finger
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			glScalef(2.0, 0.4, 1.0);
			glColor3f(0, 1, 0.75);
			glutWireCube(1.);
			glPopMatrix();

			glTranslatef(0.85, 0., 0.);
			glRotatef((GLfloat)arm_angles[Ring_t], 0., 0., 1.);				//rotate top part of ring finger
			glTranslatef(0.85, 0., 0.);

			glPushMatrix();
			glScalef(1.5, 0.4, 1.0);
			glColor3f(0.2, 1, 0.75);
			glutWireCube(1.);
			glPopMatrix();

			glPopMatrix();
		}

		{/////MIDDLE FINGER/////
			glPushMatrix();

			glTranslatef(2., 0., -0.5);
			glRotatef((GLfloat)arm_angles[Middle_b], 0., 0., 1.);			//rotate bottom part of middle finger
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			glScalef(2.0, 0.4, 1.0);
			glColor3f(1, 0, 1);
			glutWireCube(1.);
			glPopMatrix();

			glTranslatef(1., 0., 0.);
			glRotatef((GLfloat)arm_angles[Middle_m], 0., 0., 1.);			//rotate middle part of middle finger
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			glScalef(2.0, 0.4, 1.0);
			glColor3f(0.75, 0, 1);
			glutWireCube(1.);
			glPopMatrix();

			glTranslatef(0.85, 0., 0.);
			glRotatef((GLfloat)arm_angles[Middle_t], 0., 0., 1.);			//rotate top part of middle finger
			glTranslatef(0.85, 0., 0.);

			glPushMatrix();
			glScalef(1.5, 0.4, 1.0);
			glColor3f(0.75, 0.2, 1);
			glutWireCube(1.);
			glPopMatrix();

			glPopMatrix();
		}

		{/////INDEX FINGER/////
			glPushMatrix();

			glTranslatef(2., 0., -1.5);
			glRotatef((GLfloat)arm_angles[Index_b], 0., 0., 1.);			//rotate bottom part of index finger
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			glScalef(2.0, 0.4, 1.0);
			glColor3f(0.2, 0 ,1);
			glutWireCube(1.);
			glPopMatrix();

			glTranslatef(1., 0., 0.);
			glRotatef((GLfloat)arm_angles[Index_m], 0., 0., 1.);			//rotate middle part of index finger
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			glScalef(2.0, 0.4, 1.0);
			glColor3f(0, 0.2, 1);
			glutWireCube(1.);
			glPopMatrix();

			glTranslatef(0.85, 0., 0.);
			glRotatef((GLfloat)arm_angles[Index_t], 0., 0., 1.);			//rotate top part of index finger
			glTranslatef(0.85, 0., 0.);

			glPushMatrix();
			glScalef(1.5, 0.4, 1.0);
			glColor3f(0.2, 0.2, 1);
			glutWireCube(1.);
			glPopMatrix();

			glPopMatrix();
		}

		{/////THUMB/////
			glPushMatrix();

			glTranslatef(1, 0., -2.);
			glRotatef(90., 0., 1., 0.);
			glRotatef((GLfloat)arm_angles[Thumb_b], 0., 0., 1.);			//rotate bottom part of thumb
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			glScalef(2.0, 0.4, 1.0);
			glColor3f(1, 0, 0.2);
			glutWireCube(1.);
			glPopMatrix();

			glTranslatef(1., 0., 0.);
			glRotatef((GLfloat)arm_angles[Thumb_t], 0., 0., 1.);			//rotate top part of thumb
			glTranslatef(1., 0., 0.);

			glPushMatrix();
			glScalef(2.0, 0.4, 1.0);
			glColor3f(1, 0.2, 0);
			glutWireCube(1.);
			glPopMatrix();

			glPopMatrix();
		}

		glPopMatrix();
	}

	glutSwapBuffers();
}

void reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 300.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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

	}

	glutPostRedisplay();
}




int main(int argc, char * argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Hand Simulation");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);
	//glutMenuFunction


	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	glutMainLoop();
}