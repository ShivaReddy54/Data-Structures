#include <bits/stdc++.h>

int stack[25], top = -1, i;

void push(char c);
void pop();

int main(){
	char s[25] = "Shiva";
	
	for (i=0;i<strlen(s);i++)
		push(s[i]);
		
	for(i=0;i<strlen(s);i++){
		pop();
	}
}

void push(char c){
	stack[++top] = c;
}

void pop(){
	if(top == -1){
		printf("\n");
	}
	else{
		printf("%c", stack[top--]);
	}
} 
