#include <bits/stdc++.h>

int stack[25], top = -1;

void push();
void pop();
int checkparan(char s[], int l);

int main(){
	char s[25] = "[()()]";
	int l = strlen(s);
	
	int res = checkparan(s, l);
	if(res == 0)
		printf("Expression is balanced");
	else
		printf("Expression is not balanced");
}

void push(char c){
	stack[++top] = c;
}

void pop(){
	stack[top--];
}

int checkparan(char s[], int l){
	int i;
	
	for(i=0;i<l;i++){
		if(s[i] == '(' or s[i] == '[' or s[i] == '{'){
			push(s[i]);
		}
		else if (s[i] == ')' or s[i] == ']' or s[i] == '}'){
			if (top == -1){
				return -1;
			}
			else{
				pop();
			}
		}
	}
	
	if(top == -1){
		return 0;
	}
	else{
		return -1;
	}
}
