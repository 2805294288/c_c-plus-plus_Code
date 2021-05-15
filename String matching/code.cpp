#include<iostream>

using namespace std;

int main()
{
    string st1;
    string st2;
    while(cin>>st1>>st2)
    {
        int size1 = 0;
        int size = st2.size();
        int size2 = 0;
        while(size2 < size)
        {
            if(st1[size1] != st2[size2])
            {
                if(isalnum(st2[size2]) && st1[size1] == '?')
                {
                    size1++;
                    size2++;
                }
                else if(isalnum(st2[size2]) && st1[size1] == '*')
                {
                    size1++;
                    size2++;
                    while(size2 < size && st1[size1] != st2[size2])
                    {
                        size2++;
                    }
                }
                else
                {
                    cout << "false" <<endl;
                    break;
                }
            }
            else
            {
                size1++;
                size2++;
            }
        }
        if(size2 >= size)
        cout << "true" <<endl;
    }
    return 0;
}