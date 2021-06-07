#include<iostream>
#include<string>
#include<vector>

using namespace std;

string Judge(int Lsize, vector<string>& LeftV, int Rsize, vector<string>& RightV)
{
    string ret;
    if (Lsize == 2 || Rsize == 2)
    {
        if (LeftV[0] == "joker" || RightV[0] == "joker")
        {
            ret += "joker";
            ret += ' ';
            ret += "JOKER";

            return ret;
        }
        if (LeftV[0] == "JOKER" || RightV[0] == "JOKER")
        {
            ret += "JOKER";
            ret += ' ';
            ret += "joker";

            return ret;
        }
    }
    if (Lsize == 4 || Rsize == 4)
    {
        if (Lsize == 4)
        {
            for (int i = 0; i < 4; i++)
            {
                ret += LeftV[i];
                ret += ' ';
            }
            ret.pop_back();
            return ret;
        }
        if (Rsize == 4)
        {
            for (int i = 0; i < 4; i++)
            {
                ret += RightV[i];
                ret += ' ';
            }
            ret.pop_back();
            return ret;
        }
    }
    else
    {
        vector<string> com;
        for (int i = 3; i <= 10; i++)
        {
            com.push_back(to_string(i));
        }
        com.push_back("J");
        com.push_back("Q");
        com.push_back("K");
        com.push_back("A");
        com.push_back("2");

        if (Lsize == Rsize)
        {
            int m = 0;
            for (m = 0; m < 13; m++)
            {
                if (LeftV[0] == com[m])
                {
                    break;
                }
            }
            int n = 0;
            for (n = 0; n < 13; n++)
            {
                if (RightV[0] == com[n])
                {
                    break;
                }
            }
            if (m > n)
            {
                for (int i = 0; i < Lsize; i++)
                {
                    ret += LeftV[i];
                    ret += ' ';
                }
                ret.pop_back();
                return ret;
            }
            if (m < n)
            {
                for (int i = 0; i < Rsize; i++)
                {
                    ret += RightV[i];
                    ret += ' ';
                }
                ret.pop_back();
                return ret;
            }
        }
        else
        {
            ret = "ERROR";
            return ret;
        }
    }
}

int main()
{
    string st;
    while (getline(cin,st))
    {
        vector<string> LeftV;
        vector<string> RightV;

        int h = 0;
        string Lst;
        for (; h < st.size(); h++)
        {
            if (st[h] == '-')
            {
                LeftV.push_back(Lst);
                break;
            }
            if (st[h] == ' ')
            {
                LeftV.push_back(Lst);
                Lst.clear();
            }
            else
                Lst += st[h];
        }
        string Rst;
        for (int j = h + 1; j <= st.size(); j++)
        {
            if (j == st.size())
            {
                RightV.push_back(Rst);
                break;
            }
            if (st[j] == ' ')
            {
                RightV.push_back(Rst);
                Rst.clear();
            }
            else
                Rst += st[j];
        }

        int Lsize = LeftV.size();
        int Rsize = RightV.size();
        string  Ret;
        Ret = Judge(Lsize, LeftV, Rsize, RightV);
        cout << Ret << endl;
    }
    return 0;
}