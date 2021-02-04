#include<iostream>
#include<ctime>//产生随机数用的头文件
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));//种下一个产生随机数的种子
	int number = rand() % 100 + 1;//产生的随机数是在1到100之间。
	int val = 0;
	int count = 5;
	while (1) {
		cout << "你还有" << count << "次机会" << endl;
		cout << "请输入你猜测的数字：" << endl;
		cin >> val;
		if (number > val) {
			cout << "猜小了" << endl;
		}
		else if (number < val) {
			cout << "猜大了" << endl;
		}
		else {
			cout << "恭喜你！猜对了！"<<endl;
			break;
		}
		count--;
		if (count < 1) {
			cout << "抱歉！你的机会已经用完！" << endl;
			break;
		}
	}
}