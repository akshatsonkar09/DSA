#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Smart createnote function method
struct node *createnode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void TraversePreOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        TraversePreOrder(root->left);
        TraversePreOrder(root->right);
    }
}

void TraversePostOrder(struct node *root)
{
    if (root != NULL)
    {
        TraversePostOrder(root->left);
        TraversePostOrder(root->right);
        printf("%d ", root->data);
    }
}

void TraverseInOrder(struct node *root)
{
    if (root != NULL)
    {
        TraverseInOrder(root->left);
        printf("%d ", root->data);
        TraverseInOrder(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
        return 1;
}

// int searchBST (struct node * root, int key) {    Wrong
struct node *SearchRecursiveBST(struct node *root, int key)
{
    // if (root->data == NULL)  Wrong
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return SearchRecursiveBST(root->left, key);
    }
    else if (root->data < key)
    {
        return SearchRecursiveBST(root->right, key);
    }
}

/*
Q) Is root and root->data same? If no then why am I not returning root data as that is the number written inside?
root is a struct node * type pointer while ie the address whereas root->data is int ie a copy
Because your search function is meant to return the node itself, not just the number.
*/

struct node *SearchIterativeBST(struct node *root, int key)
{
    while (root != NULL)
    {
        // if (root->data == NULL)  Wrong
        /*if (root == NULL)
        {
            return NULL;
        }*/
        // Unnecessary condition as it is already stated in while loop
        if (root->data == key)
        {
            return root;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
    }
    return NULL;
}

void InsertinBST(struct node *root, int key)
{
    struct node *prev = NULL;
    struct node *ptr;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
    }
    struct node *new = createnode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

struct node* inOrderPredecessor(struct node *root) {
    root = root->left;
    while (root->right !=NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *DeleteinBST(struct node *root, int value)
{
    struct node* iPre;
    if( root == NULL){
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    
    //Search the node to be deleted
    if (value < root->data)
    {
        root->left = DeleteinBST(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = DeleteinBST(root->right, value);
    }

    //Deletion strategy when the node is found
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = DeleteinBST(root->left, iPre->data);
    } 
    return root;
}


int main()
{

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

    // Constructing the root node using function insted of writing 4-5 line of code everytime
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(2);
    struct node *p4 = createnode(4);

    //           p
    //          /\
    //        /    \
    //       p1    p2
    //      / \   
    //    p3  p4

    //          5
    //          / \
    //         /   \
    //        3     6
    //       / \   
    //      2   4

    //          8
    //          / \
    //         /   \
    //        3    10
    //       / \   
    //      1   6
    //         / \
    //        2  7
    // This is not a BST as 3>2

    // Linking of Nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // TraversePreOrder(p);
    // printf("\n");
    // TraversePostOrder(p);
    // printf("\n");
    TraverseInOrder(p);
    printf("\n");

    struct node *n1 = SearchRecursiveBST(p, 3);
    if (n1 != NULL)
    {
        printf("Found %d \n", n1->data);
    }
    else
        printf("element not found");

    struct node *n2 = SearchIterativeBST(p, 1);
    if (n2 != NULL)
    {
        printf("Found %d \n", n2->data);
    }
    else
        printf("Element not found\n");

    InsertinBST(p, 1);
    TraverseInOrder(p);
    printf("\n");
    
    DeleteinBST(p, 4);
    TraverseInOrder(p);
    printf("\n");

    return 0;
}
