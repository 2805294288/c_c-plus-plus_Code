#include <stdio.h>  
#include <Windows.h>
int main()
{
    int A = 0, B = 0, C = 0, D = 0;
    int FD;//因为c和d的供词刚好对立 表示对立的  
    int i;
    for (i = 1; i <= 4; i++)
    {

        if (i == 1)//A说的假  
        {
            A = 1; C = 1; FD = 1; D = 0;
        }
        if (i == 2)//B说的假  
        {
            A = 0; C = 0; FD = 1; D = 0;
        }
        if (i == 3)//C说的假  
        {
            A = 0; C = 1; FD = 0; D = 0;
        }
        if (i == 4)//D的说的假  
        {
            A = 0; C = 1; FD = 1; D = 1;
        }
        if (A + B + C + D + FD == 1 && FD == D)//只有一个人是凶手 当和为1时一个凶手出现  因为CD供词推出的都是D是不是 与上FD==D是为了排除D是D不是的情况   
            printf("C\n");
    }
    system("pause");
    return 0;
}