#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

void thread_print()
{
	mutex _mtx;
	condition_variable c;
	bool flag = true;

	thread t1([&]() {
		int i = 0;
		while (i <= 100)
		{
			unique_lock<mutex> lock(_mtx);
			c.wait(lock, [&]() ->bool {return flag; });
			cout << i << endl;
			i+=2;
			flag = false;
			c.notify_one();
		}
	});

	thread t2([&]() {
		int j = 1;
		while (j < 100)
		{
			unique_lock<mutex> lock(_mtx);
			c.wait(lock, [&]() ->bool {return !flag; });
			cout << j << endl;
			j+=2;
			flag = true;
			c.notify_one();
		}
		});

	t1.join();
	t2.join();
}

int main()
{
	thread_print();

	return 0;
}