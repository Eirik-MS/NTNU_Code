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
    string result = "";
    std::random_device rd;
    std::default_random_engine generator(rd());
    
    for(int i=0; i < len; i++){
        std::uniform_real_distribution<int> distribution(lower,upper);
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
    bool breaker = false;

    while(true)
    {
        cout<<"Skriv en streng som er "<<n<<" lang, og hvor hver bokstav er mellom "<<lower<<" og "<<upper<<"\n";
        cin>>resultat;
        
        if ((resultat.length() == n) && (std::all_of(resultat.begin(), resultat.end(), [](unsigned char c){return std::isalpha(c);})))
        {
            int iterations = 0;
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
                    iterations += 1;
                    //cout<<"a - "<<a<<"; i - "<<i<<"; aNum - "<<aNumber<<"; lNum - "<<lowerNumber<<"; uNum - "<<upperNumber<<"\n";
                }
            if (iterations == n){breaker = true;}
        
        }
        //cout<<breaker<<" - breaker\n";
        if (breaker == true){break;}
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


/**
void playMasterMind()
{
    //MastermindWindow mwin{900, 20, 500, 500, 4, "Mastermind"};

    string hiddenWord = randomizeString(4,'A','F');
    bool correctGuess = false;
    cout << "Du spiller nå Master Mind!\n";
    int maxForsok = 6;
    for (int forsok = 0; forsok <= maxForsok; ++forsok)
    {
        cout << "***\nForsøk nr. "<<forsok<<" / "<<maxForsok<<"\n***\n";
        cout << "Gjør ett gjett.\n";
        string guess = mwin.getInput(4,'A','F');
        int riktigeBokstaver = 0;
        int riktigePosisjoner = 0;
        

        //addGuess(mwin, guess, 'A');

        string hiddenWordReplica = hiddenWord;

        for (int i = 3; i >= 0; --i)
        {
            if(hiddenWord[i] == toupper(guess[i]))
            {
                riktigePosisjoner+= 1; 
                guess.erase(i,1);
                hiddenWordReplica.erase(i,1);
            }
        }
        cout<<guess<<" -- guess\n";
        cout<<hiddenWordReplica<<" --word replica\n";
        cout <<hiddenWord<<"\n";
        if (riktigePosisjoner == 4)
        {
            cout << "Gratulerer! Ordet var: "<<hiddenWord<<"\n";
            correctGuess = true;
            break;
        }
        else
        {
            for (int i = guess.length()-1; i >= 0; --i)
            {
                for (int q = hiddenWordReplica.length()-1; q >= 0; --q)
                {   
                    cout<<"i: "<<i<<" q: "<<q<<" guess[i]: "<<guess[i]<<" hiddenWordReplica[q]: "<<hiddenWordReplica[q]<<"\n";
                    if (guess[i] == hiddenWordReplica[q])
                    {
                        riktigeBokstaver += 1;
                        hiddenWordReplica.erase(q,1);
                        break;
                    }
                }
            }
        }
        

        //addFeedback(mwin, riktigePosisjoner, riktigeBokstaver);
        //mwin.redraw();

        cout << "---\nDu hadde "<<riktigeBokstaver<< " riktige bokstaver, og "<< riktigePosisjoner <<"  av disse var også riktig plassert.\n---\n";
        
    }
    if (correctGuess == false)
    {
        cout<<"Beklager, du klarte ikke å gjette riktig. Ordet var: "<<hiddenWord<<"\nDu er sikkert god til andre ting...";
    }
}
**/