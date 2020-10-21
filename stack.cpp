#include <iostream>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x) {
	if(top == MAX_SIZE -1) {
		printf("Overflow error\n");
		return;
	}
	A[++top] = x;
}

void Pop() {
	if(top == -1) {
		printf("No element to pop\n");
	}
	top--;
}

int Top() {
	return A[top];
}

void Print() {
	printf("Stack: ");
	for(int i = 0;i<=top;i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main() {
	Push(1);
	Push(3);
	Push(5);
	Print();
	Pop();
	Print();
	return 0;
}
