#include "NTNU_co.h"

Car::Car(int freeSeat): freeSeats{freeSeat}{};

bool Car::hasFreeSeats()const {
	if (freeSeats>0){
		return true;
	}else{
		return false;
	}
}

void Car::reserveFreeSeat(){
	if (hasFreeSeats()){
		freeSeats = freeSeats-1;
	}
}

