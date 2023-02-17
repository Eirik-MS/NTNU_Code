#include "std_lib_facilities.h"
#include "utilities.h"


int incrementByValueNumTimes(int startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++){
           startValue += increment;
       }

    return startValue;
}

void incrementByValueNumTimesRef(int &startValue, int &increment, int &numTimes)
{
    for (int i = 0; i < numTimes; i++){
           startValue += increment;
       }
}

void swapNumbers(int& A, int& B) 
{
    //JA fordi da kan funksjonen gjøre jobben sin uten å måtte returnere noe
    int C = A;
    A = B;
    B = C;
}

void printStudent(struct Student info)
{
    cout<<info.name<<" studerer "<<info.studyProgram<<" og er "<<info.age<<" år gammel.\n";
};

bool isInProgram(struct Student info, string studie)
{
    if(info.studyProgram == studie){
        return true;
    }
    return false;
}


string randomizeString(int len, char lower, char upper)
{
    int range = upper+1-lower;
    std::string result = "";
    std::random_device rd;
    std::default_random_engine generator(rd());
    
    for(int i=0; i < len; i++){
        std::uniform_real_distribution<double> distribution(0.0,range-1);
        int number = distribution(generator);
        char r = 'A' + number;
        result += r;
    }
    return result;
}

string readInputToString(int n, char lower, char upper)
{
    if (isupper(lower) == false){
        lower = toupper(lower);
    };

    if (isupper(upper) == false){
        upper = toupper(upper);
    };

    string resultat = "";

        cout<<"Skriv en streng som er "<<n<<" lang, og hvor hver bokstav er mellom "<<lower<<" og "<<upper<<"\n";
        cin>>resultat;
        
        if ((resultat.length() == n) && (std::all_of(resultat.begin(), resultat.end(), [](unsigned char c){return std::isalpha(c);})))
        {
            for(int i=0;i<n;++i)
                {
                    char a = resultat[i];
                    if (isupper(a) == false){a = toupper(a);}
                    int aNumber = a;
                    int lowerNumber = lower;
                    int upperNumber = upper;
                    if (aNumber < lowerNumber || a > upperNumber)
                        {
                            break;
                        }
                    //cout<<"a - "<<a<<"; i - "<<i<<"; aNum - "<<aNumber<<"; lNum - "<<lowerNumber<<"; uNum - "<<upperNumber<<"\n";
                }
    }
    return resultat;
}

int countChar(string word, char letter)
{
    int counter = 0;
    for(int i = 0; i < word.length(); ++i)
    {
        if (word[i] == letter)
        {
            counter += 1;
        }
    }
    return counter;
}

int checkCharactersAndPos(string hiddenWord, string guess){
    int riktigePosisjoner = 0;
    for (int i =0; i < hiddenWord.length(); i ++){
        if (hiddenWord[i] == guess[i]){
            riktigePosisjoner += 1;
        }
    }
    return riktigePosisjoner;
}


void playMasterMind(){
    string hiddenWord = randomizeString(4,'A','F');
    cout << "Hidden word: "<<hiddenWord<<"\n";
    bool correctGuess = false;
    cout << "Du spiller naa Master Mind!\n";
    int maxForsok = 6;
    for (int forsok = 0; forsok <= maxForsok; forsok++)
    {
        cout << "***\nForsok nr. "<<forsok<<" / "<<maxForsok<<"\n***\n";
        cout << "Gjor ett gjett.\n";
        string guess = readInputToString(4,'A','F');
        int riktigeBokstaver = 0;
        int riktigePosisjoner = 0;
        
        for (int i =0; i < 4 ; i ++){
            riktigeBokstaver += countChar(hiddenWord, guess[i]);
        }
        riktigePosisjoner += checkCharactersAndPos(hiddenWord, guess);

        if (riktigePosisjoner == 4){
            cout << "Gratulerer! Du har gjettet riktig!\n";
            correctGuess = true;
            break;
        }
        else if (forsok == maxForsok){
            cout << "Du har brukt opp alle forsøkene dine. Du har tapt.\n";
            break;
        }
        else
            cout << "Du har "<<riktigeBokstaver<<" riktige bokstaver og "<<riktigePosisjoner<<" riktige posisjoner.\n";
        
    }
}
