#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

int main()
{
	int i = 1;
	int j = 2;
	condition_variable c1;
	condition_variable c2;
	mutex mtx1;
	mutex mtx2;


	thread t1([&]() {
		while (i < 100)
		{
			c1.wait(unique_lock<mutex> (mtx1));
			cout << i << endl;
			i += 2;
			c2.notify_one();
		}
		});


	thread t2([&]() {
		while (j < 100)
		{
			c2.wait(unique_lock<mutex>(mtx2));
			cout << j << endl;
			j += 2;
			c1.notify_one();
		}
		});

	c1.notify_one();

	t1.join();
	t2.join();

	return 0;
}