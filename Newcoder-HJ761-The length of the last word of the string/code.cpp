#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    getline(cin,str);
    
    size_t pos = str.rfind(' ');
    
    if(pos != string::npos)
    {
        cout<< (str.size()-pos-1) <<endl;
    }
    else
    {
        cout<< str.size() <<endl;
    }
    
    return 0;
}