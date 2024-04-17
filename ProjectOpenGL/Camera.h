#include <cmath>
#define M_PI 3.14159265358979323846
#include <xmemory>
class Camera {
    double theta;       // Unghiul pentru poziția pe orizontală
    double phi;         // Unghiul pentru poziția pe verticală
    double radius;      // Distanța față de centrul cubului
    double dTheta;      // Increment pentru unghiul theta
    double dPhi;        // Increment pentru unghiul phi
public:
    Camera() : theta(0), phi(0), radius(30), dTheta(0.2), dPhi(0.1) {}

    double getX() {
        return radius * sin(theta) * cos(phi);
    }

    double getY() {
        return radius * sin(phi);
    }

    double getZ() {
        return radius * cos(theta) * cos(phi);
    }

    void moveRight() {
        theta += dTheta;
    }

    void moveLeft() {
        theta -= dTheta;
    }

    void moveUp() {
        phi += dPhi;
        if (phi >= M_PI) phi = M_PI - 0.01; // Limităm unghiul phi să nu degenereze
    }

    void moveDown() {
        phi -= dPhi;
        if (phi <= 0) phi = 0.01; // Limităm unghiul phi să nu degenereze
    }
};
