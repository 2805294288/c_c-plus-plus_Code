// write your code here cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<long long> v1(25,0);
    v1[1] = 0;
    v1[2] = 1;
    vector<long long> v2(25,0);
    v2[1] = 1;
    v2[2] = 2;
    long long ch = 2;
    for(int i = 3; i < 25; i++)
    {
        v1[i] = (i-1)*(v1[i-1]+v1[i-2]);
        ch *= i;
        v2[i] = ch;
    }
    int number = 0;
    while(cin >> number)
    {
        float ret = 0;
        ret = 1.0 * v1[number] / v2[number] * 100;
        printf("%0.2f%%\n",ret);
    }
    return 0;
}
