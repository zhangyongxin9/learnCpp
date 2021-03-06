// BTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <deque>
using namespace std;

struct BTreeNode
{
	int value;
	BTreeNode* m_left;
	BTreeNode* m_right;
};

BTreeNode* constructCore(int* preStart,int* preEnd,int* midStart,int* midEnd)
{
	BTreeNode* root = new BTreeNode();
	root->value = preStart[0];
	root->m_left = nullptr;
	root->m_right = nullptr;
	if (preStart == preEnd || midStart == midEnd)
		return root;

	int* p = midStart;
	int leftLen = 0;
	while (*p != preStart[0])
	{
		++p;
		++leftLen;
	}
	if (leftLen > 0)
		root->m_left = constructCore(preStart + 1, preStart + leftLen, midStart, p - 1);
	if( leftLen < preEnd-preStart)//--大于等于数组长度表示没有右子树
		root->m_right = constructCore(preStart + leftLen + 1, preEnd, p + 1, midEnd);

	return root;
}

BTreeNode* constructBTree(int* pre, int* mid, int length)
{
	return constructCore(pre,pre+length-1,mid,mid+length-1);
}

void printPreOrder(BTreeNode* bTree)
{
	if (bTree == nullptr)
		return;
	cout << " " << bTree->value;
	printPreOrder(bTree->m_left);
	printPreOrder(bTree->m_right);
}

void printInOrder(BTreeNode* bTree)
{
	if (bTree == nullptr)
		return;
	printInOrder(bTree->m_left);
	cout << " " << bTree->value;
	printInOrder(bTree->m_right);
}

void printPostOrder(BTreeNode* bTree)
{
	if (bTree == nullptr)
		return;
	printPostOrder(bTree->m_left);
	printPostOrder(bTree->m_right);
	cout << " " << bTree->value;
}

//--层次遍历二叉树
void printLevelOrder(BTreeNode* bTree)
{
	if (bTree == nullptr)
		return;

	deque<BTreeNode*> myDeque;
	myDeque.push_back(bTree);
	BTreeNode* tag = new BTreeNode;
	myDeque.push_back(tag);

	while (!myDeque.empty())
	{
		bTree = myDeque.front();
		if (bTree == tag)
		{
			if (myDeque.size() == 1)
				break;
			cout << endl;
			myDeque.pop_front();
			myDeque.push_back(tag);
			continue;
		}

		cout << " " << myDeque.front()->value;
		if (bTree->m_left)
			myDeque.push_back(bTree->m_left);
		if (bTree->m_right)
			myDeque.push_back(bTree->m_right);
		myDeque.pop_front();
	}
}

BTreeNode* makeTreePreOrder()
{
	cout <<endl<< "input root num:" << endl;
	int num = 0;
	cin >> num;
	BTreeNode* root = nullptr;
	if (num != 0)
	{
		root = new BTreeNode();
		root->value = num;
		root->m_left = makeTreePreOrder();
		root->m_right = makeTreePreOrder();
	}
	return root;
}

void mirrorTree(BTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;
	if (pRoot->m_left == nullptr && pRoot->m_right == nullptr)
		return;
	BTreeNode* pTemp;
	pTemp = pRoot->m_left;
	pRoot->m_left = pRoot->m_right;
	pRoot->m_right = pTemp;

	if (pRoot->m_left != nullptr)
		mirrorTree(pRoot->m_left);

	if (pRoot->m_right != nullptr)
		mirrorTree(pRoot->m_right);
}

int main()
{
	//--已知前序+中序-> 输出后序
	int pre[] = {1,2,4,7,3,5,6,8};
	int mid[] = {4,7,2,1,5,3,8,6};

	BTreeNode* bTree = constructBTree(pre, mid, sizeof(pre)/sizeof(pre[0]) );
	printPostOrder(bTree);

	bTree = makeTreePreOrder();

	cout <<endl<< "pre:print" << endl;
	printPreOrder(bTree);
	cout << endl << "in:print" << endl;
	printInOrder(bTree);
	cout << endl << "post:print" << endl;
	printPostOrder(bTree);
	cout << endl << "level:print" << endl;
	printLevelOrder(bTree);

	mirrorTree(bTree);
	cout << endl << "after mirror" << endl;

	cout << endl << "pre:print" << endl;
	printPreOrder(bTree);
	cout << endl << "in:print" << endl;
	printInOrder(bTree);
	cout << endl << "post:print" << endl;
	printPostOrder(bTree);
	cout << endl << "level:print" << endl;
	printLevelOrder(bTree);

	getchar();
	getchar();
    return 0;
}

