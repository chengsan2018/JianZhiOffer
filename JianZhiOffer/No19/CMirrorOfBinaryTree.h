#ifndef _CMIRROROFBINARYTREE
#define _CMIRROROFBINARYTREE

#include <iostream>

using namespace std;

/************************************************************************/
/* 二叉树结点
*/
/************************************************************************/
struct CBinaryTreeNode
{
	int mValue;
	CBinaryTreeNode* mLeft;
	CBinaryTreeNode* mRight;

	CBinaryTreeNode(int v, CBinaryTreeNode* l, CBinaryTreeNode* r) :mValue(v), mLeft(l), mRight(r){}
};

/************************************************************************/
/*函数功能： 将二叉树进行镜像转换 
		   采用递归的思想
*/
/************************************************************************/
void MirrorRecursively(CBinaryTreeNode *pRoot)
{
	if (pRoot)
	{
		if (pRoot->mLeft == NULL && pRoot->mRight == NULL)
		{
			return;
		}

		CBinaryTreeNode *temp = pRoot->mLeft;
		pRoot->mLeft = pRoot->mRight;
		pRoot->mRight = temp;

		MirrorRecursively(pRoot->mLeft);
		MirrorRecursively(pRoot->mRight);
	}
}

void test()
{
	CBinaryTreeNode node1(5, NULL, NULL);
	CBinaryTreeNode node2(7, NULL, NULL);
	CBinaryTreeNode node3(6, &node1, &node2);
	CBinaryTreeNode node4(9, NULL, NULL);
	CBinaryTreeNode node5(11, NULL, NULL);
	CBinaryTreeNode node6(10, &node4, &node5);
	CBinaryTreeNode node7(8, &node3, &node6);

	MirrorRecursively(&node7);
}

#endif
