#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};





int getHeight(struct node *n){
    if (n == NULL)
    {
    return 0;
    }
    return n->height;  
}






struct node*createnode(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->left = NULL;
    node->right =NULL;
    node->key = key;
    node->height = 1;

    return node;
}



int max(int a, int b) {
    if (a > b)
    {
        return a;
    }
    return b;

    //return a>b?a:b;
}


int getBalanceFactor(struct node*n){
    if(n == NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}





struct node* leftRotate(struct node* x) {
    struct node* y = x->right;
    struct node* T2 = y->right;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}



struct node* rightRotate(struct node* y) {
    struct node* x = y->left;
    struct node* T2 = x->right;

    y->left = T2;
    x->right = y;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}


struct node* insert(struct node* node, int key) {
    if (node == NULL)
    {
        return createnode(key);
    }

    if (key < node->key)  
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    return node;

    node->height = 1+max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);



    //Left Case
        if (bf >1 && key < node->left->key)
        {
            return rightRotate(node);
        }
        
    //Right Case
    if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    

    //Left Right case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    //Right Left Case
    if (bf < -1 && key > node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }    
    return node;
}


void TraversePreOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        TraversePreOrder(root->left);
        TraversePreOrder(root->right);
    }
}

int main() {

    struct node* root = NULL;
    root = insert(root, 45);
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 8);
    root = insert(root, 97);
    TraversePreOrder(root) ;
return 0;
}