//AC
//BOJ 5639 이진 검색 트리
//https://www.acmicpc.net/problem/5639 
#include <stdio.h>
#include <stdlib.h>
typedef struct tree_node *tree_ptr;
struct tree_node{
	int data;
	tree_ptr left;
	tree_ptr right;
};

void insert_BST(tree_ptr tree,int item);
void postorder(tree_ptr ptr);
void preorder(tree_ptr ptr);
int main(){
	tree_ptr tree = (tree_ptr)malloc(sizeof(struct tree_node));
	int n;
 	scanf("%d\n", &n);
 	tree->data = n;
 	tree->left = NULL;
 	tree->right = NULL;
 	while(scanf("%d\n", &n)!=EOF){
 		insert_BST(tree, n);
	 }
	postorder(tree);
	preorder(tree);
}
void insert_BST(tree_ptr tree,int item){
	tree_ptr node = (tree_ptr)malloc(sizeof(struct tree_node));
	tree_ptr temp, prev;
	node->data = item;
	node->left = NULL;
	node->right = NULL;
	
	if(tree == NULL) 	tree = node;
	else{
		temp = tree;
		prev = NULL;
		while(1){
			prev = temp;
			if(item < prev->data){
				temp = temp->left;
				if(temp == NULL){
					prev->left = node;
					return;
				}
			}
			else if(item > prev->data){
				temp = temp->right;
				if(temp==NULL){
					prev->right = node;
					return;
				}
			}
			else 	return;
		}
	}
}
void postorder(tree_ptr ptr){
	if(ptr){
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d\n", ptr->data);
	}
	else 	return;
}
void preorder(tree_ptr ptr){
	if(ptr){
		printf("%d\n", ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
	else 	return;
}
