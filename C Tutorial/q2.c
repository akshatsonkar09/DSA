#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    float coeff;
    int power;
    struct node* next;
} Node;

void display(Node *start) {
    if (start == NULL) {   // ✅ edge case
        printf("0\n");
        return;
    }

    while (start)
    {
        printf("%.2fx^%d", start->coeff, start->power);
        if (start->next) printf(" + ");   // cleaner output
        start = start->next;
    }
    printf("\n");
}

Node *createNode(float co, int pow) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->coeff = co;
    newNode->power = pow;
    newNode->next = NULL;
    return newNode;
}

Node *insertNode(Node *start, float co, int pow) {
    if (co == 0) return start; 

    Node *newNode = createNode(co, pow);
    if (!newNode) return start;

    if (start == NULL || pow > start->power)
    {
        newNode->next = start;
        return newNode;
    }

    Node *temp = start;

    while (temp->next && pow <= temp->next->power)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return start;
}

Node *createPolynomial(Node *start) {
    float co;
    int pow, n;

    printf("Enter no. of terms: ");
    scanf("%d", &n);

    if (n <= 0) return start;

    for (int i = 0; i < n; i++)
    {
        printf("Enter coefficient and power: ");
        scanf("%f %d", &co, &pow);

        start = insertNode(start, co, pow);
    }

    return start;
}

Node* AdditionPolynomial(Node *start1, Node* start2) {   // ✅ return type fixed
    if (!start1) return start2;   // ✅ edge case
    if (!start2) return start1;

    Node *temp1 = start1, *temp2 = start2, *start3 = NULL;

    while (temp1 && temp2)
    {
        if (temp1->power == temp2->power)
        {
            float sum = temp1->coeff + temp2->coeff;
            if (sum != 0)
                start3 = insertNode(start3, sum, temp1->power);

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->power > temp2->power)
        {
            start3 = insertNode(start3, temp1->coeff, temp1->power);
            temp1 = temp1->next;
        }
        else
        {
            start3 = insertNode(start3, temp2->coeff, temp2->power);
            temp2 = temp2->next;
        }
    }

    while (temp1)
    {
        start3 = insertNode(start3, temp1->coeff, temp1->power);
        temp1 = temp1->next;
    }

    while (temp2)
    {
        start3 = insertNode(start3, temp2->coeff, temp2->power);
        temp2 = temp2->next;
    }

    return start3;
}

Node* MultiplyPolynomial(Node *start1, Node* start2) {   // ✅ return type fixed
    if (!start1 || !start2) return NULL;   // ✅ edge case

    Node *temp1 = start1, *start3 = NULL;

    while (temp1)
    {
        Node *temp2 = start2;   // ✅ reset properly

        while (temp2)
        {
            start3 = insertNode(start3,
                                temp1->coeff * temp2->coeff,   // ✅ FIXED
                                temp1->power + temp2->power);  // ✅ FIXED

            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }

    return start3;
}


int josephus(int n, int k) {
    if (n == 1)
        return 0;

    return (josephus(n - 1, k) + k) % n;
}






int search(int arr[], int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (arr[i] == val) return i;
    return -1;
}

struct Node* buildPreIn(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end) return NULL;

    Node* root = newNode(preorder[(*preIndex)++]);

    if (start == end) return root;

    int inIndex = search(inorder, start, end, root->data);

    root->left = buildPreIn(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildPreIn(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

struct Node* buildPostIn(int postorder[], int inorder[], int start, int end, int* postIndex) {
    if (start > end) return NULL;

    struct Node* root = newNode(postorder[(*postIndex)--]);

    if (start == end) return root;

    int inIndex = search(inorder, start, end, root->data);

    // IMPORTANT: right first
    root->right = buildPostIn(postorder, inorder, inIndex + 1, end, postIndex);
    root->left = buildPostIn(postorder, inorder, start, inIndex - 1, postIndex);

    return root;
}

struct Node* buildPrePost(int pre[], int post[], int* preIndex, int l, int h, int size) {
    if (*preIndex >= size || l > h) return NULL;

    struct Node* root = newNode(pre[(*preIndex)++]);

    if (l == h) return root;

    int i;
    for (i = l; i <= h; i++) {
        if (post[i] == pre[*preIndex])
            break;
    }

    if (i <= h) {
        root->left = buildPrePost(pre, post, preIndex, l, i, size);
        root->right = buildPrePost(pre, post, preIndex, i + 1, h - 1, size);
    }

    return root;
}




int main() {
    Node *p1 = NULL, *p2 = NULL, *sum = NULL, *prod = NULL;

    printf("Polynomial 1:\n");
    p1 = createPolynomial(p1);

    printf("Polynomial 2:\n");
    p2 = createPolynomial(p2);

    sum = AdditionPolynomial(p1, p2);
    prod = MultiplyPolynomial(p1, p2);

    printf("Sum: ");
    display(sum);

    printf("Product: ");
    display(prod);

    return 0;
}