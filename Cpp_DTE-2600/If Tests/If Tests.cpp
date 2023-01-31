// If Tests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

std::string whatmovie();


int main()
{
	whatmovie(); 
	return 0;

}

std::string whatmovie() {
	std::string quote;
	std::getline(std::cin, quote);

	if (quote == "Frankly, my dear, I don't give a damn") {
		std::cout << "gone with the wind";
		return "gone with the wind";
	}
	else if(quote == "I'm going to make him an offer he can't refuse") {
		std::cout << "the godfather";
		return "the godfather";
	}
	else if (quote == "And shepherds we shall be") {
		std::cout << "the boondock saints";
		return "the boondock saints";
	}
	else {
		std::cout << "nop !_!";
		return "nop !_!";
	}
}


