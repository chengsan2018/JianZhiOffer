/************************************************************************/
/* ��������������һ���ö�������һ����������ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·��������
           �ĸ��ڵ㿪ʼ����һֱ��Ҷ�ڵ��������Ľڵ��γ�һ��·����
*/
/************************************************************************/

#ifndef _CFINDPATHINBT_H
#define _CFINDPATHINBT_H

#include <vector>
#include <iostream>
using namespace std;

struct CBinaryTreeNode
{
	int mValue;
	CBinaryTreeNode* mLeft;
	CBinaryTreeNode* mRight;

	CBinaryTreeNode(int v, CBinaryTreeNode* l, CBinaryTreeNode* r) :mValue(v), mLeft(l), mRight(r){}
};


void FindPath(CBinaryTreeNode *pNode, int currentweight, int allweight, vector<int> &path);

void PrintPath(CBinaryTreeNode *pRoot, int allweight)
{
	if (pRoot)
	{
		vector<int> path;
		int currentweight = 0;
		FindPath(pRoot, currentweight, allweight, path);
	}

}

void FindPath(CBinaryTreeNode *pNode, int currentweight, int allweight, vector<int> &path)
{
	currentweight += pNode->mValue;
	path.push_back(pNode->mValue);

	bool isLeaf = pNode->mLeft == NULL && pNode->mRight == NULL;
	if (currentweight == allweight && isLeaf)
	{
		cout << "A path is found: ";
		for (vector<int>::iterator it = path.begin(); it != path.end(); it++)
		{
			if (it == path.end() - 1)
			{
				cout << *it;
			}
			else
			{
				cout << *it << " - ";
			}

		}
		cout << endl;
	}

	if (currentweight < allweight)
	{
		if (pNode->mLeft != NULL)
		{
			FindPath(pNode->mLeft, currentweight, allweight, path);
		}
		if (pNode->mRight != NULL)
		{
			FindPath(pNode->mRight, currentweight, allweight, path);
		}

	}

	path.pop_back();
	//currentweight -= pNode->mValue;
}

void test()
{
	CBinaryTreeNode node1(4, NULL, NULL);
	CBinaryTreeNode node2(7, NULL, NULL);
	CBinaryTreeNode node3(5, &node1, &node2);
	CBinaryTreeNode node4(12, NULL, NULL);
	CBinaryTreeNode node5(10, &node3, &node4);
	PrintPath(&node5, 22);
}




#endif
