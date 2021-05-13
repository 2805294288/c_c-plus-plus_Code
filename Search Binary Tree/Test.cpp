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
//		cout << "�ҵ���" << endl;
//	}
//	else
//	{
//		cout << "δ�ҵ�" << endl;
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
	dict.Insert("string", "�ַ���");
	dict.Insert("sort", "����");
	dict.Insert("left", "���");
	dict.Insert("right", "�ұ�");

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
			cout << "���ʲ�����" << endl;
		}
	}*/
	string strArr[] = { "ƻ��","�㽶","����","����","ƻ��" };
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