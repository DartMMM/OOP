#include "Car.h"
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

Car::Car() : xPosition(0.0), yPosition(0.0), speed(0.0), 
             acceleration(0.0), angle(0.0) {
}

Car::Car(double initialX, double initialY, double initialSpeed, 
         double initialAcceleration, double initialAngle) {
    if (isValidSpeed(initialSpeed)) {
        speed = initialSpeed;
    } else {
        speed = 0.0;
    }
    
    if (isValidAcceleration(initialAcceleration)) {
        acceleration = initialAcceleration;
    } else {
        acceleration = 0.0;
    }
    
    if (isValidAngle(initialAngle)) {
        angle = initialAngle;
    } else {
        angle = 0.0;
    }
    
    xPosition = initialX;
    yPosition = initialY;
}

Car::Car(const Car& other) : xPosition(other.xPosition), yPosition(other.yPosition),
                            speed(other.speed), acceleration(other.acceleration),
                            angle(other.angle) {
}

Car::~Car() {
}

double Car::getXPosition() const {
    return xPosition;
}

double Car::getYPosition() const {
    return yPosition;
}

double Car::getSpeed() const {
    return speed;
}

double Car::getAcceleration() const {
    return acceleration;
}

double Car::getAngle() const {
    return angle;
}

void Car::setSpeed(double newSpeed) {
    if (isValidSpeed(newSpeed)) {
        speed = newSpeed;
    }
}

void Car::setAcceleration(double newAcceleration) {
    if (isValidAcceleration(newAcceleration)) {
        acceleration = newAcceleration;
    }
}

void Car::setAngle(double newAngle) {
    if (isValidAngle(newAngle)) {
        angle = newAngle;
    }
}

void Car::updatePosition(double deltaTime) {
    double initialSpeed = speed;
    speed += acceleration * deltaTime;
    
    if (speed < 0) {
        speed = 0;
    }
    
    double angleRadians = angle * M_PI / 180.0;
    double displacement = (initialSpeed + speed) / 2.0 * deltaTime;
    
    xPosition += displacement * cos(angleRadians);
    yPosition += displacement * sin(angleRadians);
}

string Car::toString() const {
    ostringstream stream;
    stream << fixed << setprecision(2);
    stream << "Car [Position: (" << xPosition << ", " << yPosition 
           << "), Speed: " << speed << " m/s, Acceleration: " 
           << acceleration << " m/s^2, Angle: " << angle << "-degree]";
    return stream.str();
}

bool Car::isValidSpeed(double speed) const {
    return speed >= 0.0;
}

bool Car::isValidAcceleration(double acceleration) const {
    return acceleration >= -50.0 && acceleration <= 50.0;
}

bool Car::isValidAngle(double angle) const {
    return angle >= 0.0 && angle < 360.0;
}