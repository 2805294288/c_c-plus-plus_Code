#include<bits/stdc++.h>

using namespace std;

int main()
{
    int count = 0;
    while(cin >> count)
    {
        getchar();
        int maxcount = 0;
        int n = 0;
        while(count--)
        {
            string st;
            getline(cin, st);
            string ret = st.substr(2,st.size()-2);
            if(ret == "connect")
            {
                n++;
                if(n > maxcount)
                {
                    maxcount = n;
                }
            }
            else
            {
                n--;
            }
        }
        cout << maxcount << endl;
    }
    return 0;
}