#include <stdio.h>
#include <stdlib.h>

                        /*ABSTRACT DATA TYPE*/





struct myarray {
    int reservesize;
    int usagesize;
    int *ptr; // It will point towards the first element of my array because in void createarray we are allocating memory at runtime and it will automatically points at first element of contiguous memory block
};





void createarray(struct myarray* arr, int max, int use) {
    arr->reservesize = max;
    arr->usagesize = use;
    arr->ptr = (int*)malloc(max*sizeof(int));  //It will point towards the first = (int*)malloc(max*(sizeof(int)));
}

// void createarray(struct myarray *arr, int max, int usage)
// {
//     (*arr).reservesize = max;
//     (*arr).usagesize = usage;
//     (*arr).ptr; // It will point towards the first = (int*)malloc(max*(sizeof(int)));
// }

/*This code above shows you another way to deference thru star and thru arrow*/





/*The below code is wrong because in this you are not modifying the original value instead only creating a copy of array which will not exist outside the function*/
/*To overcome that challenge you have to use pointer and dereferencing so instead of creating a copy we are pointing toward the original struct and making changes to it and that is also why deferencing ie arrow are used below */

// struct myarray{
//     int maxsize;
//     int usagesize;
//     int memoryallocate;
// };

// void allocatearray(struct myarray arr, int max, int usage) {
//     int maxsize = max;
//     int usagesize = usage;
//     int memoryallocate = (int*)malloc(max*(sizeof(int)))reserve




int enterarray(struct myarray * arr) {
    int n;
    for (int i = 0; i < arr->usagesize; i++)
    {
        printf("Enter %d element : ",i);
        scanf("%d",&n);
        (arr->ptr)[i] = n;
    }
    printf("\n");
}



void showarray(struct myarray *arr /*,int usagesize(Wrong)*/)
{
    for (int i = 0; i < arr->usagesize; i++)
    {
        printf("Element %d : %d\n", i, (arr->ptr)[i]);
    }
    printf("\n");
}
 




int main()
{
    struct myarray Array;
    createarray(&Array,10,2);   // Here we are using '&' because it is not a copy but original array and in function it is not asking for array but for address of an array and that is why '&' is used
    enterarray(&Array);
    showarray(&Array);

    return 0;
}