#include<bits/stdc++.h>

using namespace std;

int main()
{
    string Fst;
    string st;
    while(cin>>Fst>>st)
    {
        int size = Fst.size() - st.size();
        int count = 0;
        for(int i = 0; i <= size; i++)
        {
            string Gst = Fst.substr(i,st.size());
            if( Gst == st)
            {
                i += st.size() - 1;
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}