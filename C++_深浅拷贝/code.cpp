#include<iostream>
#include<string>
#pragma warning(disable:4996)

using namespace std;

namespace mystring
{
	class string
	{
	public:
		string(const char* str = "")
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);
		}
		string(const string& s)
			:_str(NULL)
		{
			string tmp(s._str);   
			swap(_str, tmp._str);  
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s._str);    
				swap(_str, tmp._str);  
			}
			return *this;
		}
		char& operator[](int i)
		{
			return _str[i];
		}

		const char* c_str()
		{
			return _str;
		}

		~string()
		{
			delete[] _str;
		}

	private:
		char* _str;
	};
}

int main()
{
	mystring::string str1("Hello World!\n");
	mystring::string str2 = str1;
	cout << str1.c_str() << endl;
	cout << str2.c_str() << endl;
	str2[0] = 'h';
	cout << str1.c_str()<< endl;
	cout << str2.c_str() << endl;
}