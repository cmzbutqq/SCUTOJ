#include <iostream>
using namespace std;
struct Chains
{
    char character;
    Chains *next;
};

int main()
{
    string theString;
    while (cin >> theString)
    {
        int length = theString.length();
        Chains theChain[length];
        theChain[0].character = theString[0];
        theChain[0].next = NULL;
        for (int i = 1; i < length; i++)
        {
            theChain[i].character = theString[i];
            theChain[i].next = &theChain[i - 1];
        }
        Chains reader = theChain[length - 1];
        while (reader.next != NULL)
        {
            cout << reader.character;
            reader = *reader.next;
        }
        cout << reader.character << endl;
    }
    return 0;
}
