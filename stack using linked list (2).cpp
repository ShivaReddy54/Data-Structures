#include <bits/stdc++.h>
#define node struct NODE

node {
	int data;
	node * next;
}*top = NULL, *p;

void push();
void pop();
void peek();
void display();

int main(){
	int ch;
	do {
		printf("1.Push\n2.pop\n3.peek\n4.display\n");
		scanf("%d", &ch);
		
		switch(ch){
			case 1: push(); break;
			case 2: pop(); break;
			case 3: peek(); break;
			case 4: display(); break;
		}
	}while(ch <= 4);
}

void push(){
	int n;
	printf("enter data: ");
	scanf("%d", &n);
	
	p = (node*)malloc(sizeof(node));
	p->data = n;
	
	if (top == NULL){
		p->next = NULL;
		top = p;
	}
	else {
		p->next = top;
		top = p;
	}
}

void pop(){
	if (top == NULL)
		printf("stack is empty\n");
	else {
		p = (node*)malloc(sizeof(node));
		p = top;
		top = top->next;
		printf("%d was deleted\n", p->data);
		free(p);
	}
}

void peek(){
	if (top == NULL)
		printf("stack is empty\n");
	else {
		p = (node*)malloc(sizeof(node));
		p = top;
		printf("%d is at top\n", p->data);
	}
}

void display(){
	if (top == NULL)
		printf("stack is empty\n");
	else {
		p = (node*)malloc(sizeof(node));
		p = top;
		
		while(p != NULL){
			printf("%d ", p->data);
			p = p->next;
		}
	}
}
