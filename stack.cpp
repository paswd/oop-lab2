#include "stack.h"
#include "square.h"


FSquare GetEmptyFSquare(void)
{
	Position empty_pos;
	empty_pos.x = 0;
	empty_pos.y = 0;
	FSquare *empty_href = new FSquare(empty_pos, -1.0);
	FSquare empty = *empty_href;
	delete empty_href;
	return empty;
}

StackNode::StackNode(void)
{
	this->value = GetEmptyFSquare();
	this->next = NULL;
}

StackNode *StackNode::GetNext(void)
{
	return this->next;
}

std::ostream& operator<<(std::ostream& os, const StackNode& node)
{
	os << node.value;
	return os;
}


Stack::Stack(void)
{
	this->top = NULL;
}

Stack::~Stack(void)
{
	StackNode *node_del = this->top;
	while (node_del) {
		StackNode *tmp = node_del->next;
		delete node_del;
		node_del = tmp;
	}
}


void Stack::Push(Item value)
{
	StackNode *nw = new StackNode();
	nw->value = value;
	nw->next = this->top;
	this->top = nw;
}

Item Stack::Pop(void)
{
	if (this->IsEmpty()) {
		printf("Stack is empty\n");
		return GetEmptyFSquare();
	}
	Item result = this->top->value;
	StackNode *node_del = this->top;
	this->top = this->top->next;
	delete node_del;
	return result;
}

Item Stack::Top(void)
{
	if (this->IsEmpty())
		return GetEmptyFSquare();
	return this->top->value;
}

bool Stack::IsEmpty(void)
{
	if (this->top == NULL)
		return true;
	return false;
}

size_t Stack::Depth(void)
{
	if (this->IsEmpty())
		return 0;

	Item value = this->Pop();
	int res = this->Depth();
	this->Push(value);
	return res + 1;
}

/*void Stack::Print(void)
{
	if (this->IsEmpty())
		return;
	Item value = this->Pop();
	this->Print();
	value.Print();
	this->Push(value);
}*/

std::ostream& operator<<(std::ostream& os,const Stack& stack)
{
	//os << "Test" << std::endl;
	StackNode *ths = stack.top;
	size_t cnt = 0;
	while (ths != NULL) {
		if (cnt > 0) {
			std::cout << "-------------------------------" << std::endl;
		}
		os << *ths;
		ths = ths->GetNext();
		cnt++;
	}
	return os;
}

