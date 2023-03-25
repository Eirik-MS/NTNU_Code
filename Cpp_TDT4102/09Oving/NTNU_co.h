#include <string>
#include <memory>

class Car{
	private:
		int freeSeats;
		
	public:
		bool hasFreeSeats() const;
		void reserveFreeSeat();
		Car(int freeSeat);

};

class Person{
	private:
		std::string name;
		std::string email;
		std::unique_ptr<Car> bil; 
	public: 
		std::string getName();
		std::string getEmail();
		
		void setName();
		void setEmail();

		bool hasFreeSeats() const;
};