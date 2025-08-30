#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key, height;
    struct Node *left, *right;
};

int height(struct Node* n){ return n? n->height:0; }
int max(int a,int b){ return a>b?a:b; }

struct Node* newNode(int key){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->key=key; n->left=n->right=NULL; n->height=1;
    return n;
}

struct Node* rightRotate(struct Node* y){
    struct Node* x=y->left; struct Node* T2=x->right;
    x->right=y; y->left=T2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}

struct Node* leftRotate(struct Node* x){
    struct Node* y=x->right; struct Node* T2=y->left;
    y->left=x; x->right=T2;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
}

int getBalance(struct Node* n){ return n? height(n->left)-height(n->right):0; }

struct Node* insert(struct Node* node,int key){
    if(!node) return newNode(key);
    if(key<node->key) node->left=insert(node->left,key);
    else if(key>node->key) node->right=insert(node->right,key);
    else return node;

    node->height=1+max(height(node->left),height(node->right));
    int balance=getBalance(node);

    if(balance>1 && key<node->left->key) return rightRotate(node);
    if(balance<-1 && key>node->right->key) return leftRotate(node);
    if(balance>1 && key>node->left->key){ node->left=leftRotate(node->left); return rightRotate(node); }
    if(balance<-1 && key<node->right->key){ node->right=rightRotate(node->right); return leftRotate(node); }
    return node;
}

struct Node* minValueNode(struct Node* node){
    struct Node* current=node;
    while(current->left) current=current->left;
    return current;
}

struct Node* deleteNode(struct Node* root,int key){
    if(!root) return root;
    if(key<root->key) root->left=deleteNode(root->left,key);
    else if(key>root->key) root->right=deleteNode(root->right,key);
    else{
        if(!root->left || !root->right){
            struct Node* temp=root->left?root->left:root->right;
            if(!temp){ temp=root; root=NULL; }
            else *root=*temp;
            free(temp);
        }else{
            struct Node* temp=minValueNode(root->right);
            root->key=temp->key;
            root->right=deleteNode(root->right,temp->key);
        }
    }
    if(!root) return root;
    root->height=1+max(height(root->left),height(root->right));
    int balance=getBalance(root);

    if(balance>1 && getBalance(root->left)>=0) return rightRotate(root);
    if(balance>1 && getBalance(root->left)<0){ root->left=leftRotate(root->left); return rightRotate(root); }
    if(balance<-1 && getBalance(root->right)<=0) return leftRotate(root);
    if(balance<-1 && getBalance(root->right)>0){ root->right=rightRotate(root->right); return leftRotate(root); }
    return root;
}

struct Node* search(struct Node* root,int key){
    if(!root || root->key==key) return root;
    if(key<root->key) return search(root->left,key);
    return search(root->right,key);
}

void preorder(struct Node* root){
    if(root){ printf("%d ",root->key); preorder(root->left); preorder(root->right); }
}

int main(){
    struct Node* root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,25);

    printf("Preorder traversal: "); preorder(root);

    root=deleteNode(root,40);
    printf("\nAfter deletion: "); preorder(root);

    if(search(root,25)) printf("\nKey 25 found!");
    else printf("\nKey not found!");
}
