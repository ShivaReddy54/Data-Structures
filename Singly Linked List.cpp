#include <bits/stdc++.h>
#define node struct NODE

node {
	int data;
	node * next;
}*head = NULL, *tail = NULL, *p, *temp, *q;

int n;

void create(int n);
void insertbeg(int n);
void insertend(int n);
void insertpos(int n, int pos);
void display();
void deletebeg();
void deletepos(int n);
void deleteend();
int search(int n);

int main(){
			int ch;

	do{
		printf("1.Create\n2.insert at beg\n3.insert at pos\n4.insert at end\n");
		printf("5.delete at beg\n6.delete at pos\n7.delete at end\n");
		printf("8.display\n9.search\n");
		
		scanf("%d", &ch);
		
		switch(ch){
			case 1: create(5); break;
			case 2: insertbeg(10); break;
			case 3: insertpos(15, 1); break;
			case 4: insertend(25); break;
			case 5: deletebeg(); break;
			case 6: deletepos(1); break;
			case 7: deleteend(); break;
			case 8: display(); break;
			case 9: search(10); break;
		}
	}while( ch <= 9);
}

void create(int n){
	p = (node *)malloc(sizeof(node));
	p->data = n;
	p->next = NULL;
	head = tail = p;
}

void insertbeg(int n){
	if(head == NULL)
		create(n);
	else {
		p = (node *)malloc(sizeof(node));
		p->data = n;
		p->next = head;
		head = p;
	}
}

void insertend(int n){
	if(head == NULL)
		create(n);
	else {
		p = (node *)malloc(sizeof(node));
		p->data = n;
		p->next = NULL;
		
		tail->next = p;
		tail = p;
	}
}

void insertpos(int n, int pos){
	if (head == NULL)
		create(n);
	else {
		p = (node *)malloc(sizeof(node));
		p->data = n;
		
		temp = (node*)malloc(sizeof(node));
		temp = head;
		int i;
		for(i=1;i<pos;i++){
			temp = temp->next;
		}
		p->next = temp->next;
		temp->next = p;
	}
}

void display(){
	if(head == NULL)
		printf("list is empty\n");
	else {
		p = (node*)malloc(sizeof(node));
		p = head;
		
		while(p != NULL){
			printf("%d ", p->data);
			p = p->next;
		}
		printf("\n");
	}
}

void deletebeg(){
	if(head == NULL)
		printf("List is empty\n");
	else {
		p = (node *)malloc(sizeof(node));
		p = head;
		printf("%d was deleted\n", p->data);
		head = head->next;
		free(p);
	}
}

void deletepos(int pos){
	if(head == NULL)
		printf("List is empty\n");
	else {
		p = (node*)malloc(sizeof(node));
		q = (node*)malloc(sizeof(node));
		
		p = head;
		q = head->next;
		int i;
		
		for(i=1;i<pos-1;i++){
			p = p->next;
			q = q->next;
		}
		p->next = q->next;
		printf("%d was deleted\n", q->data);
		free(q);
	}
}

void deleteend(){
	if(head == NULL)
		printf("List is empty\n");
	else {
		p = (node*)malloc(sizeof(node));
		q = (node*)malloc(sizeof(node));
		
		p = head;
		q = head->next;
		
		while(q->next != NULL){
			p = p->next;
			q = q->next;
		}
		
		p->next = NULL;
		printf("%d was deleted\n", q->data);
		free(q);
	}
}

int search(int n){
	if(head == NULL)
		printf("List is empty\n");
	else{
		p = (node*)malloc(sizeof(node));
		p = head;
		while(p != NULL){
			if (n == p->data){
				printf("%d was there\n", n);
				return 0;
			}
			p = p->next;
		}
		printf("%d was not there\n", n);
	}
}
