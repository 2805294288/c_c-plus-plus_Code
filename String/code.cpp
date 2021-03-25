#include"code.h"

using namespace mystring;

str::str()
	:_str(new char[1])
{

	_str[0] = '\0';
}

str::str(const char* str)
	:_str(new char[strlen(str) + 1])
{
		strcpy(_str, str);
}

str::str(const str& s)
	:_str(new char[strlen(s._str) + 1])
{
	strcpy(_str, s._str);
}

str& str::operator=(const str& s)
{
	if (this != &s)
	{
		delete[] _str;
		_str=(new char[strlen(s._str)+1]);
		strcpy(_str, s._str);
	}
	return *this;
}

char& str::operator[](int i)
{
	return _str[i];
}

str::~str()
{
	delete[] _str;
	_str = nullptr;
}

const char* str::c_str()
{
	return _str;
}

str::iterator str::end()
{
	return _str + _size;
}

str::const_iterator str::begin() const
{
	return _str;
}

str::const_iterator str::end() const
{
	return _str + _size;
}


str::iterator str::begin()
{
	return _str;
}

size_t str::size()
{
	return _size;
}

void str::reserve(size_t n)
{
	char* tmp = new char[n];
	strcpy(tmp, _str);
	delete[] _str;
	_str = tmp;
	_capacity = n;
}

void str::push_back(char& c)
{
	if (_size == _capacity)
	{
		reserve(2 * _capacity);
	}
	_str[_size] = c;
	++_size;
}

void str::append(const char* str)
{
	size_t len = strlen(str);
	if (_size + len > _capacity)
	{
		reserve(_size + len);
	}
	strcpy(_str+len, str);
	_size += len;
}

str& str::operator+=(char ch)
{
	push_back(ch);
	return *this;
}

str& str::operator+=(const char* str)
{
	append(str);
	return *this;
}

str& str::operator+=(const str& str)
{
	append(str._str);
	return *this;
}

void str::clear()
{
	delete[] _str;
	_size = _capacity = 0;
	_str = nullptr;
}

void str::swap(str& s)
 {
	std::swap(_str, s._str);
	std::swap(_size, s._size);
	std::swap(_capacity, s._capacity);
}

size_t str::size()const
{
	return _size;
}

size_t str::capacity()const
{
	return _capacity;
}

bool str::empty()const
{
	if (_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


