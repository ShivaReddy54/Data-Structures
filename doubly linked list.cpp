#include <bits/stdc++.h>
#define node struct NODE

node {
	int data;
	node * prev, *next;
}*head = NULL, *tail = NULL, *p, *q, *temp;

void create();
void insertbeg();
void insertpos();
void insertend();
void deletebeg();
void deletepos();
void deleteend();
void display();

int main(){
	int ch;
	do{
		printf("1.create\n2.insertbeg\n3.insertpos\n4.insertend\n");
		printf("5.deletebeg\n6.deletepos\n7.deleteend\n8.display\n");
		scanf("%d", &ch);
		
		switch(ch){
			case 1: create(); break;
			case 2: insertbeg(); break;
			case 3: insertpos(); break;
			case 4: insertend(); break;
			case 5: deletebeg(); break;
			case 6: deletepos(); break;
			case 7: deleteend(); break;
			case 8: display(); break;
		}
	}while(ch <= 8);
}

void create(){
	int n;
	printf("Enter data: ");
	scanf("%d", &n);
	
	p = (node *)malloc(sizeof(node));
	p->data = n;
	p->next = NULL;
	p->prev = NULL;
	head = tail = p;
}

void insertbeg(){
	if(head == NULL)
		create();
	else{
		int n;
		printf("Enter data: ");
		scanf("%d", &n);
		
		p = (node *)malloc(sizeof(node));
		p->data = n;
		p->prev = NULL;
		
		p->next = head;
		head->prev = p;
		head = p;
	}
}

void insertpos(){
	if(head == NULL)
		create();
	else {
		int n, pos, i;
		printf("Enter data: ");
		scanf("%d", &n);
		printf("Enter position: ");
		scanf("%d", &pos);
		
		p = (node *)malloc(sizeof(node));
		p->data = n;
		
		temp = (node*)malloc(sizeof(node));
		temp = head;
		for(i=1;i<pos-1;i++){
			temp = temp->next;
		}
		
		if(temp->next != NULL){
			p->next = temp->next;
			temp->next->prev = p;
			temp->next = p;
			p->prev = temp;
		}
		else {
			insertend();
		}
	}
}

void insertend(){
	if(head == NULL)
		create();
	else{
		int n;
		printf("Enter data: ");
		scanf("%d", &n);
		
		p = (node*)malloc(sizeof(node));
		p->data = n;
		p->next = NULL;
		
		tail->next = p;
		p->prev = tail;
		tail = p; 		
	}
}

void deletebeg(){
	if(head == NULL)
		printf("list is empty\n");
	else {
		p = (node*)malloc(sizeof(node));
		p = head;
		
		if(head == tail){
			printf("%d was deleted\n", p->data);
			free(p);
			head = tail = NULL;
		}
		else {
			head = head->next;
			head->prev = NULL;
			printf("%d was deleted\n", p->data);
			free(p);
		}
	}
}

void deletepos(){
	if(head == NULL)
		printf("list is empty\n");
	else {
		p = (node*)malloc(sizeof(node));
		p = head;
		
		int pos,i;
		printf("Enter position: ");
		scanf("%d", &pos);
		
		if(head == tail){
			printf("%d was deleted\n", p->data);
			free(p);
			head = tail = NULL;
		}
		else if(pos == 1){
			deletebeg();
		}
		else{
			
			for(i=1;i<pos;i++){
				p = p->next;
			}
			
			if(p->next != NULL){
				p->next->prev = p->prev;
				p->prev->next = p->next;
				printf("%d was deletd\n", p->data);
				free(p);
			}
			else {
				deleteend();
			}
		}	
	}
}

void deleteend(){
	if(head == NULL)
		printf("list is empty\n");
	else {
		p = (node*)malloc(sizeof(node));
		p = tail;
		
		if(head == tail){
			printf("%d was deleted\n", p->data);
			free(p);
			head = tail = NULL;
		}
		else{
			tail = tail->prev;
			tail->next = NULL;
			printf("%d was deleted\n", p->data);
			free(p);
		}
	}
}

void display(){
	if(head == NULL)
		printf("list is empty\n");
	else{
		p = (node*)malloc(sizeof(node));
		p = head;
		
		printf("from head to tail: ");
		while(p != NULL){
			printf("%d ",p->data);
			p = p->next;
		}
		printf("\n");
		
		
	 	temp = (node*)malloc(sizeof(node));
		temp = tail;
		
		printf("from tail to head: ");
		while(temp != NULL){
			printf("%d ", temp->data);
			temp = temp->prev;
		}
		printf("\n"); 
	}
}
