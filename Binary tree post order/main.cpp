#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    node* left;
    node* right;
};
struct node* root;
struct node* insert(struct node* r, int data);
void postOrder(struct node* r);

int main(){
    root = NULL;
    int n, v;
    printf("How many data's do you want to insert ?\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Data %d: ", i+1);
        scanf("%d", &v);
        root = insert(root, v);
    }
    printf("Postorder Traversal: ");
    postOrder(root);
    printf("\n");
    return 0;
}

struct node* insert(struct node* r, int data){
    if(r==NULL){
        r = (struct node*) malloc(sizeof(struct node));
        r->value = data;
        r->left = NULL;
        r->right = NULL;
    }else if(data < r->value){
        r->left = insert(r->left, data);
    }else {
        r->right = insert(r->right, data);
    }
    return r;

}
void postOrder(struct node* r){
    if(r!=NULL){
        postOrder(r->left);
        postOrder(r->right);
        printf("%d ", r->value);

    }
}
