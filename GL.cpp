#include<math.h>
#include"glut.h"
#include"size_sim2.h"

int cn = 0;

/*初期化*/
void GL_init() {
	glClearColor(0.0, 0.0, 1.0, 1.0);
}

/*ウィンドウの大きさを調整*/
void resize(int w, int h) {
	glViewport(0, 0, w, h);
	glLoadIdentity();
	glOrtho(-w / 50.0, w / 50.0, -h / 50.0, h / 50.0, -1.0, 1.0);
}

/*容器*/
void container() {
	glBegin(GL_LINE_LOOP);
	glColor3d(1.0, 1.0, 1.0);
	glVertex2d(-6.0, -12.0);
	glVertex2d(6.0, -12.0);
	glVertex2d(6.0, 12.0);
	glVertex2d(-6.0, 12.0);
	glEnd();
}

/*粒子*/
void particle(double x, double y, double r, bool a) {
	double theta = 0.0;
	glBegin(GL_POLYGON);
	if (a == 0) {
		glColor3d(1.0, 1.0, 1.0);
	}
	else {
		glColor3d(0.0, 0.0, 0.0);
	}
	for (int i = 0; i < 5000; i++) {
		theta += 6.2831853072 / 5000.0;
		glVertex2d(x + r * cos(theta), y + r * sin(theta));
	}
	glEnd();
}

/*初期描画*/
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	container();
	glFlush();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '1':
		GL_init();
		display();
		particle_init();
		cn = 0;
		glFlush();
		break;
	case '2':
		GL_init();
		display();
		down(cn);
		cn++;
		glFlush();
		break;
	case '3':
		GL_init();
		display();
		up();
		glFlush();
		break;
	default:
		break;
	}
}