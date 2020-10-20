#include<stdlib.h>
#include<stdio.h>

struct Node {
	int data;
	Node* next;
};

void RecursiveReverse(Node* p, Node** head) {
	if(p->next == NULL) {
		*head = p;
		return;
	}
	RecursiveReverse(p->next, head);
	p->next->next = p;
	p->next = NULL;
}

void RecursivePrint(Node* p) {
	if(p == NULL) return;
	RecursivePrint(p->next);
	printf("%d ", p->data);
}

Node* Reverse(Node** head) {
	Node *prev, *current, *next;
	current = *head;
	prev = NULL;
	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
	return *head;
}


void Delete(int n, Node** head) {
	Node* temp1 = *head;

	if(n==1) {
		*head = temp1->next;
		delete temp1;
		return;
	}

	for(int i = 0; i<n-2;i++) {
		temp1 = temp1->next;
	}

	Node* temp2 = temp1->next;
	temp1->next = temp2->next;
	delete temp2;
}

void InsertAnywhere(int data, int n, Node** head) {
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;
	if(n == 1) {
		temp1->next = *head;
		*head = temp1;
		return;
	}
	Node* temp2 = *head;
	for(int i = 0;i<n-2;i++) {
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

void Insert(Node** head, int x) {
	Node* temp = new Node();
	temp->data = x;
	temp->next = *head;
	*head = temp;
}

void Print(Node** head) {
	Node* temp = *head;
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


int main () {
	Node* head = NULL;
	InsertAnywhere(5,1, &head);
	InsertAnywhere(6,2, &head);
	InsertAnywhere(2,1, &head);
	InsertAnywhere(4,2, &head);
	Print(&head);
	Reverse(&head);
	Print(&head);
	RecursivePrint(head);
	printf("\nNow recursive revert\n");
	Print(&head);
	RecursiveReverse(head, &head);
	Print(&head);
}

