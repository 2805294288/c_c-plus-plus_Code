#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class Person
{
public:
	Person(string name, int score)
	{
		this->m_name = name;
		this->m_score = score;
	}
	string m_name;
	int m_score;
};
void GreatPerson(vector<Person>& v)
{
	string nameseed = "ABC";
	for (int i = 0; i < 3; i++) {
		string name = "选手";
		name += nameseed[i];

		int score = 0;
		Person p(name, score);

		v.push_back(p);

	}
}
void SetScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>d;
		for (int i = 1; i < 4; i++) 
		{
			int score = 0;
			cout << "请输入" << it->m_name << "的第" << i << "个分数：" << endl;
			cin >> score;
			d.push_back(score);
		}
		sort(d.begin(), d.end());

		d.pop_back();
		d.pop_front();

		int sum = 0;
		for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
		{
			sum += *it;
		}

		int avg = sum / d.size();

		it->m_score = avg;

		cout << it->m_name << ": " << "成绩：" << it->m_score << endl;
		cout << endl;
	}
}
int main()
{
	vector<Person>v;
	GreatPerson(v);

	SetScore(v);

	return 0;
}