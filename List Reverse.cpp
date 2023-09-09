#include <bits/stdc++.h>
#define node struct NODE

node {
	int val;
	node* next;
} *head = NULL, *p,*temp, *current;

void insert(int n);
void reverse();
void display();

int main(){
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	
	display();
	
	reverse();
	display();
}

void reverse(){
	if(head == NULL)
		printf("list is empty\n");
	else{
		node *prev, *temp, *next;
		prev = (node*)malloc(sizeof(node));
		prev = NULL;
		
		temp = (node*)malloc(sizeof(node));
		temp = head;
		
		next = (node*)malloc(sizeof(node));
		
		while(temp != NULL){
			next = temp->next;
			temp->next = prev;
			prev = temp;
			temp = next;
		}
		head = prev;
	}
}

void insert(int n){
	p = (node*)malloc(sizeof(node));
	p->val = n;
	if (head == NULL){
		p->next = NULL;
		head = p;
	}
	else{
		p->next = head;
		head = p;
	}
}

void display(){
	if(head == NULL)
		printf("List is empty\n");
	else{
		temp = (node*)malloc(sizeof(node));
		temp = head;
		
		while(temp != NULL){
			printf("%d ", temp->val);
			temp = temp->next;
		}
		printf("\n");
	}
}
