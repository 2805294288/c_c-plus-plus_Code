#include<bits/stdc++.h>

using namespace std;

int main()
{
    int number = 0;
    while(cin>>number)
    {
        int count = 0;
        for(int i=2; i<sqrt(number); i++)
        {
            if(number % i == 0)
            {
                while(number % i == 0)
                {
                    number /= i;
                }
                count++;
            }
        }
        if(number != 1)
        {
             count++; 
        }
        cout << count << endl;
    }
    return 0;
}