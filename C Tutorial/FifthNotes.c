#include <stdio.h>
// #define pi 22/7   wrong as it will be 3 not 3.14
#define pi 22.0/7.0
#define square(r) ((r)*(r))

int main() {

                        /*VOID POINTER START*/
int a=54;
void *ptr;
ptr = &a;

printf("This will give garbage value %d\n", ptr); //type is void so no answer
printf("This will give proper value %d\n", *((int*) ptr)); //type is now changed to int
                        /*VOID POINTER END*/




                        
                        /*NULL POINTER START*/
int b= 34;
int* Ptr = NULL; // If this is uninitialised(int *ptr;) then there is no guarantee what will happen and any statement can be printed
//printf("%d", *ptr);   // Here now pointer is now a null pointer and it can not be dereferenced, if you try to  dereference it then code will crash

// To prevent that we can use if else statment
if (Ptr != NULL)
{
    printf("Address of b is %d\n", *Ptr);
}
else {
    printf("Pointer is null pointer\n");
}
                        /*NULL POINTER END*/



                        /*WILD POINTER START*/
int c = 6;
int* pTr; //This is a wild pointer
pTr = &c;// No longer a wild pointer as it is dereferenced properly otherwise code will give bug
                        /*WILD POINTER START*/


                        /*USE OF PREPROCESSOR START*/
int d = 7;
printf("Area of circle of radius 7 units is %f\n", pi*square(d));
                         /*USE OF PREPROCESSOR END*/


                         /*PREDETERMINED MACRO START*/
printf("Today's Date is %s\n",__DATE__);
printf("Time is %s\n",__TIME__);
printf("File Name is %s\n",__FILE__);
printf("Line is %d\n",__LINE__);
printf("ASCI is %d\n",__STDC__);
                        /*PREDETERMINED MACRO START*/


    return 0;
}
