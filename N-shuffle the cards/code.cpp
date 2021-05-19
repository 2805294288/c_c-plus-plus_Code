#include<iostream>
#include<vector>

using namespace std;
vector<int> XP(vector<int>& ret,vector<int>& CV)
{
    for(int i=0; i<CV.size()/2; i++)
    {
        ret[i*2] = CV[i];
        ret[i*2+1] = CV[i+CV.size()/2];
    }
    return ret;
}
int main()
{
    int n = 0;
    cin>>n;
    while(n--)
    {
        int size = 0;
        cin>>size;
        int count = 0;
        cin>>count; 
        vector<int> CV;
        int number = 0;
        for(int i=0; i<2*size; i++)
        {
            cin>>number;
            CV.push_back(number);
        }
        vector<int> ret(2*size);
        while(count--)
        {
            XP(ret,CV);
            CV = ret;
        }
        
        for(int i=0; i<ret.size()-1; i++)
        {
            cout<<ret[i]<<" ";
        }
        cout<<ret[ret.size()-1]<<endl;
    }
    return 0;
}







