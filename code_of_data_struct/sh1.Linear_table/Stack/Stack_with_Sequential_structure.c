#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;

//define bool
typedef int bool;
#define true 1
#define false 0

typedef struct SNode* Stack;
typedef struct SNode {
	ElementType data;
	Stack Next;
}SNode;

//Create a new Stack.
Stack MakeStack() {
	Stack S = (Stack)malloc(sizeof(SNode));
	S->Next = NULL;
	return S;
}

//Push a SNode in Stack.
void Push(Stack S, ElementType X) {
	Stack S1 = MakeStack();
	S1->data = X;
	S1->Next = S->Next;
	S->Next = S1->Next;
	return;
}

//Pop Stack and return the data of the top SNode.
//If your Stack is empty or NULL. It will return 0.
ElementType Pop(Stack S) {
	if (S == NULL) {
		printf("Your Stack is NULL! \n");
		return 0;
	}
	if (S->Next == NULL) {
		printf("Your Stack is empty! \n");
		return 0;
	}
	Stack S1 = S->Next;
	S->Next = S1->Next;
	free(S1);
	return true;
}

//Set data in a  new Stack and return it.
//0th is the top of Stack.
Stack Set(ElementType* d, int size) {
	Stack S = MakeStack();
	int i = size - 1;
	for (; i >= 0; i--) {
		Push(S, d[i]);
	}
	return S;
}

//

int main() {
	return 0;
}