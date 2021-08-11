#include<iostream>

template<class T>
class Unique_ptr
{
public:
	Unique_ptr(T* p)
		:_ptr(p)
	{}

	~Unique_ptr()
	{
		delete _ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}

	T* get()
	{
		return _ptr;
	}

	Unique_ptr(const Unique_ptr<int>&) = delete;
	Unique_ptr<T>& operator=(const Unique_ptr<int>&) = delete;
private:
	T* _ptr;
};

int main()
{
	Unique_ptr<int> p1(new int(0));
	Unique_ptr<int> p2(p1);
	Unique_ptr<int> p3 = p1;


}

