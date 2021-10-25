//AC
//BOJ 1991 트리 순회
#include <stdio.h>
#include <stdlib.h>
typedef struct tree_type * tree_ptr;
struct tree_type{
	tree_ptr left;
	tree_ptr right;
	char data;
};

tree_ptr create_node(char a);
void preorder(tree_ptr ptr);
void inorder(tree_ptr ptr);
void postorder(tree_ptr ptr);
int main(){
	tree_ptr tree[26];
	int n, i, j;
	char arr[27][2];
	char x,y,z;
	scanf("%d\n", &n);
	for(i=0; i<n; i++){
		scanf(" %c %c %c",&x,&y,&z);
		arr[i][0] = y;
		arr[i][1] = z;
		tree[i] = create_node(x);
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(arr[i][0] == tree[j]->data) 
				tree[i]->left = tree[j];
			if(arr[i][1] == tree[j]->data) 	
				tree[i]->right = tree[j];
		}
	}
	preorder(tree[0]);
	printf("\n");
	inorder(tree[0]);
	printf("\n");
	postorder(tree[0]);
	
}
tree_ptr create_node(char a){
	tree_ptr node;
	node = (tree_ptr)malloc(sizeof(struct tree_type));
	node->data = a;
	node->left = NULL;
	node->right= NULL;
	return node;
}
void preorder(tree_ptr ptr){
	if(ptr){
		printf("%c", ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
	else 	return;
}
void inorder(tree_ptr ptr){
	if(ptr){
		inorder(ptr->left);
		printf("%c", ptr->data);
		inorder(ptr->right);
	}
	else 	return;
}
void postorder(tree_ptr ptr){
	if(ptr){
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%c", ptr->data);
	}
	else 	return;
}
