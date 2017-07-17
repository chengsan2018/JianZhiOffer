/************************************************************************/
/* ��������������һ�����������������ö���������ת����һ�������˫������Ҫ���ܴ����κ���
           �Ľ�㣬ֻ�ܵ������ֽ��ָ���ָ��
*/
/************************************************************************/

#ifndef _CBST2DOUBLYLIST_H
#define _CBST2DOUBLYLIST_H

#include <iostream>

using namespace std;

struct CBinaryTreeNode
{
	int mValue;
	CBinaryTreeNode* mLeft;
	CBinaryTreeNode* mRight;

	CBinaryTreeNode(int v, CBinaryTreeNode* l, CBinaryTreeNode* r) :mValue(v), mLeft(l), mRight(r){}
};

void InOrder(CBinaryTreeNode* theNode, CBinaryTreeNode *preNode, CBinaryTreeNode* postNode);
CBinaryTreeNode* FindPreNode(CBinaryTreeNode* theNode);
CBinaryTreeNode* FindPostNode(CBinaryTreeNode* theNode);


CBinaryTreeNode* Convert(CBinaryTreeNode* pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot, NULL, NULL);
		CBinaryTreeNode* headNode = pRoot;
		while (headNode->mLeft)
		{
			headNode = headNode->mLeft;
		}
		return headNode;
	}
	else
		return NULL;
}

void InOrder(CBinaryTreeNode* theNode, CBinaryTreeNode *preNode, CBinaryTreeNode* postNode)
{
	if ( !theNode->mLeft && ! theNode->mRight )  // �����Ҷ�ڵ�
	{
		theNode->mLeft = preNode;
		theNode->mRight = postNode;
		return;
	}

	CBinaryTreeNode* PreNodeFromSubTree = NULL; 
	CBinaryTreeNode* PostNodeFromSubTree = NULL;

	if (!theNode->mLeft)  //���������Ϊ��
	{
		theNode->mLeft = NULL;
	}
	else
	{
		PreNodeFromSubTree = FindPreNode(theNode); //���������У��ҵ���ǰ�ڵ��ǰ��
		InOrder(theNode->mLeft, preNode, theNode); //�������������������ĺ��һ����theNode
		theNode->mLeft = PreNodeFromSubTree;      
	}

	if (!theNode->mRight)
	{
		theNode->mRight = NULL;
	}
	else
	{ 
		PostNodeFromSubTree = FindPostNode(theNode); //���������У��ҵ���ǰ�ڵ�ĺ��
		InOrder(theNode->mRight, theNode, postNode); //��������������������ǰ��һ����theNode
		theNode->mRight = PostNodeFromSubTree;
	}

}

CBinaryTreeNode* FindPreNode(CBinaryTreeNode* theNode)
{
	CBinaryTreeNode* preNode = NULL;
	if (theNode->mLeft)
	{
		preNode = theNode->mLeft;
		while (preNode->mRight)
		{
			preNode = preNode->mRight;
		}
	}
	return preNode;
}

CBinaryTreeNode* FindPostNode(CBinaryTreeNode* theNode)
{
	CBinaryTreeNode* postNode = NULL;
	if (theNode->mRight)
	{
		postNode = theNode->mRight;
		while (postNode->mLeft)
		{
			postNode = postNode->mLeft;
		}
	}
	return postNode;
}

void test()
{
	CBinaryTreeNode node1(4, NULL, NULL);
	CBinaryTreeNode node2(8, NULL, NULL);
	CBinaryTreeNode node3(6, NULL, &node2);
	CBinaryTreeNode node4(12, NULL, NULL);
	CBinaryTreeNode node5(16, NULL, NULL);
	CBinaryTreeNode node6(14, &node4, &node5);
	CBinaryTreeNode node7(10, &node3, &node6);

	CBinaryTreeNode* pHead = Convert(&node7);

}

#endif
