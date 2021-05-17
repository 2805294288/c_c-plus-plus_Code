#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int main()
{
    string st1;
    string st2;
    while(cin >> st1 >> st2)
    {
        int Sst1 = st1.size();
        int Sst2 = st2.size();
        string ret;
        int max = 0;
        if(Sst2 < Sst1)
        st2.swap(st1);
        
        vector<vector<int>> arr(st1.size()+1,vector<int>(st2.size()+1,0));
        
        for(int i=1; i<=st1.size(); i++)
        {
            for(int j=1; j<=st2.size(); j++)
            {
                if(st1[i-1] == st2[j-1])
                {
                    arr[i][j] = arr[i-1][j-1]+1;
                    if(arr[i][j] > max)
                    {
                        max = arr[i][j];
                        ret=st1.substr(i-max,max);
                    }
                }
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}