#include<iostream>
#include<vector>
using namespace std;

template<size_t N>
class Bitset
{
public:
	Bitset()
	{
		_bits.resize((N >> 3) + 1, 0);//注意右移优先级，+1，比如10 10/8 = 1 但是应该加一
	}

	void set(size_t x)
	{
		size_t index = x / 8;
		size_t i = x % 8;

		_bits[index] |= 1 << i;
	}

	void reset(size_t x)
	{
		size_t index = x / 8;
		size_t i = x % 8;

		_bits[index] &= ~(1 << i);
	}

	bool test(size_t x)
	{
		size_t index = x / 8;
		size_t i = x % 8;

		return _bits[index] &( 1 << i);//对对应的位进行按位&
	}

private:
	std::vector<char> _bits; //按位操作，char除以8 
	//std::vector<int> _bits; // 除以32
};


void TestBitset()
{
	Bitset<100> bs;
	bs.set(10);
	bs.set(17);
	bs.set(80);

	cout << bs.test(10) << endl;
	cout << bs.test(17) << endl;
	cout << bs.test(80) << endl;
	cout << bs.test(81) << endl;

	bs.reset(80);
	bs.set(81);

	cout << endl;

	cout << bs.test(10) << endl;
	cout << bs.test(17) << endl;
	cout << bs.test(80) << endl;
	cout << bs.test(81) << endl;
}
int main()
{
	TestBitset();
	return 0;
}