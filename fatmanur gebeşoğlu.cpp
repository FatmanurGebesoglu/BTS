#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node BTREE;
BTREE *new_node(int data) {
    BTREE *p = (BTREE *) malloc(sizeof(BTREE));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
BTREE* istenenBuyuk(BTREE* root, int k){
	BTREE *temp = root;
	BTREE *f = NULL;
	int count =0;
    while (temp != NULL) {  
        if (temp->right == NULL) { 
            if (++count == k) 
                f = temp; 
            temp = temp->left; 
        } 
        else { 
            BTREE* temp2 = temp->right; 
            while (temp2->left != NULL && temp2->left != temp) 
                temp2 = temp2->left; 
            if (temp2->left == NULL) { 
                temp2->left = temp; 
                temp = temp->right; 
            } 
            else { 
                temp2->left = NULL; 
                if (++count == k) 
                    f = temp; 
                temp = temp->left; 
            } 
        } 
    }  
    return f; 
}   
int main(){
	BTREE *myroot =new_node(1);
	myroot->left = new_node(2); 
    myroot->right = new_node(7); 
    myroot->left->left = new_node(1); 
    myroot->left->right = new_node(3); 
    myroot->right->left = new_node(6); 
    myroot->right->right = new_node(10);
    printf("%d",istenenBuyuk(myroot,3)->data);
}




