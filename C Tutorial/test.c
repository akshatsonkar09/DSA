#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} TreeNode;

TreeNode *createNode (int data) {
    TreeNode *new = (TreeNode*)malloc(sizeof(TreeNode));
    new->val = data;
    new->left = new->right = NULL;
    return new;
}

TreeNode *InsertinBST (TreeNode* root, int data) {
    if(root == NULL) return createNode(data);
    else if(root->val > data) root->left = InsertinBST(root->left, data);
    else root->right = InsertinBST(root->right, data);
    return root;
}

void inorder(TreeNode* root, int arr[], int *i) {
    if(root == NULL) return;

    inorder(root->left, arr, i);
    arr[(*i)++] = root->val;
    inorder(root->right, arr, i);
}

void printarray (int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
}

int main() {
    int i = 0;
    int Inorder[100];
    TreeNode *root = createNode(100);
    root = InsertinBST(root,50);
    root = InsertinBST(root,20);
    root = InsertinBST(root,25);
    root = InsertinBST(root,75);
    root = InsertinBST(root,125);
    root = InsertinBST(root,150);
    inorder(root, Inorder, &i);
    printarray(Inorder,i);
    return 0;
}
