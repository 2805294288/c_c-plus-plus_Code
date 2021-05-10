#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string st1;
    getline(cin, st1);

    int size = st1.size();
    int head = 0;
    int tail = 0;
    int state = 0;
    while(head <size && st1[head] == '"' || st1[head] == ' ')
    {
        if (st1[head] == '"')
        {
            state = 1;
        }
        head++;
    }
    tail = head;

    string st2;
    int count = 0;
    vector<string> arr;
    while (tail<=size)
    {
        if (tail == size)
        {
            count++;
            arr.push_back(st2);
            break;
        }
        if (state == 1)
        {
            if (st1[tail] == '"')
            {
                count++;
                arr.push_back(st2);
                st2.clear();
                state = 0;
                tail=tail+2;
                if (tail < size && st1[tail] == '"')
                {
                    tail++;
                    state = 1;
                }
            }
        }
        else 
        {
            if (st1[tail] == ' ')
            {
                count++;
                arr.push_back(st2);
                st2.clear();
                tail++;
                state = 0;
                if (st1[tail] == '"')
                {
                    tail++;
                    state = 1;
                }
            }
        }
        if(tail<size)
        st2 += st1[tail];
        tail++;
    }
    cout << count << endl;
    for (auto st : arr)
    {
        cout << st << endl;
    }
    return 0;
}
