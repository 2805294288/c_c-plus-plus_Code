#include<iostream>
#include<string>

using namespace std;
int main()
{
    string number;
    while(cin>>number)
    {
        if(number.size() < 2)
        {
            cout<<number<<endl;
        }
        else
        {
            long long ret;
            while(1)
            {
                ret = 0;
                for(auto c:number)
                {
                    ret += c-'0';
                }
                if(ret < 10)
                {
                    break;
                }
                number = to_string(ret);
            }
            cout<<ret<<endl;
        }
    }
    return 0;
}