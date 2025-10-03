#ifndef CAR_H
#define CAR_H

#include <cmath>
#include <string>

class Car {
public:
    Car();
    Car(double initialX, double initialY, double initialSpeed, 
        double initialAcceleration, double initialAngle);
    Car(const Car& other);
    ~Car();

    double getXPosition() const;
    double getYPosition() const;
    double getSpeed() const;
    double getAcceleration() const;
    double getAngle() const;

    void setSpeed(double newSpeed);
    void setAcceleration(double newAcceleration);
    void setAngle(double newAngle);

    void updatePosition(double deltaTime);
    std::string toString() const;

private:
    double xPosition;
    double yPosition;
    double speed;
    double acceleration;
    double angle;

    bool isValidSpeed(double speed) const;
    bool isValidAcceleration(double acceleration) const;
    bool isValidAngle(double angle) const;
};

#endif 