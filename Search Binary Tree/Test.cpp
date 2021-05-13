#include"BSTree.hpp"

//void TestBSTree()
//{
//	BSTree<int> t;
//	t.Insert(5);
//	t.Insert(2);
//	t.Insert(6);
//	t.Insert(8);
//	t.Insert(3);
//	t.Insert(4);
//
//
//	t.InOrder();
//	const BSTreeNode<int>* node = t.Find(2);
//	if (node)
//	{
//		cout << "ÕÒµ½ÁË" << endl;
//	}
//	else
//	{
//		cout << "Î´ÕÒµ½" << endl;
//	}
//	//t.Erase(6);
//	if (t.Erase(6))
//	{
//		cout << "erase success!" << endl;
//	}
//	else
//	{
//		cout << "erase fail!" << endl;
//	}
//	t.InOrder();
//	if (t.Erase(2))
//	{
//		cout << "erase success!" << endl;
//	}
//	else
//	{
//		cout << "erase fail!" << endl;
//	}
//	t.InOrder();
//}

void TestBSTreeKV()
{
	BSTree<string, string> dict;
	dict.Insert("string", "×Ö·û´®");
	dict.Insert("sort", "ÅÅÐò");
	dict.Insert("left", "×ó±ß");
	dict.Insert("right", "ÓÒ±ß");

	dict.InOrder();
	/*string str;
	while (cin >> str)
	{
		BSTreeNode<string, string>* ret = dict.Find(str);
		if (ret)
		{
			cout << ret->_val << endl;
		}
		else
		{
			cout << "µ¥´Ê²»´æÔÚ" << endl;
		}
	}*/
	string strArr[] = { "Æ»¹û","Ïã½¶","Î÷¹Ï","Î÷¹Ï","Æ»¹û" };
	BSTree<string, int> countTree;
	for (auto& str : strArr)
	{
		auto ret = countTree.Find(str);
		if (ret == nullptr)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_val++;
		}
	}
	countTree.InOrder();
}
int main()
{
	/*TestBSTree();*/
	TestBSTreeKV();
	return 0;
}