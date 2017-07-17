/************************************************************************/
/* ��������������ĳ��������ǰ�������������������������ؽ����ö�����
   ���磺����ǰ�������{1��2��4��7��3��5��6��8}
		�����������{4��7��2��1��5��3��8��6}
		�ؽ��ö����������������ĸ����
*/
/************************************************************************/
#ifndef _CRECONSTRUCTBINARYTREE_H
#define _CRECONSTRUCTBINARYTREE_H
#include <vector>

using namespace std;

//�����
template <class T>
struct TreeNode
{
	T mValue;
	TreeNode<T> *mLeft;
	TreeNode<T> *mRight;

	TreeNode(T v, TreeNode<T> *l, TreeNode<T> *r):mValue(v),mLeft(l),mRight(r){}
};

//�ؽ����������õݹ��˼��
template<class T>
TreeNode<T> *ReconstructBinaryTree(T *PreOrder, int n1, int n2, T *InOrder, int m1, int m2)
{
	if (n1 > n2 || m1 > m2 || n1 < 0 || n2 < 0 || m1 < 0|| m2 < 0)
	//��ʾ����Ϊ��
	{
		return NULL;
	}
	//������Ϊ�գ� ��ǰ��������еĵ�һ������Ǹ����
	TreeNode<T> *root = new TreeNode <T> (PreOrder[n1], NULL, NULL);

	if (n1 == n2 && m1 == m2) //��ʾ����ֻ��һ����㣬
	{
		return root;//ֱ�ӷ���root
	}
	//��������ж�����
	//��������������У��ҵ�������λ�� i
	int i;
	for (i = m1; i <= m2;i++)
	{
		if (InOrder[i] == PreOrder[n1])
		{
			break;
		}
	}
	//������������У�i��ߵĽ��Ϊ��������i�ұߵĽ��Ϊ��������
	TreeNode<T> *leftchild = ReconstructBinaryTree(PreOrder, n1+1, n1+i-m1, InOrder, m1, i - 1);
	TreeNode<T> *rightchild = ReconstructBinaryTree(PreOrder, n1+i-m1+1, n2, InOrder, i + 1, m2);
	root->mLeft = leftchild;
	root->mRight = rightchild;
	return root;
}

//���Ժ���
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