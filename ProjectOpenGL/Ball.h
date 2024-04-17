#pragma once
#include <gl/GL.h>



int boxMin = 0, boxMax = 8;

class Ball
{
	GLfloat* color;
	double maximumHeight;
	int speed;
public:
	double radius;
    std::vector<double> position;
    std::vector<int> directions;
public:
	Ball(double r, GLfloat* c, double h, double x, double z, std::vector<int> directions) :
		radius(r), color(c), maximumHeight(h), speed(-1) {
        this->directions = directions;
        this->position.push_back(x);
        this->position.push_back(h);
        this->position.push_back(z);

    }

	void update(Ball* balls) {
		/*x += direction * 0.05;*/
        for (int i = 0; i < 3; i++) {
            position[i] += directions[i] * 0.05;
        }

        for (int i = 0; i < 3; i++) {
            if (position[i] > boxMax - radius) {
                position[i] = boxMax - radius;
                directions[i] *= -1;
            }
            if (position[i] < boxMin + radius) {
                position[i] = boxMin + radius;
                directions[i] *= -1;
            }
        }

		//z += direction * 0.05;
		
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
		glTranslated(position[0], position[1], position[2]);
		glutSolidSphere(radius, 30, 30);
		glPopMatrix();
	}
};