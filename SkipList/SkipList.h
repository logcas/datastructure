#pragma once
#include"SkipNode.h"
#include<random>
#include<ctime>

class SkipList
{
	int curLevel;
	SkipNode* head;
	bool randomLevel();

public:
	SkipList():curLevel(1){ head = new SkipNode();}
	~SkipList(){ delete head;}
	
	void Insert(int s);
	void Search(int s);
	void Print();
};

