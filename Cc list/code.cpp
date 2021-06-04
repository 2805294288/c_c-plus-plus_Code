#include<bits/stdc++.h>

using namespace std;

string Judge(string st1, string st2)
{
    string ret;
    int i = 0;
    while(i < st1.size())
    {
        if(st1[i] == '"')
        {
            int index = st1.find('"',i+1);//find函数从当前位置开始会计算当前位置最左边是一个闭区间，默认为0
            ret = st1.substr(i+1,index - i - 1);//substr是一个左闭右开区间。
            if(ret == st2)
            {
                return "Ignore";
            }
            ret.clear();
            i += index - i + 1;
        }
        else
        {
            if(st1[i] == ',')
            {
                if(ret == st2)
                {
                    return "Ignore";
                }
                ret.clear();
            }
            else
            {
                ret += st1[i];
            }
            i++;
        }
    }
    if(ret == st2)//末尾的时候还要再判断一下
    {
        return "Ignore";
    }
    else
    {
    return "Important!";
    }
}

int main()
{
    string st1;
    string st2;
    while(getline(cin,st1))
    {
        getline(cin,st2);
        cout << Judge(st1,st2) << endl;
    }
    return 0;
}