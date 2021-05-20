#include<iostream>
#include<string>

using namespace std;

int main()
{
    int count = 0;
    while(cin>>count)
    {
        string st;
        cin>>st;
        int head = 1;
        int tail = 1;
        int index = 1;
        if(count <= 4)
        {
            tail = count;
            for(auto s:st)
            {
                if(index == head && s == 'U')
                {
                    index = count;
                }
                else if(index == tail && s == 'D')
                {
                    index = 1;
                }
                else if(s == 'U' )
                {
                        index--;
                }
                else 
                {
                        index++;
                }
                    
            }
            for(int i=0; i<count-1; i++)
            {
            cout<<head+i<<" ";
            }
            cout<< head + (count-1) <<endl;
            cout<<index<<endl;
        }
            else
            {
                head = 1;
                tail = 4;
                index = 1; 
                for(auto s:st)
                {
                    if(index ==1 && s == 'U')
                    {
                        index = count;
                        tail = count;
                        head = count - 4 + 1;
                    }
                    else if(index == count && s== 'D')
                    {
                        index = 1;
                        head = 1;
                        tail = head + 3;
                    }
                    else if(s == 'U' )
                    {
                        index--;
                        if(index < head)
                        {
                            head--;
                            tail--;
                        }
                    }
                    else
                    {
                        index++;
                        if(index > tail)
                        {
                            head++;
                            tail++;
                        }
                    }
                }
                for(int i=0; i<3; i++)
                {
                cout<<head+i<<" ";
                }
                cout<< head + 3 <<endl;
                cout<<index<<endl;
        }
      }
    return 0;
}






