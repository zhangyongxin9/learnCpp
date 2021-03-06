// Test01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct LinkNode
{
	int value;
	LinkNode* m_next;
};

void reversePrintLinklist(LinkNode* pHead)
{
	if (pHead != nullptr)
	{
		reversePrintLinklist(pHead->m_next);
		cout << " " << pHead->value;
	}
}

void PrintLinklist(LinkNode* pHead)
{
	if (pHead != nullptr)
	{
		cout << " " << pHead->value;
		PrintLinklist(pHead->m_next);
	}
}

void PrintKthNodeToTail(LinkNode* pHead,unsigned int k)
{
	if (pHead == nullptr || k == 0)
		return;
	LinkNode* pPre = pHead;
	LinkNode* pBehind = pHead;

	for (int i = 0; i < k-1; ++i)
	{
		pBehind = pBehind->m_next;
		if (!pBehind)
		{
			cout << "k is too big" << endl;
			return;
		}
	}

	while (pBehind->m_next)
	{
		pPre = pPre->m_next;
		pBehind = pBehind->m_next;
	}
	cout << pPre->value;
}

LinkNode* reverseList(LinkNode* pHead)
{
	LinkNode* pRet = nullptr;
	LinkNode* pNode = pHead;
	LinkNode* pPre = nullptr;
	LinkNode* pNext = pNode;

	while ( pNode)
	{
		pNext = pNode->m_next;
		if (!pNext)
			pRet = pNode;
		pNode->m_next = pPre;

		pPre = pNode;
		pNode = pNext;
	}
	return pRet;

}
//--没有头节点创建！！
LinkNode* createListNoHeadNode()
{
	int value = 100;

	LinkNode* pHead = nullptr;
	LinkNode* pre = pHead;

	while (value != 0)
	{
		cout << endl<<"input next value with 0 end!" << endl;
		cin >> value;
		if (value != 0)
		{
			LinkNode* oneNode = new LinkNode;
			oneNode->value = value;
			oneNode->m_next = nullptr;
			if (!pHead)
			{
				pHead = oneNode;
				pre = oneNode;
			}
			else
			{
				pre->m_next = oneNode;
				pre = pre->m_next;
			}
		}
	}
	return pHead;
}

//a b 都是递增链表
LinkNode* mergeSortedList(LinkNode* pHeadA, LinkNode* pHeadB)
{
	LinkNode* pRet = pHeadA;
	if (pHeadA->value < pHeadB->value)
	{
		while (pHeadA)
		{
			while (pHeadA->m_next && pHeadA->m_next->value < pHeadB->value)
			{
				pHeadA = pHeadA->m_next;
			}
			LinkNode* pANext = pHeadA->m_next;
			pHeadA->m_next = pHeadB;
			while (pANext && pHeadB->m_next && pHeadB->m_next->value < pANext->value)
			{
				pHeadB = pHeadB->m_next;
			}
			LinkNode* pBNext = pHeadB->m_next;
			pHeadB->m_next = pANext;

			pHeadA = pANext;
			pHeadB = pBNext;
		}
	}
	else
	{

	}
	return pRet;
}

LinkNode* mergeSortedList2(LinkNode* pHeadA, LinkNode* pHeadB)
{
	if (!pHeadA)
		return pHeadB;
	if (!pHeadB)
		return pHeadA;

	LinkNode* pRet = nullptr; 
	if (pHeadA->value < pHeadB->value)
	{
		pRet = pHeadA;
		pRet->m_next = mergeSortedList2(pHeadA->m_next, pHeadB);
	}
	else
	{
		pRet = pHeadB;
		pRet->m_next = mergeSortedList2(pHeadA, pHeadB->m_next);
	}
	return pRet;
}

int main()
{
	int value = 100;

	LinkNode* pHeadA = createListNoHeadNode();
	cout << endl << "list A is:"<<endl;
	PrintLinklist(pHeadA);

	LinkNode* pHeadB = createListNoHeadNode();
	cout << endl << "list B is:" << endl;
	PrintLinklist(pHeadB);

	LinkNode* pHeadC = mergeSortedList2(pHeadA, pHeadB);
	cout << endl << "list C is:" << endl;
	PrintLinklist(pHeadC);

	//--pHead最好不要是第一个节点 否则容易搞混！！！
	//LinkNode* pHead = createListNoHeadNode();
	//
	//cout << "reverse print" << endl;
	//reversePrintLinklist(pHead );
	//
	//cout << endl<<"print" << endl;
	//PrintLinklist(pHead);
	//
	//int num;
	//cout << endl<<"input K:" << endl;
	//cin >> num;
	//cout << endl << "reverse K node is " << endl;
	//PrintKthNodeToTail(pHead, num);
	//
	//pHead = reverseList(pHead);
	//cout << endl<<"after reverseList " << endl;
	//PrintLinklist(pHead);

	getchar();
	return 0;
}

