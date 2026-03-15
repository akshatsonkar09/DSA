#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coef;
    int expo;
    struct node *link;
};


// Function to create a new node telling the number of terms you want
struct node *create(struct node *start)
{
    float coeff;
    int expo, i, n;
    printf("\nEnter the number of terms you want");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("/nEnter the coefficient and exponent of %d term:", i);
        scanf("%d %d", &coeff, &expo);
        start = insert_s(start, coeff, expo);
    }
    return start;
}


// Function to insert new node and new term
struct node *insert_s(struct node *start, float co, int ex)
{
    struct node *tmp, *ptr;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->coef = co;
    tmp->expo = ex;
    if (start == NULL || ex > start->expo) /* If list is empty or exp greater than first node */
    {
        tmp->link = start;
        start = tmp;
    }
    else
    {
        ptr = start;
        while (ptr->link != NULL && ptr->link->expo >= ex)
            ptr = ptr->link;
        tmp->link = ptr->link;
        ptr->link = tmp;
    }
    return start;
}


// Function to insert/link in new node
struct node *insert(struct node *start, float co, int ex)
{
    struct node *tmp, *ptr;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->coef = co;
    tmp->expo = ex;
    if (start == NULL) /* If list is empty */
    {
        tmp->link = start;
        start = tmp;
    }
    else /* insert at the end of the list*/
    {
        ptr = start;
        while (ptr->link != NULL)
            ptr = ptr->link;
        tmp->link = NULL; /* or tmp->link = ptr->link*/
        ptr->link = tmp;
    }
    return start;
}
// Display Linked list
void display(struct node *start)
{
    struct node *ptr = start;
    if (ptr == NULL)
    {
        printf("Zero polynomial");
        return;
    }
    while (ptr != NULL)
    {
        printf("%.1fx^%d", ptr->coef, ptr->expo);
        ptr = ptr->link;
        if (ptr != NULL)
            printf("+");
        else
            printf("\n");
    }
}

// Addition of two polynomials
void poly_add(struct node *p1, struct node *p2)
{
    struct node *start3;
    start3 = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->expo > p2->expo)
        {
            start3 = insert(start3, p1->coef, p1->expo);
            p1 = p1->link;
        }
        else if (p2->expo > p1->expo)
        {
            start3 = insert(start3, p2->coef, p2->expo);
            p2 = p2->link;
        }
        else if (p1->expo == p2->expo)
        {
            start3 = insert(start3, p1->coef + p2->coef, p1->expo);
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    while (p1 != NULL) /*If poly2 has finished and elements left in poly1*/
    {
        start3 = insert(start3, p1->coef, p1->expo);
        p1 = p1->link;
    }
    while (p2 != NULL) /*If poly2 has finished and elements left in poly1*/
    {
        start3 = insert(start3, p2->coef, p2->expo);
        p2 = p2->link;
    }
    printf("Added Polynomial is : ");
    display(start3);
}


// Multiplication of two polynomials
void poly_multi(struct node *p1, struct node *p2)
{
    struct node *start3;
    struct node *p2_beg = p2;
    start3 = NULL;
    if (p1 == NULL && p2 == NULL)
    {
        printf("Multiplied Polynomial is zero polynomial \n: ");
        return;
    }
    while (p1 != NULL)
    {
        p2 = p2_beg;
        while (p2 != NULL)
        {
            start3 = insert_s(start3, p1->coef * p2->coef, p1->expo + p2->expo);
            p2 = p2->link;
        }
        p1 = p1->link;
    }
    display(start3);
}

int main()
{
    struct node *start1 = NULL, *start2 = NULL, *start3 = NULL;
    printf("Enter Polynomial 1");
    start1 = create(start1);
    printf("Enter Polynomial 2");
    start2 = create(start2);
    // Display polynomials List
    printf("\n polynomial 1 is: ");
    display(start1);
    printf("\n polynomial 2 is: ");
    display(start2);
    // Function add two polynomial numbers
    poly_add(start1, start2);
    // Function multiply two polynomial numbers
    poly_multi(start1, start2);
    return 0;
}