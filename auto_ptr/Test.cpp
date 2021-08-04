#include<iostream>

using namespace std;

namespace my
{
	template <class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* p)
			:_ptr(p)
		{}

		auto_ptr(auto_ptr<T>& p)
			:_ptr(p._ptr)
		{
			p._ptr = nullptr;
		}

		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}

		auto_ptr<T>& operator=(auto_ptr<T>& p)
		{
			if (this != &p)
			{
				if (_ptr)
				{
					delete _ptr;
				}

				_ptr = p._ptr;
				p._ptr = nullptr;
			}
			return *this;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
			}
		}
	private:
		T* _ptr;
	};

}

void Test()
{
	my::auto_ptr<int> p(new int);

	my::auto_ptr<int> p1(p);
}
int main()
{
	Test();
	return 0;
}