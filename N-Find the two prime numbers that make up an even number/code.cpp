#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;

bool Judge(int number)
{
    for(int i=2; i <= sqrt(number); i++)
    {
        if(number % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int number = 0;
    while(cin>>number)
    {
        int i = 2;
        int j = number-2;
        int n1 = i;
        int n2 = j;
        int ch = 0;
        int minch = INT_MAX;
        while(i <= j)
        {    
            if(Judge(i) && Judge(j))
            {
                ch = j - i;
                if(ch < minch)
                {
                    minch = ch;
                    n1 = i;
                    n2 = j;
                }
            }
            i++;
            j--;
        }
        cout<<n1<<endl;
        cout<<n2<<endl;
    }
    return 0;
}







