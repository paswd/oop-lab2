#include <stdio.h>
#include "figure.h"
#include "stack.h"
#include "square.h"

int main(void)
{
	Stack *stack = new Stack;
	printf("-------------------------------------------\n");
	printf("Commands:\n");
	printf("a <value> - push to stack\n");
	printf("d - pop from stack and print popped item\n");
	printf("p - print stack\n");
	printf("q - exit\n");
	printf("-------------------------------------------\n");
	//int cnt = 0;
	while (true) {
		//printf("%d\n", cnt);
		//cnt++;
		char cmd;
		Item value = GetEmptyFSquare();
		bool is_finished = false;
		scanf("%c", &cmd);
		switch (cmd) {
			case 'q':
				is_finished = true;
				break;
			case 'a':
				value = (Item) FSquare(std::cin);
				stack->Push(value);
				break;
			case 'd':
				value = stack->Pop();
				if (value.GetLength() >= 0.0)
					value.Print();
				break;
			case 'p':
				stack->Print();
				break;
			case '\n':
				break;
			default:
				printf("Invalid command `%c`\n", cmd);
				break;
		}
		if (is_finished) break;
	}
	printf("Goodbye!\n");

	delete stack;

	return 0;
}
