
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
    cout << "Time: ";
    int hours = (int) time / 3600;
    int minutes = (int) (time - hours * 3600) / 60;
    int seconds = (int) time - hours * 3600 - minutes * 60;
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

bool checkIfDistanceToTargetIsCorrect(double dist, double speedx, double speedy) {
    double error = targetPractice(dist, speedx, speedy);
    if (abs(error) < 5) {
        return true;
    } else {
        return false;
    }    
}

void playTargetPractice() {
    int distanceToTarget = randomWithLimits(100, 1000);
    
    
    for (int i = 0; i < 10; i++) {
        cout << "Distance to target: " << distanceToTarget << endl;
        double theta = getUserInputTheta();
        double absVelocity = getUserInputAbsVelocity();
        vector <double> velocityVector = getVelocityVector(theta, absVelocity);
        if ( checkIfDistanceToTargetIsCorrect(distanceToTarget, velocityVector[0], velocityVector[1])) {
            cout << "Hit!, congatulations" << endl;
            printTime(flightTime(velocityVector[1]));
            break;1
        } else {
            cout << "Missed, you were off by " << targetPractice(distanceToTarget, velocityVector[0], velocityVector[1]) << " meters." << endl;
            printTime(flightTime(velocityVector[1]));
        }
        if (i == 9) {
            cout << "You have run out of tries, better luck next time." << endl;
        }

    }
}