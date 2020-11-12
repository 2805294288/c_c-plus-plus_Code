#include<stdio.h>
#include<string.h>
#include<windows.h>
#define NAME "TOM"
#define PASSWORD "1234"
#pragma warning (disable: 4996)
int main()
{
    int time = 3;
    int times = 3;
    char name[64];
    char password[64];
    do
    {
        printf("请输入你的账户：\n ");
        scanf("%s", name);
        printf("请输入你的密码:\n");
        scanf("%s", password);
        if (strcmp(name, NAME) == 0 && strcmp(password, PASSWORD) == 0)
        {
            printf("恭喜你！登陆成功!");
            break;
        }
        else
        {
            printf("输入错误！从新输入！\n");
            time--;
            if (time <= 0) {
                printf("你需要等%d秒钟\n", times);
                Sleep(times*1000);
                times += 3;
            } 
            else
            printf("你还有%d次机会：\n", time);
        }
    } while (1);
    return 0;
}