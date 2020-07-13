#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 10          //The MAXSIZE of List is 10.
typedef int ElementType;
typedef int Position;
//define bool
typedef int bool;
#define true 1
#define false 0

typedef struct LNode* List;
typedef struct LNode {
    ElementType data[MAXSIZE];
    int Size;
}LNode;

//Create a new List.
List MakeList() {
    List L = (List)malloc(sizeof(LNode));
    L->Size = -1;
    return L;
}

//Set data in List.
List Set(ElementType* Data, int size) {
    List L = MakeList();

    if (size < 0 || size >MAXSIZE) {
        printf("Your enter data's size is error!(Set) \n");
        printf("Return a empty List!\n ");
        return L;
    }
	int i = 0;
    for (; i < size; i++) {
        L->data[i] = Data[i];
    }
    L->Size = size;
    return L;
}

//Add a new data at the last if a List.
bool Add(List L, ElementType X) {
    if (L->Size >= MAXSIZE) {
        printf("Your List is full!(Add) \n");
        printf("Will return the old List!\n");
        return false;
    }
    L->Size++;
    L->data[L->Size - 1] = X;
    return true;
}

//Find the position of node which data is K.
//And return the Subscript of the Node.
Position Find(List L, ElementType K) {
    if (L->Size == -1) {
        printf("Your List is empty!(Find)\n");
        return -1;
    }
	int i = 0;
    for(; i < L->Size; i++) {
        if (L->data[i] == K) {
            return i + 1;
        }
    }
    printf("Your List don't have %d.(Find)\n", K);
    return -1;
}

//Insert a node at jth Node.
//(if you want to insert at the first node, j = 1.)
bool Insert(List L, Position j, ElementType X) {
    if (L->Size >= MAXSIZE) {
        printf("Your List is full! \n");
        return false;
    }
    if (j < 0 || j > L->Size + 1) {
        printf("Your j is ERROR! \n");
        return false;
    }
	int i = L->Size;
    for (; i >= j; i--) {
        L->data[i] = L->data[i - 1];
    }
    L->data[j - 1] = X;
    L->Size++;

    return true;
}

//Delete the Kth Node.
//(if you wanna delete the first Node, K = 1.)
bool Delete(List L, Position K) {
    if (K <= 0 || K > L->Size) {
        printf("Your enter Position is error!(Delete) \n");
        return false;
    }
	int i = K - 1;
    for (; i < L->Size - 1; i++) {
        L->data[i] = L->data[i + 1];
    }
    L->data[L->Size - 1] = 0;
    L->Size--;
    return true;
}

//Display a List.
void Display(List L) {
    if (L->Size == -1) {
        printf("Your List is empty!(Display) \n");
        return;
    }

    printf("\n");
	int i = 0;
    for (; i < L->Size; i++) {
        printf("%d ", L->data[i]);
    }
    printf("The List is over! \n");
    return;
}

int main() {
    List L = MakeList();
    Display(L);
    int* d = (int*)malloc(10 * sizeof(int));
	int i = 0;
    for (; i < 10; i++) {
        d[i] = i;
    }
    L = Set(d, 10);
    Display(L);
    Add(L, 5);
    Display(L);
    if (Delete(L, 5)) { printf("Delete is successful!"); Display(L); }
    if (Insert(L, 3, 7)) { printf("Insert is successful!"); Display(L); }

    return 0;
}

