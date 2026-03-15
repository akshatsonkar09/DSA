#include <stdio.h>




int sum(int a, int b) /*Part of Function*/ // Bina iss part ke code nahi chalega kyunki sum  wala operator neeche nahi likha hai aur sirf yahan par woh defined hai
{
    return a + b;
}
//Agar integer function hai toh return value important hai
                                /*Part of function*/
// Agar int ko upar define kiya aur int and return ko maine neeche define kar diya aur toh bhi code chal jayega bas upe ke int me semicolon lagana hoga aur yeh int aur return int main ke bahar hona chahiye$$





                                /*VOID START*/
void printstar(int n) // Same cheese jo upar likhi hai woh iss par bhi valid hai
/* Void ka kaam hota hai sirf value dena yeh value int main me nahi jaati hai

Explanation-
A return value is the data a function sends back to the place where it was called — it’s different from just printing something.

Think of it like this:

📦 A function with a return value is like a vending machine: you press a button, and it gives you something back (like a chocolate).

📢 A function without a return value is like a speaker: you press a button, and it just makes a sound, but doesn't give anything back to you.

⚠️ So your question:
"It is giving output, so isn’t that a return?"

Answer: No.
printf() just displays output on the screen, but it does not return anything useful to main() from func().
*/

{
    for (int i = 0; i < n; i++)
    {
        printf("%c", '*');
    }
}
                                /*VOID END*/





                            /*wITHOUT ARGUMENT WITH RETURN VALUE*/
int takenumber()
{
    int I;
    printf("\nEnter a number\n");
    scanf("%d", &I);
    return I;
}




                            /*EXERCISE 3 RECURSION EXAMPLE*/
                            /*FACTORIAL*/

// It is a good example of loop without using loop cause jo number enter hoga woh factorial function ko wapas se call karega aur karta rahega until else statement naa aa jaye
int factorial(int number)
{
    if (number == 1 || number == 0)
    {
        return 1;
    }
    else
    {
        return (number * factorial(number - 1));
    }
}
                            /*EXERCISE 3*/




                            /*CALL BY REFERENCE*/
void changevalue (int* x) {
    *x = 34;
}



                            /*PASSING ARRAY AS FUNCTION ARGUMENT*/

// void func1(int array[])
// {
//     for (int i = 0; i < 4; i++)
//     {
//         printf("The value at %d is %d\n", i, array[i]);
//     }
//     // array[0] = 382; // Very important point that if you change any value here, it gets reflected in main()
//     return 0;
// }

void func2(int *ptr)
{
    for (int i = 0; i < 4; i++)
    {
        printf("The value at %d is %d\n", i, *(ptr + i));
    }
    *(ptr + 2) = 6534;
}
                            /*PASSING ARRAY AS FUNCTION ARGUMENT*/





int main()
{
    printf("Hello World\n");

                                        /*FUNCTIONS START*/

    // Function can be declared beforehand and can be called when needed like in firstnotes I had to define different int for value but that could have been avvoided if I had declared a and b beforehand and called when needed but I had to declare new functions if I want them to perform different tasks like greater than or less than operators
    // Functions has to be declared then defined and then called
    // If I call a function first and then declare it it will show a warning that function was declared later


    /*Part of Int Sum*/
    int a = 9, b = 27, c;
    c = sum(a, b);
    printf("The sum is %d \n", c);
    /*Part of Int Sum and Example of With argument and with return*/




    /*Part of Void printstar*/
    printstar(7);
    /*Part of Void printstar and Example of With argument and without return */




    /*Example of Without argument and with return*/
    {
        int d;

        d = takenumber();
        printf("Entered Number is %d\n", d);
    }
    /*Example of Without argument and with return*/





    /*BENFITS AND USES OF FUNCTION IN CODES*/

    /*
    ❌Example Without Arguments (Not Reusable):

    #include <stdio.h>

    void print5Times() {
        for(int i = 0; i < 5; i++) {
            printf("Hello\n");
        }
    }

    int main() {
        print5Times();  // always prints 5 times
        return 0;
    }
    ❌ You cannot change how many times it prints without editing the function.
    /*


    /*
    ✅ Example With Arguments (Reusable):
    c
    Copy code
    #include <stdio.h>

    void printNTimes(int n) {
        for(int i = 0; i < n; i++) {
            printf("Hello\n");
        }
    }

    int main() {
        printNTimes(3);  // prints 3 times
        printNTimes(5);  // prints 5 times
        printNTimes(1);  // prints 1 time
        return 0;
    }
    ✅ The same function works for any value of n, because it's passed as an argument.
    */





    /*Exercise -2*/
    /*Multiplication Table*/

    int e, f;
    printf("Hello World\n");
    printf("Enter the number whose Table you want\n");
    scanf("%d", &f);
    printf("Table of %d - \n", f);
    for (int e = 1; e <= 10; e++)
    {
        printf("%d x %d = %d \n", f, e, f * e);
    }
    /*Exercise 2*/





    /*Exercise 3*/
    /*Factorial*/

    int numb;
    printf("Hello World\n");
    printf("Enter the number whose Factorial you want\n");
    scanf("%d", &numb);
    printf("Factorial of %d is %d\n", numb, factorial(numb));





    /*ARRAYS START*/

    int marks[4] = {54, 67, 87, 67}; // Agar user se input lena hota toh = ke aage wala nahi likhte aur For 1D array agar 4 nahi bhi likhoge toh woh apne aap gin lega
    /*
    For taking values of from user

     for (int i = 0; i < 4; i++)
    {
        printf("Enter the marks of %d\n", i+1);     //i+1 matlab i me +1 kar dena hai taaki usse 0 nahi 1 aaye
       scanf("%d", &marks[i]);
    }   */

    /*This is the way to display array below */
    for (int i = 0; i < 4; i++)
    {
        printf("The marks of %d is %d \n", i + 1, marks[i]);
    }



    /* 2D ARRAY*/

    int Marks[2][4] = {{23, 54, 26, 44}, {3, 25, 34, 12}};

    for (int k = 0; k < 2; k++) // Sabse pehle loop yahan se start hoga from k =0 se
    {
        for (int j = 0; j < 4; j++) // Phir loop k=0 saath andar jaayega aur dekhega ki ek aur loop hai aur phir woh k,j ka k=1 ke saath j=1 to 4 ka loop chalayega
        {
            printf("%d ", Marks[k][j]); // iss loop ke andar value print hone lagenge
        }
        printf("\n"); // ab loop j se bahar nikal gaya aur k,j wale [1,1][1,2] [1,3] [1,4] print ke baad ek line chodega
        // ab yeh k=2 ke saath wapas loop par jaayega aur same process follow karega
    }

    /*ARRAY END*/




    /*POINTERS START*/

    int l = 54;
    int *ptrl = &l;
    int *ptrnull = NULL;

    printf("The address of l is %p\n", &l);                                // l ki memory address
    printf("The value of integer pointed by pointer ptrl is %d\n", *ptrl); // pointer jo l ko point kar raha hai usme jo value hai uski value print
    printf("The address of l thru pointer is %p\n", ptrl);                 // l ki memory address thru pointer
    printf("The address of pointer is %p\n", &ptrl);                       // pointer ki memory address
    printf("Gives NULL value and not any garbage value thru pointer ptrnull %d\n", ptrnull);

    // & aata hai memory address dene ke liye aur %x ya %p hai ki kis format me dena hai hexadecimal yaa koi aur type
    // Pointer ka use karke hum apni memory khali kar sakte hai after completing a task and usi memory me dusra task perform kar sakte hai
    // Memory contiguos hoti hai yaani ki blockchain type ek ke baad ek ab agar usme kuch memory khaali hai toh usko fill karke pointer ke thru point kar sakte hai

    /* &(Address-of) and *(Dereference) OPERATOR */
/*         int a = 10;
int *ptr = &a;
printf("%d", *ptr);  // prints 10
Here, *ptr gives the value stored at the address ptr is pointing to.

So, *ptr means "value at the address stored in ptr".
*/

/*
| Symbol | Name        | Meaning                              |
| ------ | ----------- | ------------------------------------ |
| `&`    | Address-of  | Get the memory address of a variable |
| `*`    | Dereference | Get the value at a memory address    |

*/
    /*POINTERS END*/

    /*POINTERS ARITHMETIC START*/
    // Pointer arithmetic p++ me ek value type ka size plus hota hai ie int size = 4 so ptrm me +4 add hoga aur same for ptrm + 1 me

    int m = 4;
    int *ptrm = &m;
    printf("Size of ptrm is %d\n", ptrm);
    ptrm++;
    printf("Size of ptrm++ is %d\n", ptrm);
    printf("Size of ptrm+1 is %d\n", ptrm + 1);

    /*POINTERS ARITHMETIC END*/




    /*POINTER AND ARRAY START*/

    // Agar array define kiya hai aur pointer to array likh diya toh woh by defailt first array ie arr[0] par point karega

    int arr[] = {1, 2, 3, 4, 5, 6};
    printf("The address of first array is %d\n", &arr[0]);
    printf("The address of first array is %d\n", arr);
    printf("The address of sixth array is %d\n", &arr[5]);
    printf("The address of sixth array is %d\n", arr + 5);

    printf("The value of address of first array is %d\n", *(&arr[0]));
    printf("The value of address of first array is %d\n", *arr);
    printf("The value of address of first array is %d\n", arr[0]);
    printf("The value of address of sixth array is %d\n", *(&arr[5]));
    printf("The value of address of sixth array is %d\n", *(arr + 5));
    printf("The value of address of sixth array is %d\n", arr[5]);

    // Printing of value and sizeof array thru different methods
    //  arr++ is not a valid statement because usme ek assigned memory location me assigned space store hai ie woh ek constant hai (programming wala not maths wala)
    //  int *arrayptr = arr;     bana kar array ki memory ko arrayptr++ kar sakte hai aur yeh valid hai cause ab woh bas usme point kar raha hai

    /*POINTER AND ARRAY END*/



    /*ACTUAL vs FORMAL PARAMETERS*/

    /*

    int add (int a,int b) //Yeh formal variable hai jo sirf function ke andar assigned hai bahar nahi yeh apni value argument yaani int x/y se le leta haif
    {
    int y1; //local variable
    return a+b;
    }

    int main () {
    int x=2, y=3; // Yeh actual variable hai jo ki har jagah valid hai main ke andar aur bahar dono aur yeh copy hota hai a and b ki jagah par jab function ko call karte hai
    add(x,y)
    }

    */




/*
Call by value matlab function me main se value ko bhejna aur isme original value change nahi hoti hai
Call by reference matlab function me main se value ka address bhejna (one way thru dereferencing ie &x aur int*x wala method aur isme original value change kar sakte hai hai)
*/

/*EXAMPLE OF CALL BY REFERENCE*/
 int n = 43;
    printf("Value of n is %d\n", n);
    changevalue(&n);
    printf("Value of n is %d\n", n);
    //Bina original value badle value change kardi under same variable






/*PASSING ARRAY AS FUNCTION ARGUMENT START*/

    int array[] = {23, 13, 3, 43};

    printf("The value at index 0 is %d\n", array[2]);
    // func1(array);
    func2(array);
 printf("The value at index 0 is %d\n", array[2]);

/*PASSING ARRAY AS FUNCTION ARGUMENT END*/


    return 0;
}
