#pragma once
#include<vector>
using namespace std;
class SkipNode
{
public:
	SkipNode(int m_value = INT_MIN) 
		:value(m_value)
		,up(nullptr)
		,down(nullptr)
		,next(nullptr){}
	int value;
	SkipNode* up;
	SkipNode* down;
	SkipNode* next;
};

