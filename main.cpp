#include <iostream>
#include <cassert>
#include <cmath>
#include "Car.h"

using namespace std;

#ifdef RUN_TESTS
void runTests() {
    cout << "=== RUNNING TESTS ===" << endl;
    
    Car car1;
    assert(car1.getXPosition() == 0.0);
    assert(car1.getYPosition() == 0.0);
    assert(car1.getSpeed() == 0.0);
    assert(car1.getAcceleration() == 0.0);
    assert(car1.getAngle() == 0.0);
    
    Car car2(10.0, 20.0, 5.0, 2.0, 45.0);
    assert(car2.getXPosition() == 10.0);
    assert(car2.getYPosition() == 20.0);
    assert(car2.getSpeed() == 5.0);
    assert(car2.getAcceleration() == 2.0);
    assert(car2.getAngle() == 45.0);
    
    Car car3(car2);
    assert(car3.getXPosition() == car2.getXPosition());
    assert(car3.getYPosition() == car2.getYPosition());
    assert(car3.getSpeed() == car2.getSpeed());
    assert(car3.getAcceleration() == car2.getAcceleration());
    assert(car3.getAngle() == car2.getAngle());
    
    Car car4;
    car4.setSpeed(15.0);
    assert(car4.getSpeed() == 15.0);
    
    car4.setAcceleration(3.0);
    assert(car4.getAcceleration() == 3.0);
    
    car4.setAngle(180.0);
    assert(car4.getAngle() == 180.0);
    
    Car car5(0.0, 0.0, 10.0, 0.0, 0.0);
    car5.updatePosition(1.0);
    assert(fabs(car5.getXPosition() - 10.0) < 0.001);
    assert(fabs(car5.getYPosition() - 0.0) < 0.001);
    
    cout << "=== ALL TESTS PASSED! ===" << endl;
}
#endif

int main() {
#ifdef RUN_TESTS
    // ТОЛЬКО тесты
    runTests();
#else
    // ТОЛЬКО симуляция
    cout << "=== RADIO CONTROLLED CAR SIMULATION ===" << endl;
    
    Car car(0.0, 0.0, 0.0, 0.0, 0.0);
    cout << "Initial: " << car.toString() << endl;
    
    car.setSpeed(10.0);
    car.setAngle(45.0);
    car.updatePosition(2.0);
    
    cout << "After movement: " << car.toString() << endl;
    
    car.setAcceleration(1.0);
    car.updatePosition(3.0);
    
    cout << "Final: " << car.toString() << endl;
    cout << "Simulation completed!" << endl;
#endif
    
    return 0;
}