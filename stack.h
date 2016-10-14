#ifndef _STACK_H_
#define _STACK_H_

#include "square.h"


typedef FSquare Item;


FSquare GetEmptyFSquare(void);

class StackNode {
public:
	Item value;
	StackNode *next;

	StackNode(void);
	StackNode *GetNext(void);
	friend std::ostream& operator<<(std::ostream& os, const StackNode& node);
};

class Stack {
private:
	StackNode *top;
public:
	Stack(void);
	~Stack(void);

	void Push(Item value);
	Item Pop(void);
	Item Top(void);
	bool IsEmpty(void);
	size_t Depth(void);
	//void Print(void);
	friend std::ostream& operator<<(std::ostream& os,const Stack& stack);
};

#endif
