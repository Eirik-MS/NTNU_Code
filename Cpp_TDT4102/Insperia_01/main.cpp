#include "std_lib_facilities.h"
#include "InsuranceContract.h"
#include "ContractDataBase.h"
#include "Utilities.h"

//------------------------------------------------------------------------------'

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	ContractDataBase db{};
	db.loadContracts("DataBase.txt");
	InsuranceContract contract{"Jonas Lie", InsuranceType::Car, 1000, 1242, ""};
	//You can test your code under here
	cout << contract << endl;


	return 0;
}

//------------------------------------------------------------------------------
