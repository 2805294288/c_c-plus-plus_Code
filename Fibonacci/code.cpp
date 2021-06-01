#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v(100001);
    v[0]=1;
    v[1]=1;
    for(int i = 2; i <= 100000; i++)
    {
        v[i] = (v[i-1] + v[i - 2]) % 1000000;
    }
    int number = 0;
    while(cin>>number)
    {
        if(number < 29)
        {
            cout << v[number] << endl;
        }
        else
        {
            printf("%06d\n",v[number]);
        }
    }
    return 0;
}