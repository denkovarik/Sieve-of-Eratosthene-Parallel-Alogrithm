#include <bits/stdc++.h>

using namespace std;

bool isUnsignedInt(string number)
{
    for(unsigned i = 0; i < number.length(); i++)
    {
        if(!isdigit(number[i]))
            return false;
    }

    return true;
}

int main(int argc, char **argv)
{
    unsigned p = 2;
    unsigned n = 1000;
    unsigned numDigitsN;
    unsigned numDigitsP;
    unsigned counter = 0;
    string argNum;
    vector<bool> primeList;

    // Read command line arguments
    if(argc > 1)
    {
        argNum = argv[1];        
        if(isUnsignedInt(argNum))
        {
            n = stoi(argNum);
        }
    }

    primeList.resize(n+1, true);

    while(p <= n)
    {
        if(counter % 10 == 0)
        {
            numDigitsN = log10(n) + 1;
            numDigitsP = 1;

            if(counter > 0)
            {
                numDigitsP = log10(counter) + 1;
                cout << endl;
            }

            for(int i = 1; i < numDigitsN - numDigitsP; i++)
                cout << " ";
            cout << counter << ": "; 
        }

        cout << p << " ";

        for(unsigned i = 2; i * p < primeList.size(); i++)
        {
            primeList[i*p] = false;
        }  
        
        // Find the first prime larger than p
        p++;
        while(p < primeList.size() && !primeList[p]) 
            p++;

        counter++;
    }
    cout << endl;
}
