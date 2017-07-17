/************************************************************************/
/* 问题描述：对二叉树按层次进行遍历，并打印
*/
/************************************************************************/
#ifndef _CPRINTTREE_H
#define _CPRINTTREE_H

#include <iostream>
#include <queue>

using namespace std;

struct CBinaryTreeNode
{
	int mValue;
	CBinaryTreeNode* mLeft;
	CBinaryTreeNode* mRight;

	CBinaryTreeNode(int v, CBinaryTreeNode* l, CBinaryTreeNode* r) :mValue(v), mLeft(l), mRight(r){}
};


/************************************************************************/
/* 层次遍历
*/
/************************************************************************/
void PrintBinaryTree(CBinaryTreeNode* pRoot)
{
	if (pRoot)
	{
		queue<CBinaryTreeNode*> NodeToPrint;  //!!!!
		NodeToPrint.push(pRoot);
		while (!NodeToPrint.empty())
		{
			CBinaryTreeNode* pCurrent = NodeToPrint.front();
			cout << pCurrent->mValue << ' ';
			if(pCurrent->mLeft)
				NodeToPrint.push(pCurrent->mLeft);
			if(pCurrent->mRight)
				NodeToPrint.push(pCurrent->mRight);
			NodeToPrint.pop();
		}
		cout << endl;
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
	PrintBinaryTree(&node7);
}
#endif
