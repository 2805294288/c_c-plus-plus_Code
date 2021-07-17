#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int count = 0;
    while(cin>>count)
    {
        vector<int> v;
        long long number = 0;
        while(count--)
        {
            cin>>number;
            v.push_back(number);
        }
        
        for(auto n:v)
        {
            n--;
            long long head = 1;
            long long tail = 1;
            long long ret = 1;
            while(n--)
            {
                ret = head + tail;
                ret = ret % 10000;
                head = tail;
                tail = ret;
            }
            string Sret;
            Sret = to_string(ret);
            if(Sret.size()==4)
            {
                cout << ret;
            }
           else
           {
               int size = 4-Sret.size();
               string st;
               while(size--)
               {
                   st += '0';
               }
               st += Sret;
               cout << st;
           }
        }
        cout << endl;
    }
    return 0;
}