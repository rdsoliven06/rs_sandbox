#include <iostream>
using namespace std;

const int MAX_NUM_CASES = 5;

class HandleCovid
{
private:
    /* 1 = Exposed/Positive 
       0 = Not Exposed/Negative. */
    int covidArr[MAX_NUM_CASES] = {0,0,0,0,0}; 
    int isExposedArr[MAX_NUM_CASES] = {1,0,0,1,0};
public:
    /* Default Constructor */
    HandleCovid();
    /* Deefault Destructor */
    ~HandleCovid(); 
    /* countPositiveCase Method
       Output:  Returns number of positive case */
    void countPositiveCase();
};

HandleCovid::HandleCovid(){}
HandleCovid::~HandleCovid(){}

void  HandleCovid::countPositiveCase()
{   
    int isPositive = 1;
    int isNegative = 0;
    int numPosCase = 0;
    for (int i=0;i<MAX_NUM_CASES;i++)
    {
        if (covidArr[i] == isNegative && isExposedArr[i] == isPositive)
        {
            covidArr[i] = isPositive;
            ++numPosCase;
        }
        else
        {
            covidArr[i];
            numPosCase;
        }
    }
   
    cout << "The total number of positive cases is " << numPosCase << "." << endl;
    for (int i=0;i<MAX_NUM_CASES;i++)
    {
        cout << "Person ID [" << i << "] = ";
        cout <<  covidArr[i] << endl;
    }
}

// Main 
int main(){
    HandleCovid handleCovid;
    handleCovid.countPositiveCase();
    return 0;
}
