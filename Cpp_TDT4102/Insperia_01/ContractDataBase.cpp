#include "ContractDataBase.h"

InsuranceContract ContractDataBase::getContract(int id)
{
    // BEGIN: 1b

    for (InsuranceContract con : contracts)
    {
        if (con.getId() == id)
        {
            return con;
        }
    }

    // END: 1b

    // Returning an empty contract if no contract with the given id is found.
    return InsuranceContract{};
}

int ContractDataBase::numberOfInsuranceType(InsuranceType type)
{
    // BEGIN: 1c

    int count = 0;
    for (InsuranceContract con : contracts)
    {
        if (con.getInsuranceType() == type)
        {
            count++;
        }
    }
    return count;
    // END: 1c
}

int ContractDataBase::addContract(string holderName, InsuranceType insType, int value)
{
    // BEGIN: 1d 

    // find highest id
    int highestId = 0;
    for (InsuranceContract con : contracts){
        if (con.getId() > highestId){
            highestId = con.getId();
        }
    }

    // add new contract
    InsuranceContract newContract{holderName, insType, value, highestId + 1};
    contracts.push_back(newContract);

    return highestId + 1;

    // END: 1d
}

void ContractDataBase::saveContracts(string filename)
{
    // BEGIN: 1e

    std::filesystem::path file{filename};
    std::ofstream outputStream{file};

    for (InsuranceContract con : contracts)
    {
        outputStream << con.getHolder() << "," << insuranceTypeToString(con.getInsuranceType()) << "," << con.getValue() << "," << con.getId() << "," << con.getInsuranceText() << endl;
    }

    // END: 1e
}

void ContractDataBase::loadContracts(string filename)
{
    ifstream inFile{filename};
    if (!inFile)
    {
        error("Couldn't open file: ", filename);
    }

    string line;
    while (getline(inFile, line))
    {
        stringstream ss{line};
        char seperator;

        string holderName;
        getline(ss, holderName, ',');

        string insType;
        getline(ss, insType, ',');

        int value;
        ss >> value;
        ss >> seperator;

        int id;
        ss >> id;
        ss >> seperator;

        string insuranceText;
        getline(ss, insuranceText, ',');

        contracts.push_back({holderName, stringToInsuranceType.at(insType), value, id, insuranceText});
    }
}
