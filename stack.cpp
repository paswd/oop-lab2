#include "stack.h"
#include "square.h"
//#include "basfunc.h"


/*struct _stack {
	StackNode *top;
};


void stack_push(Stack *stack, Item value)
{
	
}

Item stack_pop(Stack *stack)
{
	
}

Item stack_top(Stack *stack)
{
	
}

/*void stack_print_correct(Stack *stack)
{
	StackNode *ths = stack->first;
	while (ths) {
		printf("%lld ", ths->value);
		ths = ths->next;
	}
	printf("\n");
}*/

/*bool stack_is_empty(Stack *stack)
{
	if (stack->top == NULL)
		return true;
	return false;
}

int stack_depth(Stack *stack)
{

}
void stack_print(Stack *stack)
{
	if (stack_is_empty(stack))
		return;
	Item value = stack_pop(stack);
	stack_print(stack);
	stack_push(stack, value);
	printf("%lld ", value);
}*/

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

Stack::Stack(void)
{
	this->top = NULL;
}

Stack::~Stack(void)
{
	StackNode *node_del = this->top;
	while (node_del) {
		StackNode *tmp = node_del->next;
		free(node_del);
		node_del = tmp;
	}
}


void Stack::Push(Item value)
{
	StackNode *nw = new StackNode;
	nw->value = value;
	nw->next = this->top;
	this->top = nw;
}

Item Stack::Pop(void)
{
	if (this->IsEmpty()) {
		printf("Stack is empty\n");
		return GetEmptyFSquare(void);
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
		return GetEmptyFSquare(void);
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

void Stack::Print(void)
{
	if (this->IsEmpty())
		return;
	Item value = this->Pop();
	this->Print();
	this->Push(value);
	value.Print();
}

