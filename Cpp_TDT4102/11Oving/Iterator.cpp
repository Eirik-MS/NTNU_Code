#include "oppgave_en.h"

void replace(std::vector<std::string>& vec, std::string old, std::string replacement){
	for (int i = 0; i<vec.size(); i++){
		if (vec.at(i) == old){
			vec.at(i) = replacement;
		}
	}
}
void vec_print(std::vector<std::string>& vec){

	for (auto elem : vec){
		std::cout << elem << std::endl;
	}

	for (auto elem = vec.rbegin(); elem != vec.rend(); ++elem){
        std::cout << *elem << std::endl;
	}
}
void vec_print(std::set<std::string>& vec){

	for (auto elem : vec){
		std::cout << elem << std::endl;
	}

	for (auto elem = vec.rbegin(); elem != vec.rend(); ++elem){
        std::cout << *elem << std::endl;
	}
}