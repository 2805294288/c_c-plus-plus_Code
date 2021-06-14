#include<bits/stdc++.h>

using namespace std;

void Func(set<string>& st, string& s)
{
    string ret;
    for(auto& c : s)
    {
        if(c >= '0' && c <= '9')
        {
            ret += c;
        }
        else if(c >= 'A' && c <= 'C')
        {
            ret += '2';
        }
        else if(c >= 'D' && c <= 'F')
        {
            ret += '3';
        }
        else if(c >= 'G' && c <= 'I')
        {
            ret += '4';
        }
        else if(c >= 'J' && c <= 'L')
        {
            ret += '5';
        }
        else if(c >= 'M' && c <= 'O')
        {
            ret += '6';
        }
        else if(c >= 'P' && c <= 'S')
        {
            ret += '7';
        }
        else if(c >= 'T' && c <= 'V')
        {
            ret += '8';
        }
        else if(c >= 'W' && c <= 'Z')
        {
            ret += '9';
        }
        
        if(ret.size() == 3)
        {
            ret += '-';
        }
    }
    st.insert(ret);
}

int main()
{
    int count = 0;
    while(cin>>count)
    {
        //getchar();
        set<string> st;
        string s;
        while(count--)
        {
            cin>>s;
            Func(st,s);
        }
        
        auto it = st.begin();
        while(it != st.end())
        {
            cout << *it << endl;
            it++;
        }
        cout << endl;
    }
    return 0;
}