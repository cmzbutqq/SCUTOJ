#include<iostream>
using namespace std;

int main()
{
    int input;
    while(cin>>input)
    {
        for(int factor=2;factor<=input;factor++)
        {
            check:
            if (input%factor==0)
            {
                cout<<factor<<endl;
                input/=factor;
                goto check;
            }
        }
    }
    return 0;
}