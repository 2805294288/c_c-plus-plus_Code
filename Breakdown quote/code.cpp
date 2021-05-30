#include<bits/stdc++.h>

using namespace std;
bool Judge(int number)
{
    for(int i = 2; i<= sqrt(number); i++)
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
    long long number = 0;
    while(cin>>number)
    {
        string ret;
        int number1 = number;
        ret += to_string(number);
        ret += " = ";
        if(number <= 3)
        {
            ret += to_string(number);
        }
        else
        {
            int state = 0;
            int i = 2;
            while(i <= sqrt(number))
            {
            
                if(number % i == 0)
                {
                    state = 1;
                    int ret1 = number / i;
                    if(Judge(i))
                    {
                        ret += to_string(i);
                        ret += " * ";
                    }
                    if(Judge(ret1))
                    {
                        ret += to_string(ret1);
                        ret += " * ";
                    }
                    if(Judge(i) && Judge(ret1))
                    {
                        break;
                    }
                    else if(Judge(i) && !Judge(ret1))
                    {
                        number = ret1;
                    }
                }
                else
                {
                    i++;
                }
            }
                if(state == 1)
                {
                    ret.pop_back();
                    ret.pop_back();
                    ret.pop_back();
                }
                else
                {
                    ret += to_string(number1);
                }
            }
            cout << ret << endl;
        }
    return 0;
}