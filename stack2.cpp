#include<iostream>

struct Node {
	int data;
	Node* next;
};

Node* top = NULL;

void Push(int x) {
	Node* temp = new Node();
	temp->data = x;
	temp->next = top;
	top = temp;
}

void Pop() {
	Node* temp; 
	if(top == NULL) return;
	temp = top;
	top = top->next;
	temp->next = NULL;
	delete temp;
}

void Print() {
	Node* temp = top;
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	Push(2);
	Push(5);
	Push(8);
	Push(9);
	Pop();
	Print();
	return 0;
}
