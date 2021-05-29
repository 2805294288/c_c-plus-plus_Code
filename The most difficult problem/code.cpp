#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<char> v1;
    char i = 'A';
    for( i='A'; i<'Z'; i++)
    {
        v1.push_back(i);
    }
    vector<char> v2;
    char j = 'V';
    for( j = 'V'; j<='Z'; j++)
    {
        v2.push_back(j);
    }
    for( j = 'A'; j <= 'U'; j++)
    {
        v2.push_back(j);
    }
    
    string st;
    while(getline(cin,st))
    {
        string ret;
        for(auto& c:st)
        {
            if(isupper(c))
            {
                ret += v2[c-'A'];
            }
            else
                ret += c;
        }
        cout<<ret<<endl;
    }
    return 0;
}











