#include<stdio.h>
#include<windows.h>
int main()
{
    int FactSum(int strat, int end);
    int strat = 1;
    int end = 2;
    int total = FactSum(strat, end);
    printf("%d", total);
    return 0;
}

int FactSum(int strat, int end)
{
    int sum = 0;
    int Fact(int n);
    for (int i = strat; i <= end; i++)
    {
        sum = sum + Fact(i);
    }
    return sum;
}

int Fact(int n)
{
    int result = 1;
    for (int i = n; i >= 1; i--)
        result *= i;
    return result;
}