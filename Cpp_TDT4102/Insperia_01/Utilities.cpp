#include "Utilities.h"

string toGreek(string sentence)
{
    // BEGIN: 2a
    stringstream ss;
    for (char oldChar : sentence){
        if (oldChar == (char)" "){
            ss << oldChar;
        }else{
            char newChar = oldChar + 2;
            ss << newChar;
        }
        
    }
    return ss.str();
    // END: 2a
}

vector<vector<string>> loadSvada()
{
    // BEGIN: 2b

    std::filesystem::path file{"SvadaWords.txt"};
    std::ifstream inputstream{file};
    string line;
    vector<vector<string>> svada;
    vector<string> segment;

    while(getline(inputstream, line)){
        if (line == "||"){
            svada.push_back(segment);
            segment.clear();
        }else{
            segment.push_back(line);
        }
        

    }

    return svada;

    // END: 2b
}

string svadaGenerator(vector<vector<string>> svadaVec)
{
    // BEGIN: 2c1
    
    string setning;
    string vilkaar;

    for (int k = 0; k < 10; k++){
        setning = "";
        for (int i = 0; i<svadaVec.size(); i++){
            int randIndx = rand() % svadaVec.at(i).size()-1;
            setning += svadaVec.at(i).at(randIndx); 
        }
        vilkaar += setning;
    }
    // END: 2c1
}