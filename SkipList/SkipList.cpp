#include "stdafx.h"
#include "SkipList.h"
#include<iostream>
using namespace std;

bool SkipList::randomLevel()
{
	srand(unsigned(time(0)));
	int r = rand() % 2;
	if (r == 1) return true;
	return false;
}

void SkipList::Insert(int val)
{
	/* ��������Ͳ����Ԫ�� */
	SkipNode* cursor = head; // �����α�
	SkipNode* insertNode = nullptr; // ���������Ԫ�ؽڵ�
	while (cursor->down != nullptr)
		cursor = cursor->down;  // �ҵ���ײ�Ԫ�أ�L1�㣩
	SkipNode* current_head = cursor; // ������ײ�ͷ�ڵ��λ��
	while (cursor->next != nullptr)
	{
		if (val <= cursor->next->value && insertNode == nullptr)
		{
			insertNode = new SkipNode(val);
			insertNode->next = cursor->next;
			cursor->next = insertNode;
		}
		cursor = cursor->next;
	}
	if (cursor->next == nullptr && insertNode == nullptr)
	{
		insertNode = new SkipNode(val);
		cursor->next = insertNode;
	}
	/* ��ײ����Ԫ�ؽ��� */

	/* �ϲ����Ԫ�� */
	int cursorLevel = 1; // �α����ڲ���
	cursor = current_head; 
	while (randomLevel())
	{
		curLevel++; // ��ǰ���ڲ�����һ
		if (cursorLevel < curLevel)
		{
			cursorLevel++;
			if (head->up == nullptr)
			{
				SkipNode* new_head = new SkipNode();
				head->up = new_head;
				new_head->down = head;
			}
			cursor = cursor->up; // �α�����
		}
		SkipNode* new_insertNode = nullptr;
		while (cursor->next != nullptr)
		{
			if (val <= cursor->next->value && new_insertNode == nullptr)
			{
				new_insertNode = new SkipNode(val);
				new_insertNode->next = cursor->next;
				cursor->next = new_insertNode;
			}
			cursor = cursor->next;
		}
		if (cursor->next == nullptr)
		{
			new_insertNode = new SkipNode(val);
			cursor->next = new_insertNode;
		}

		while (insertNode->up != nullptr)
			insertNode = insertNode->up;

		insertNode->up = new_insertNode;
		new_insertNode->down = insertNode;
		head = head->up;
		cursor = head;
		
	}

}

void SkipList::Search(int val)
{
	bool isFound = false;
	while (head->up != nullptr)
		head = head->up;
	SkipNode* cursor = head;

	while (cursor->down != nullptr) 
	{ 
		while (cursor->next != nullptr) 
		{ 
			if (val < cursor->next->value)
			{ 
				break;
			}
			if (val == cursor->next->value)
			{
				isFound = true;
				cout << val << " is found..\n";
				return;
			}
			cursor = cursor->next;
		}
		cursor = cursor->down;
	}
	/* ���α굽��������һ��ʱ������ѭ��ʧЧ����ʼ�������*/
	while (cursor->next != nullptr)
	{ 
		if (val > cursor->next->value)
		{
			cursor = cursor->next; 
		}
		else if (val == cursor->next->value) 
		{
			isFound = true;
			cout << val << " is found..\n";
			return;
		}
		else if (val < cursor->next->value)
		{
			cout << val << " is not found..\n";
			return;
		}
	}
}

void SkipList::Print()
{
	
}
