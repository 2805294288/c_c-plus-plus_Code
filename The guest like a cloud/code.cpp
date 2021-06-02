#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<long long> v(81);
    v[0] = 1;
    v[1] = 1;
    v[2] = 1;
    for(int i = 3; i <= 80; i++)
    {
        v[i] = v[i - 1] + v[ i- 2];
    }
    
    int from = 0;
    int to = 0;
    while(cin>>from>>to)
    {
        long long count = 0;
        for(int i = from; i <= to; i++)
        {
            count += v[i];
        }
        cout << count << endl;
    }
    return 0;
}