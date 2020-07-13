#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef int Position;
//define bool
typedef int bool;
#define true 1
#define false 0


typedef struct LNode* List;
typedef struct LNode {
	ElementType data;
	List Next;
}LNode;				//This of edition List has head LNode.

//Create a new List.
List MakeList() {
	List L = (List)malloc(sizeof(LNode));
	L->Next = NULL;
	return L;
}

//Attach a new Node at the last of the List.
//If L is NULL, it will return a new List which only have one Node without head LNode.
List Attach(List L, ElementType X) {
	if (L == NULL) {
		List L = MakeList();
		List L1 = MakeList();
		L1->data = X;
		L->Next = L1;
		return L;
	}
	List P = L;
	while (P->Next != NULL) {
		P = P->Next;
	}
	List L1 = MakeList();
	L1->data = X;
	P->Next = L1;
	return L;
}

//Set data in a new List.
List Set(ElementType* d, int size) {
	List L = MakeList();
	if (size <= 0) {
		size < 0 ?
			printf("Your data's size is ERROR! \n") :
			printf("Your data's size is zero! \n");
		printf("Will return a empty List! \n");
		return L;
	}
	int i = 0;
	for (; i < size; i++) {
		L = Attach(L, d[i]);
	}
	return L;
}

//Return the length of List.
//Return -1 is mean L is NULL.In another word L don't have any LNode even the head LNode.
int Length(List L) {
	if (L == NULL) { return -1; }
	int num = 0;
	List P = L;
	while (P->Next != NULL) {
		P = P->Next;
		num++;
	}
	return num;
}

//Search the data of Kth LNode.
//If the search successes it will return the data of LNode.
//If the search fails it will return 0!
ElementType Search(List L, Position K) {
	if (L == NULL) {
		printf("L is NULL!(Search) \nWill return 0! \n");
		return 0;
	}
	int i = 0;
	List P = L;
	while (i < K && P->Next != NULL) {
		P = P->Next;
		i++;
	}
	if (i == K)return P->data;
	else {
		printf("Can't Search! \nWill return 0! \n");
		return 0;
	}
}

//Find X in the List.And return the Position of the LNode.
//If the find fails it will return ERROR(-1).
Position Find(List L, ElementType X) {
	if (L == NULL) {
		printf("Your List is NULL!(Find) \n");
		return -1;
	}
	if (L->Next == NULL) {
		printf("Your List only has head LNode!(Find) \n");
		return -1;
	}

	List P = L;
	int ans = 0;
	while (P->Next != NULL && P->data != X) {
		P = P->Next;
		ans++;
	}
	if (P->data != X) {
		printf("%d is not in the List!(Find) \n", X);
		return -1;
	}
	printf("%d is at the %dth LNode of the List!(Find) \n", X, ans);
	return ans;
}

//Delete the Kth LNode of the List.
bool Delete(List L, Position K) {
	if (L == NULL) {
		printf("Your List is NULL!(Delete) \n");
		return false;
	}
	if (L->Next == NULL) {
		printf("Your List is empty!(Delete) \n");
		return false;
	}
	if (K <= 0) {
		printf("Your enter K is ERROR!(Delete) \n");
		return false;
	}

	List Pre = L;
	List P = L;
	P = P->Next;
	int i = 1;
	while (P->Next != NULL && i < K) {
		P = P->Next;
		Pre = Pre->Next;
		i++;
	}
	if (i == K) {
		Pre->Next = P->Next;
		free(P);
		return true;
	}
	printf("The number of LNode is less than %d!(Delete) \n", K);
	return false;
}

//Display the List.
void Display(List L) {
	if (L == NULL) {
		printf("Your List is NULL!(Display) \n");
		return;
	}
	if (L->Next == NULL) {
		printf("Your List is empty!(Display) \n");
		return;
	}

	List P = L;
	int i = 0;
	while (P->Next != NULL) {
		P = P->Next;
		printf("%d ", P->data);
		i++;
	}
	printf("\nThe number of LNodes is %d! ", i);
	printf("\nThis List is over! \n");
	return;
}


int main() {
	int* d = (int*)malloc(20);
	int i  = 0;
	for(; i<5; i++){
		d[i] = i;
	}
	List L = Set(d, 5);
	Delete(L, 5);
	Display(L);
	return 0;
}