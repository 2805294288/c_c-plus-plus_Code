#include<bits/stdc++.h>

using namespace std;

int main()
{
    int count = 0;
    while(cin>>count)
    {
        getchar();
        vector<string> Vs;
        while(count--)
        {
            string st;
            cin >> st;
            Vs.push_back(st);
        }
        
        sort(Vs.begin(),Vs.end());
        
        vector<string> ret;
        for(int i = 0; i < Vs.size() - 1; i++)
        {
            if(Vs[i+1].find(Vs[i]+'/') == -1)//这里必须加‘/’，要不然会出现/a/b，和/a/ba这样的情况。这样就是后面包含了前面的，实则没有。
            {
                ret.push_back(Vs[i]);
            }
        }
        
        ret.push_back(Vs[Vs.size()-1]);
        
        for(int i = 0; i < ret.size(); i++)
        {
            cout << "mkdir -p " << ret[i] << endl;
        }
        cout << endl;
    }
    return 0;
}