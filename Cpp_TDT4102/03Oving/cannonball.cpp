
#include "cannonball.h"

double acclY() {
    return -9.81;
}

double velY(double initVelocityY, double time) {
    return initVelocityY + acclY() * time;
}

double posX(double initVelocity, double time, double initPosition) {
    return initPosition + initVelocity * time;
}

double posY(double initVelocity, double time, double initPosition) {
    return initPosition + initVelocity * time + (acclY()*time*time)/2;
}

void printTime(double time) {
    int hours = time / 3600;
    int minutes = (time - hours * 3600) / 60;
    int seconds = time - hours * 3600 - minutes * 60;
    cout << hours << ":" << minutes << ":" << seconds << endl;
}

double flightTime(double initVelocityY) {
    return -2 * initVelocityY / acclY();
}

double getUserInputTheta() {
    double theta;
    cout << "Enter the launch angle (in degrees): ";
    cin >> theta;
    return theta;
}

double getUserInputAbsVelocity() {
    double absVelocity;
    cout << "Enter the initial velocity (in meters/sec): ";
    cin >> absVelocity;
    return absVelocity;
}

double degToRad(double deg) {
    return deg * M_PI / 180;
}

double getVelocityX(double theta, double absVelocity) {
    return absVelocity * cos(degToRad(theta));
}

double getVelocityY(double theta, double absVelocity) {
    return absVelocity * sin(degToRad(theta));
}

vector <double> getVelocityVector(double theta, double absVelocity) {
    vector <double> velocityVector;
    velocityVector.push_back(getVelocityX(theta, absVelocity));
    velocityVector.push_back(getVelocityY(theta, absVelocity));
    return velocityVector;
}

double getDistanceTraveled(double velocityX, double velocityY) {
    return (velocityX * flightTime(velocityY)) / 2;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}