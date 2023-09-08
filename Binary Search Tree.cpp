#include <bits/stdc++.h>
typedef struct NODE {
    int data;
    struct NODE *left, *right;
} node;

node* create(int n);
node* insert(node* root, int n);
void inorder(node* root);
void preorder(node* root);
void postorder(node* root);
int minvalue(node* root);
int maxvalue(node* root);
int height(node* root);
int getmax(int a, int b){
	return (a > b) ? a : b;
}
int search(node* root, int n);
node* deletenode(node* root, int n);

int main(){
    node* root = NULL;
    int ch, i, n, res;
    do{
    	printf("1.insert\n2.Inorder\n3.preorder\n4.postorder\n5.min value\n6.maxvalue\n");
    	printf("7.height\n8.search\n9.delete\n");
    	scanf("%d", &ch);
    	
    	switch(ch){
    		case 1:
    			printf("Enter data: ");
    			scanf("%d", &n);
    			root = insert(root, n);
    			break;
    		
    		case 2:
    			inorder(root);
    			printf("\n");
    			break;
    		
    		case 3:
    			preorder(root);
    			printf("\n");
    			break;
    		
    		case 4:
    			postorder(root);
    			printf("\n");
    			break;
    		
    		case 5:
    			printf("min : %d \n", minvalue(root));
    			break;
    		
    		case 6:
    			printf("max: %d \n", maxvalue(root));
    			break;
    		
    		case 7:
    			printf("Height: %d\n", height(root));
				break;
				
			case 8:
				res = search(root, 10);
			    if(res == 1)
			    	printf("value is present\n");
			    else
			    	printf("Value is not present\n");
			    break;
			    
			case 9:
				printf("Enter data: ");
    			scanf("%d", &n);
    			root = deletenode(root,n);
    			break;
		}
	}while(ch <= 9);
}

node* create(int n){
    node* p = (node*)malloc(sizeof(node));
    p->data = n;
    p->right = NULL;
    p->left = NULL;

    return p;
}

node* insert(node* root, int n){
    if(root == NULL)
        return create(n);
    else{
        if(n <= root->data)
            root->left = insert(root->left, n);
        else
            root->right = insert(root->right, n);    
    }
    return root;
}

void inorder(node* root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int minvalue(node* root){
    if(root == NULL)
        return -1; 
    
    if(root->left == NULL)
        return root->data;
    
    return minvalue(root->left);
}

int maxvalue(node* root){
    if(root == NULL)
        return -1;
    
    if(root->right == NULL)
        return root->data;
    
    return maxvalue(root->right);
}

int height(node* root){
	if(root == NULL)
		return -1;
	else{
		return getmax(height(root->left), height(root->right)) + 1;
	}
}

int search(node* root, int n){
	if(root == NULL)
		return 0;
	else{
		if (n == root->data)
			return 1;
		else if(n > root->data)
			search(root->right, n);
		else if(n < root->data)
			search(root->left, n);
	}
}

node* deletenode(node* root, int n){
	if (root == NULL)
		return NULL;
	else{
		if (n == root->data){
			if(root->left == NULL and root->right == NULL)
				root = NULL;
			else if(root->left == NULL)
				root = root->right;
			else if(root->right == NULL)
				root = root->left;
			else{
				int max = minvalue(root->left);
				root->data = max;
				root->left = deletenode(root->left, max);
			}
		}
		else if(n > root->data)
			root->right = deletenode(root->right, n);
		else
			root->left = deletenode(root->left, n);
		
		return root;
	}
}
