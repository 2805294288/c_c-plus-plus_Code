//#pragma once
//#include<iostream>
//
//using namespace std;
//
//template <class K>
//struct BSTreeNode
//{
//	K _key;
//	struct BSTreeNode<K>* _left;
//	struct BSTreeNode<K>* _right;
//
//	BSTreeNode(const K& key)
//		:_key(key)
//		, _left(nullptr)
//		,_right(nullptr)
//	{}
//};
//
//template<class K>
//class BSTree
//{
//	typedef BSTreeNode<K> Node;
//public:
//	bool Insert(K key)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(key);
//			return true;
//		}
//		
//			Node* parent = nullptr;
//			Node* cur = _root;
//			while (cur)
//			{
//				if (cur->_key > key)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else if(cur->_key < key)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else
//				{
//					return false;
//				}
//			}
//
//			Node* newnode = new Node(key);
//			if (parent->_key>key)
//			{
//				parent->_left = newnode;
//			}
//			else 
//			{
//				parent->_right = newnode;
//			}
//			return true;
//	}
//	void _InOrder(Node* root)
//	{
//		if (root == nullptr)
//		{
//			return;
//		}
//		//递归遍历，左中右。且返回的就是有顺序的。
//		_InOrder(root->_left);
//		cout << root->_key<<" ";
//		_InOrder(root->_right);
//	}
//	void InOrder()
//	{
//		_InOrder(_root);
//		cout << endl;
//	}
//
//	const Node* Find(const K& key)
//	{
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				cur = cur->_left;
//			}
//			else
//			{
//				return cur;
//			}
//		}
//		return nullptr;
//	}
//	bool Erase(const K& key)
//	{
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else
//			{
//				if (cur->_left == nullptr)
//				{
//					if (cur == _root)
//					{
//						_root = cur->_right;
//					}
//					else
//					{
//						if (cur == parent->_left)
//						{
//							parent->_left = cur->_right;
//						}
//						else
//						{
//							parent->_right = cur->_right;
//						}
//					}
//					delete cur;
//				}
//				else if (cur->_right == nullptr)
//				{
//					if (cur == _root)
//					{
//						_root = cur->_left;
//					}
//					else
//					{
//						if (cur == parent->_left)
//						{
//							parent->_left = cur->_left;
//						}
//						else
//						{
//							parent->_right = cur->_left;
//						}
//					}
//					delete cur;
//				}
//				else
//				{
//					Node* subparent = cur;
//					Node* subMin = cur->_right;
//					while (subMin->_left)
//					{
//						parent = subMin;
//						subMin = subMin->_left;
//					}
//
//					cur->_key = subMin->_key;
//					if (subparent->_left == subMin)
//					{
//						subparent->_left = subMin->_right;
//					}
//					else
//					{
//						subparent->_right = subMin->_right;
//					}
//					delete subMin;
//				}
//				return true;
//			}
//
//		}
//		return false;
//	}
//private:
//	Node* _root=nullptr;
//};

#pragma once
#include<iostream>

using namespace std;

template <class K,class V>
struct BSTreeNode
{
	K _key;
	V _val;
	struct BSTreeNode<K,V>* _left;
	struct BSTreeNode<K,V>* _right;

	BSTreeNode(const K& key, const V& val)
		:_key(key)
		, _val(val)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class K,class V>
class BSTree
{
	typedef BSTreeNode<K,V> Node;
public:
	bool Insert(const K& key,const V& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(key,val);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		Node* newnode = new Node(key,val);
		if (parent->_key > key)
		{
			parent->_left = newnode;
		}
		else
		{
			parent->_right = newnode;
		}
		return true;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		//递归遍历，左中右。且返回的就是有顺序的。
		_InOrder(root->_left);
		cout << root->_key << ":" << root->_val << endl;
		_InOrder(root->_right);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}
	//bool Erase(const K& key)
	//{
	//	Node* parent = nullptr;
	//	Node* cur = _root;
	//	while (cur)
	//	{
	//		if (cur->_key > key)
	//		{
	//			parent = cur;
	//			cur = cur->_left;
	//		}
	//		else if (cur->_key < key)
	//		{
	//			parent = cur;
	//			cur = cur->_right;
	//		}
	//		else
	//		{
	//			if (cur->_left == nullptr)
	//			{
	//				if (cur == _root)
	//				{
	//					_root = cur->_right;
	//				}
	//				else
	//				{
	//					if (cur == parent->_left)
	//					{
	//						parent->_left = cur->_right;
	//					}
	//					else
	//					{
	//						parent->_right = cur->_right;
	//					}
	//				}
	//				delete cur;
	//			}
	//			else if (cur->_right == nullptr)
	//			{
	//				if (cur == _root)
	//				{
	//					_root = cur->_left;
	//				}
	//				else
	//				{
	//					if (cur == parent->_left)
	//					{
	//						parent->_left = cur->_left;
	//					}
	//					else
	//					{
	//						parent->_right = cur->_left;
	//					}
	//				}
	//				delete cur;
	//			}
	//			else
	//			{
	//				Node* subparent = cur;
	//				Node* subMin = cur->_right;
	//				while (subMin->_left)
	//				{
	//					parent = subMin;
	//					subMin = subMin->_left;
	//				}

	//				cur->_key = subMin->_key;
	//				if (subparent->_left == subMin)
	//				{
	//					subparent->_left = subMin->_right;
	//				}
	//				else
	//				{
	//					subparent->_right = subMin->_right;
	//				}
	//				delete subMin;
	//			}
	//			return true;
	//		}

	//	}
	//	return false;
	//}
private:
	Node* _root = nullptr;
};

