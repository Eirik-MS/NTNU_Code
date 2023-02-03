#include "std_lib_facilities.h"


double acclY();
double velY(double initVelocityY, double time);
double posX(double initVelocity, double time, double initPosition);
double posY(double initVelocity, double time, double initPosition);
void printTime(double time);
double flightTime(double initVelocityY);
double getUserInputTheta();
double getUserInputAbsVelocity();
double degToRad(double deg);
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);
double getDistanceTraveled(double velocityX, double velocityY);
vector <double> getVelocityVector(double theta, double absVelocity);