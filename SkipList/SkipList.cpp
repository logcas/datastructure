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
	/* 首先在最低层插入元素 */
	SkipNode* cursor = head; // 建立游标
	SkipNode* insertNode = nullptr; // 建立插入的元素节点
	while (cursor->down != nullptr)
		cursor = cursor->down;  // 找到最底层元素（L1层）
	SkipNode* current_head = cursor; // 保存最底层头节点的位置
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
	/* 最底层插入元素结束 */

	/* 上层插入元素 */
	int cursorLevel = 1; // 游标所在层数
	cursor = current_head; 
	while (randomLevel())
	{
		curLevel++; // 当前所在层数加一
		if (cursorLevel < curLevel)
		{
			cursorLevel++;
			if (head->up == nullptr)
			{
				SkipNode* new_head = new SkipNode();
				head->up = new_head;
				new_head->down = head;
			}
			cursor = cursor->up; // 游标上移
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
	/* 当游标到达最下面一层时，上面循环失效，开始下面遍历*/
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
