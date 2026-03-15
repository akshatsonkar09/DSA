#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};

    // Smart createnote function method
struct node* createnode(int data) {
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void TraversePreOrder (struct node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        TraversePreOrder(root -> left);
        TraversePreOrder(root -> right);
    }
}

void TraversePostOrder (struct node* root) {
    if (root != NULL) {
        TraversePostOrder(root->left);
        TraversePostOrder(root->right);
        printf("%d ",root->data);
    }
}

void TraverseInOrder (struct node* root){
    if (root != NULL) {
        TraverseInOrder(root->left);
        printf("%d ", root->data);
        TraverseInOrder(root->right);
    }
}

int main() {

    // Brute Method
    // struct node* p;
    // p = (struct node*)malloc(sizeof(struct node));
    // p->left =NULL;
    // p->right = NULL;
    // p->data = 2;

    // struct node* p1;
    // p1 = (struct node*)malloc(sizeof(struct node));
    // p1->left =NULL;
    // p1->right = NULL;
    // p1->data = 4;

    // struct node* p2;
    // p2 = (struct node*)malloc(sizeof(struct node));
    // p2->left =NULL;
    // p2->right = NULL;
    // p2->data = 6;

    // p->left = p1;
    // p->left = p2;
    // Brute Method

    //Constructing the root node using function insted of writing 4-5 line of code everytime
    struct node* p = createnode(4);
    struct node* p1 = createnode(65);
    struct node* p2 = createnode(6);
    struct node* p3 = createnode(8);
    struct node* p4 = createnode(11);
    struct node* p5 = createnode(17);
    struct node* p6 = createnode(4);

    //           p
    //          /\
    //        /    \
    //       p1    p2
    //      / \    / \
    //    p3  p4  p5  p6

     //          4
    //          / \
    //        /    \
    //       65     6
    //      / \    / \
    //    8   11  17   4

    //Linking of Nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    TraversePreOrder(p);
    printf("\n");
    TraversePostOrder(p);
    printf("\n");
    TraverseInOrder(p);
    printf("\n");

    return 0;
}
