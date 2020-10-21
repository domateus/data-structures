#include <iostream>

struct Node {
	int data;
	Node* next;
	Node* prev;
};

Node* getNewNode(int x) {
	Node* newNode = new Node();
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void InsertAtHead(int x, Node** head) {
	Node* temp = getNewNode(x);
	if(*head == NULL) {
		*head = temp;
		return;
	}
	(*head)->prev = temp;
	temp->next = *head;
	*head = temp;	
}

void Print(Node** head) {
	Node* temp = *head;
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void ReversePrint(Node** head) {
	Node* temp = *head;
	if(temp == NULL) return;

	while(temp->next != NULL) temp = temp->next;

	printf("Reverse: ");
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}


int main() {
	Node* head = NULL;
	InsertAtHead(5, &head);
	InsertAtHead(6, &head);
	InsertAtHead(3, &head);
	Print(&head);
	ReversePrint(&head);

	return 0;
}
