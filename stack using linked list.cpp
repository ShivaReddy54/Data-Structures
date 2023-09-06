#include <bits/stdc++.h>

int stack[50], top = -1;

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
	if (top == 49)
		printf("Stack is full\n");
	else {
		int n;
		printf("Enter element: ");
		scanf("%d", &n);
		stack[++top] = n;
	}
}

void pop(){
	if (top == -1)
		printf("Stack is empty\n");
	else {
		printf("%d was deleted\n", stack[top--]);
	}
}


void peek(){
	if (top == -1)
		printf("Stack is empty\n");
	else {
		printf("%d is at top\n", stack[top]);
	}
}

void display(){
	if (top == -1)
		printf("Stack is empty\n");
	else {
		int i;
		for(i=top;i>=0;i--){
			printf("%d ", stack[i]);
		}
		printf("\n");
	}
}
