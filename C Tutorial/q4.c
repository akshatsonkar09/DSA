#include <stdlib.h>
#include <stdio.h>


typedef struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
} TreeNode;

TreeNode *createNode (int val) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = val;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}



TreeNode *InsertinBST(TreeNode *root, int key) {

    if (root == NULL) return createNode(key);

    TreeNode *ptr = root;

    if (key < ptr->data) ptr->lchild = InsertinBST(ptr->lchild, key);
    else if (key > ptr->data) ptr->rchild = InsertinBST(ptr->rchild, key);
    else printf("Duplicate Key");
    return ptr;
}



TreeNode *DeleteinBST(TreeNode *root, int key) {

    if (root == NULL) return root;

    if (key < root->data)
        root->lchild = DeleteinBST(root->lchild, key);

    else if (key > root->data)
        root->rchild = DeleteinBST(root->rchild, key);

    else {
        if (root->lchild == NULL) {
            TreeNode *temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL) {
            TreeNode *temp = root->lchild;
            free(root);
            return temp;
        }

        TreeNode *succ = root->rchild;
        while (succ->lchild) succ = succ->lchild;
        root->data = succ->data;
        root->rchild = DeleteinBST(root->rchild, succ->data);
    }
    return root;
}



int isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL) return 1;

    if (root->data <= min || root->data >= max)
        return 0;

    return isBSTUtil(root->lchild, min, root->data) &&
           isBSTUtil(root->rchild, root->data, max);
}

int isBST(struct Node* root) {
    return isBSTUtil(root, -999, 999);
}



/*
#include <stdio.h>
#include <stdlib.h>

// -------- Node --------
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// -------- Insert in BST --------
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// -------- Inorder Store --------
void inorderStore(struct Node* root, int arr[], int* i) {
    if (!root) return;

    inorderStore(root->left, arr, i);
    arr[(*i)++] = root->data;
    inorderStore(root->right, arr, i);
}

// -------- Find Pair --------
int findPair(struct Node* root, int k) {
    int arr[100], n = 0;

    inorderStore(root, arr, &n);

    int l = 0, r = n - 1;

    while (l < r) {
        int sum = arr[l] + arr[r];

        if (sum == k) return 1;
        else if (sum < k) l++;
        else r--;
    }
    return 0;
}

// -------- Main --------
int main() {
    struct Node* root = NULL;
    int n, x, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements (BST insertion):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    if (findPair(root, k))
        printf("Pair exists\n");
    else
        printf("No such pair\n");

    return 0;
}
*/



void inorder_store(TreeNode* root, int arr[], int *i) {
    if (!root) return;
    inorder_store(root->lchild, arr, i);
    arr[(*i)++] = root->data;
    inorder_store(root->rchild, arr, i);
}

void inorder_fill(TreeNode* root, int arr[], int *i) {
    if (!root) return;
    inorder_fill(root->lchild, arr, i);
    root->data = arr[(*i)++];
    inorder_fill(root->rchild, arr, i);
}
void recoverTree(TreeNode* root) {
    int arr[1000], n = 0;

    inorder_store(root, arr, &n);

    // sort arr[0..i-1]

    // simple bubble sort
    for(int x = 0; x < n-1; x++) {
        for(int y = 0; y < n-x-1; y++) {
            if(arr[y] > arr[y+1]) {
                int temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
            }
        }
    }

    int j = 0;
    inorder_fill(root, arr, &j);
}



    
int main() {

    return 0;
}