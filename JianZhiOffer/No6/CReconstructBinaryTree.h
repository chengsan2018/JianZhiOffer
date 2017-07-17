/************************************************************************/
/* 问题描述：输入某二叉树的前序遍历结果和中序遍历结果，请重建出该二叉树
   例如：输入前序遍序列{1，2，4，7，3，5，6，8}
		中序遍历序列{4，7，2，1，5，3，8，6}
		重建该二叉树，并返回它的根结点
*/
/************************************************************************/
#ifndef _CRECONSTRUCTBINARYTREE_H
#define _CRECONSTRUCTBINARYTREE_H
#include <vector>

using namespace std;

//树结点
template <class T>
struct TreeNode
{
	T mValue;
	TreeNode<T> *mLeft;
	TreeNode<T> *mRight;

	TreeNode(T v, TreeNode<T> *l, TreeNode<T> *r):mValue(v),mLeft(l),mRight(r){}
};

//重建函数，采用递归的思想
template<class T>
TreeNode<T> *ReconstructBinaryTree(T *PreOrder, int n1, int n2, T *InOrder, int m1, int m2)
{
	if (n1 > n2 || m1 > m2 || n1 < 0 || n2 < 0 || m1 < 0|| m2 < 0)
	//表示子树为空
	{
		return NULL;
	}
	//子树不为空， 则前序遍历序列的第一个结点是根结点
	TreeNode<T> *root = new TreeNode <T> (PreOrder[n1], NULL, NULL);

	if (n1 == n2 && m1 == m2) //表示子树只有一个结点，
	{
		return root;//直接返回root
	}
	//如果子树有多个结点
	//在中序遍历序列中，找到根结点的位置 i
	int i;
	for (i = m1; i <= m2;i++)
	{
		if (InOrder[i] == PreOrder[n1])
		{
			break;
		}
	}
	//中序遍历序列中，i左边的结点为左子树，i右边的结点为右子树。
	TreeNode<T> *leftchild = ReconstructBinaryTree(PreOrder, n1+1, n1+i-m1, InOrder, m1, i - 1);
	TreeNode<T> *rightchild = ReconstructBinaryTree(PreOrder, n1+i-m1+1, n2, InOrder, i + 1, m2);
	root->mLeft = leftchild;
	root->mRight = rightchild;
	return root;
}

//测试函数
void test()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	a.push_back(7);
	a.push_back(3);
	a.push_back(5);
	a.push_back(6);
	a.push_back(8);

	vector<int> b;
	b.push_back(4);
	b.push_back(7);
	b.push_back(2);
	b.push_back(1);
	b.push_back(5);
	b.push_back(3);
	b.push_back(8);
	b.push_back(6); 

	TreeNode<int> *root = NULL;
	root = ReconstructBinaryTree(&a[0], 0, 7, &b[0], 0, 7);
}
#endif