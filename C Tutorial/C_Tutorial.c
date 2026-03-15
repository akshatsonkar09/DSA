#include <stdio.h>
#define pie 3.14        // Value of pie is absolute defined if any other value is specified then it will show error
#include <string.h> // library hai in string
#include <stdlib.h> // for memory allocation
// #define pi 22/7   wrong as it will be 3 not 3.14
#define pi 22.0 / 7.0
#define square(r) ((r) * (r))



/*Part of Function*/

int sum(int a, int b)  // Bina iss part ke code nahi chalega kyunki sum  wala operator neeche nahi likha hai aur sirf yahan par woh defined hai
{
    return a + b;
}
// Agar integer function hai toh return value important hai

/*Part of function*/



// Agar int ko upar define kiya aur int and return ko maine neeche define kar diya aur toh bhi code chal jayega bas upar ke int me semicolon lagana hoga aur yeh int aur return int main ke bahar hona chahiye$$







/*VOID START*/

void printstar(int n) // Same cheeze jo upar likhi hai woh iss par bhi valid hai
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", '*');
    }
}

/*
Void ka kaam hota hai sirf value dena yeh value int main me nahi jaati hai basically no return statement hota hai void ie works even without void

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


/*VOID END*/








/*wITHOUT ARGUMENT WITH RETURN VALUE*/
int takenumber()
{
    int I;
    printf("\nEnter a number\n");
    scanf("%d", &I);
    return I;
}
/*wITHOUT ARGUMENT WITH RETURN VALUE*/




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
int changevalue(int *x)
{
    *x = 34;
}
/*CALL BY REFERENCE*/






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



/*STRING START*/

// void name (char string[]) {
//     int i;
//     while (string[i] != '\0')
//     {
//         printf("%c",string[i]);
//         i++;
//     }
// }
// String print thru function but while loop

/* Parameter = variable inside function definition
  Argument = actual value you send while calling */

void name(char string[])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        printf("%c", string[i]);
    }

    printf("\n"); // String print thru function but for loop
}

/*STRING END*/





/*STRUCTURE START*/
struct student
{
    int roll;
    int marks;
    char grade;
    char name[30];
} /*akshat,sahil;*/; // Aise pre define bhi kar sakte hai

// struct student akshat,sahil;        structure ko agar yahan par rakhenge toh woh ek global variable ban jayega aur kabhi bhi call kiya jaa sakta hai

/*STRUCTURE END*/





/*TYPEDEF START*/
/*Eg 2*/
//  Normally
// struct student
// {
//     int roll;
//     int marks;
//     char grade;
// };

typedef /**/ struct Student
{
    int roll;
    int marks;
    char grade;
} /**/ std;
/*TYPEDEF END*/




/*UNION START*/
union sTudent
{
    int roll;
    int marks;
    char grade;
    char name[38];
};
/*UNION END*/





/*MISCELLANEOUS 1 START*/
// This shows that even if we use same variable it is not exactly same and are actually saved into two different spots
int func1(int e)
{
    printf("the address of e inside function is %d\n", &e);
    return e * 10;
}
/*MISCELLANEOUS 1 END*/





/*GLOBAL,LOCAL AND STATIC VARIABLE START*/
int d; // This is a global variable since it can be used in entire code
int func3(int f)
{
    int loc;              // This is a local variable since it can only be used inside the function
    static int myvar = 0; // If my var is not given any value then it starts from 0
    printf("The value of myvar is %d\n", myvar);
    myvar++;
    return f + myvar;
    // Instead of staring from the start the function remebers its last value when it was called then start from that value when called again
}
/*GLOBAL,LOCAL AND STATIC VARIABLE END*/





/*MISCELLANEOUS 2 START*/
void reverse(char str[])
{
    int len = strlen(str);
    for (int j = 0; j < len / 2; j++)
    {
        char temp = str[j];
        str[j] = str[len - j - 1];
        str[len - j - 1] = temp;
    }
}
/*MISCELLANEOUS 2 END*/




int main()
{

    printf("Hello World\n");

    // \n for end line or called escape sequence and is one single character
    // other backslash sequences can be used for different purposes

    printf("Hello \t \"New World\n");
    // IMPORTANT - \t will give tab space and \" or \' for quotes




    // Start of Algebraic
    int a, b;
    a = 4;
    printf("Number A is %d\n", a);
    printf("Number B is ");
    scanf("%d", &b);

    printf("Sum %d and %d is %d\n", a, b, a + b);
    // This ends Algebraic




    /*  $$ %d means make space for a integral value
    if IMPORTANT %d(format specifier) used two time then has to assign both times and if three so three time and so on $$ */




    // Sizeof Start
    int arrr[5];
    int *pp = arrr;

    //printf("%zu", sizeof x);      For variable paranthesis is not needed
    printf("Size of Int is %zu\n", __SIZEOF_INT__);
    printf("Size of Float is %zu\n", sizeof(float));
    printf("%zu\n", sizeof(char));
    printf("%zu\n", sizeof(arrr));      // 20 (5 * 4)
    printf("%zu\n", sizeof(arrr[0]));      // 4
    printf("SIZE OF POINTER IS %zu\n", sizeof(pp));    //4 for 32 bit and 8 for 64 bit

    // (Important) sizeof is an operator, not a function.
/*
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("%zu", sizeof(arr));
    // //sizeof is evaluated at compile time, not runtime except when used with variable length arrays, it is evaluated at runtime (since VLA) sizeof does not evaluate the expression:
*/

/*int x = 10;
printf("%zu", sizeof(x++));  // x is NOT incremented

Use %zu in printf for sizeof because it returns a value of type size_t          IMPORTANT
*/





    /*Sizeof End


    Int only gives integer
    Float gives 6 decimal points    IMPORTANT
    Double and long double even furthur*/






    /*Operators Start
    $$You can use Alt + Click for multi cursor$$*/

    
    // Start of Integer Operators
    a = 34;
    b = 6;

    printf("a+b = %d\n", a + b);
    printf("a-b = %d\n", a - b);
    printf("a*b = %d\n", a * b);
    printf("a/b = %d\n", a / b);
    printf("ab = %d\n", a % b);

    // End of Integer Operators


    // Start of Float Operators
    
    float c;
    a = 7;
    c = 6.34;
    
    printf("a+c = %f\n", a + c);
    printf("a-c = %f\n", a - c);
    printf("a*c = %f\n", a * c);
    printf("a/c = %f\n", a / c);
    

    // End of Float Operators


    /* 
    %d is for integers while %f is for floating variables
    IMPORTANT****** For some reason int%float does not work and shows error (Answer- modulus operator % only works with integer types.)
    % gives remainder and is called modulus
    $$ I am unable to take fraction/float value and use it as an integral value $$
    */
   




    /*Relational Operators Starts*/
    a = 34;
    b = 6;

    printf("a is equal to b = %d\n", a == b);
    printf("a is not equal to b = %d\n", a != b);
    printf("a is greater than b = %d\n", a > b);
    printf("a is less than b = %d\n", a < b);
    printf("a is greater or equal to than b = %d\n", a >= b);
    printf("a is less or equal to than b = %d\n", a <= b);

    // For true 1 and For false 0 is returned

    /*Relational Operators Ends*/





    /*Logical Operators Start*/
    a = 0;
    b = 34;

    printf("Both Satisfy = %d\n", a && b);
    printf("Atleast One Satisfy = %d\n", a || b);
    printf("Condition of Both Satisfy then output Reversed = %d\n", !a && b);

    /*
    These condition are only satisfied when input is integer except 0 ie 32 and 42 satisfy conditions
    For not output put ! mark
    */

    /*Logical Operators Ends*/








    /*Bitwise Operator Start*/

    /* 
    & is and; | is or ; ^ is Xor gates and are calculated in binary form
    */

    /*
    Eg 2 = 10 and 3 = 11
    So first place of both is compared and then second place of both is compared
    */

    a = 1;
    b = 2;

    printf("And Gate = %d\n", a & b);
    printf("Or Gate = %d\n", a | b);
    printf("XOR Gate = %d\n", a ^ b);

    /*
    a & b gives a non-zero result only if at least one bit position is 1 in both a and b.
    Eg - int a = 6;  // Binary: 00000110
    int b = 3;  // Binary: 00000011
    */


    // Not only 1 and 0 but &/| in binary and answer in numeral
    // Useful for fast calculations and low runtime
    // $$Do not confuse OR/AND for addition$$

    /*Bitwise Operator End*/



    /*Float Decimal Places Start*/
    //IMPORTANT*******************
    
    float o;
    
    o = 8.356;
    
    printf("Value of b is %9.2f\n", o);
    printf("%10.2f\n", 3.14);
    printf("%010.2f\n", 3.14); // width = 10, padded with zeros → "0000003.14"

    /* 
    9.6 tell us to leave space for 9 characters(including decimal) and upto 6 decimal places
    if we add negative sign then succeeding space left otherwise preceeding space is vacant
    */
   
   /*Float Decimal Places End*/




   //////// In C constant is something which cannot be changed or absolute value
   





    /*Constant variables Start*/
    
    int p = 3;
    //  int p = 4;  Will throw error
    p = 4;  //No error

    printf("%d\n", p);
    
    // This is to tell that if there are no operators then I can change my variable 'p from 3 to 4'
    // To prevent this use const function or predefined function(at top)
    
    /*
    IMPORTANT
    const int q = 5;
    q=7;
    printf("%d",q);
    */
   // This program will show error
   

   /*Constant variables End*/











    /*My exerecise 1 Start*/


    /*
    char ch= 'M';
    char ch= 'S';
    char ch= 'MS';
    This is wrong only below part is needed
    */

    char ch = 'Q'; // Still not sure about declarations
    // char ch = 'A';  Correct way
    // char ch = 'AB"; Wrong cannot use 2 letters

    printf("We are giving gifts to students who have passed exams of \n 1) Maths(Q)\n 2) Science(S)\n 3)Maths and Science Both(R)\n Please enter which Exam you passed\n");

    scanf(" %c", &ch); // This part is weak

    if (ch == 'Q' || ch == 'q') /*character should always be in inverted quotes
          ||(or gate) is used for mulitple commands*/

    {
        printf("You are awarded 15 Points\n");
    }

    else if (ch == 'S' || ch == 's')
    {
        printf("You are awarded 15 Points\n");
    }

    else if (ch == 'R' || ch == 'r') // char==MS cannot be used as it is two letters
    {
        printf("You are awarded 45 Points\n");
    }

    /*
    Very Important concept of using space before %c
   1) When you enter input in the console, you typically press Enter (\n) after typing.

    2)If you enter, for example, Q and press Enter, the input buffer contains:

text
  Code-  'Q' '\n'
3) %c reads the very next character, including whitespace (like \n, spaces, or tabs).

4) So, if you do:


Code - scanf("%c", &ch);  // Reads 'Q' (correct)
5) but if you call scanf("%c", &ch) again, it will read \n (leftover newline) instead of waiting for new input.

6) A space in the format string (" %c") tells scanf to skip all whitespace characters (spaces, tabs, newlines) before reading the next non-whitespace character.

7) So, if the input is Q\n:     It ignores \n and waits for the next actual character (like 'Q').

8) OR you can use getchar(); after sacnf of char to tackle this issue
    */


    /*My Exercise 1 End*/













    /*Switch Start*/




    /*Switch Program Type 1*/

    /*In this type marks input is inside case function*/
    int age, marks; // Error made ---> int=age,marks;
    age = 3;
    marks = 45;

    /*  
    1) No semicolon in switch and curly brackets for cases until end
    2)Switch is a substitute for if else if
    3)Break can be removed but if there is no break then code will not terminate after finding correct case but will execute complete code and will give default statement as weel so use according to need
    4) case 3 is not third case but case where entered value is 3   
    */

    switch (age)
    {
    case 3:
        printf("Enter Your Age - 3\n");
        printf("Your Age is 3\n");

        printf("Enter Your Marks - 45\n");
        // scanf("%d", &marks);      (If marks input from user)

        switch (marks)
        {
        case 45:
            printf("Your Marks are 45\n");
            break;

        default:
            printf("Your age is 3 but Marks not 45\n");
            break;
        }
        break;

    default:
        printf("Age is not 3\n");
        break;
    }

    /*Switch Type 1 End */

    
    /*Switch Type 2 Start*/
    /*In this type marks input is outside case function*/

    int AGE, MARKS;
    AGE = 3;
    MARKS = 45;

    printf("Enter Your AGE - 3\n");
    // scanf("%d", &AGE);    (If age input from user)
    printf("Enter Your MARKS - 45\n");
    // scanf("%d", &MARKS);      (If marks input from user)

    switch (AGE)
    {
    case 3:
        printf("Your AGE is 3\n");

        switch (MARKS)
        {
        case 45:
            printf("Your MARKS are 45\n");
            break;

        default:
            printf("Your AGE is 3 but MARKS not 45\n");
            break;
        }
        break;

    default:
        printf("AGE is not 3\n");
        break;
    }
    /*Switch Type 2 End*/


    /*Both Types are not exactly same the way they show output differs but both are correct and can be used according to situations*/


    /*Switch End*/










    /*Loop Start*/

    int num, index = 0; // Mistake was not defining starting point of I

    printf("Enter Your Number\n");
    scanf("%d", &num);

    /*Do While Start*/

    do
    {
        printf("Loop numbers are %d\n", index);
        index = index + 1; // Forgot to write this
    } 
    while (index < num);

    /*Do While End*/


    /*Do While without user indexput*/

    index = 0;
    do
    {
        printf("%d", index);
        index = index + 1;
    } while (index < 20);

    /*Do While without user input*/

    /*While Loop Start*/

    index = 0;

    while (index < 20)
    {
        printf("%d", index);
        index = index + 1;
    }

    /*While Loop End*/



    /*For Loop Start*/
    
    /*Different Ways to write For Loop*/
    
    int x;
    for (x = 0; x < 5; x++)
    { // agar kaafi saari condition daal di toh execute toh   sabko karega lekin maanega sirf last wale ko
        printf(" 1st For %d \n", x);
    }
    
    int X = 0; // pehele define kar diya toh bhi chalega
    for (; X < 5; X++)
    { // semicolon lagega par aur 1st expression khali rahega
        printf("2nd For %d\n", X);
    }
    
    int y, z = 0; // saath me do bhi define kar sakte hai
    for (y = 0; z < 5; z++)
    { // semicolon lagega par aur 1st expression khali rahega
        printf("3rd For %d %d\n", z, y);
    }
    
    int w = 0; // pehele define kar diya toh bhi chalega
    for (; w < 5;)
    { // semicolon lagega par aur 1st expression khali rahega
        printf("Pehle Define %d\n", w);
        w++; // baad me bhi define kar sakte hai
    }
    
    // Basically jab marzi tab jo chahe woh define karlo
    
    int try = 0;
    for (; try <= 10; try++) // Agar sirf ek hi line hai toh curly brackets ki need nahi hai
        printf("Try %d\n", try);
        
        for (int newtry = 0; newtry < 8; newtry++) // int for me bhi define kar sakte ho
        printf("New Try %d\n", newtry);
        
    /*For Loop End*/


    /*LOOP START*/

    int i;
    for (i = 0; i < 10; i++) // First is kahan se start karna hai Second is kab band karna hai(more appropriate)\kab tak karna hai, last is increment karna hai yaa decrement in i
    {
        printf("%d\n Enter Your Age\n", i); // break is basically used to break loop if undesired thing happens
        scanf("%d", &age);                  // Isme scanf andar hai isliye yeh output maangta rahega tab tak jab loop naa pura hojaye yaa phir break statement naa lag jaaye
        if (age > 10)
        {
            break;
        }
    }

    /*LOOP END*/




    /*CONTINUE START WEAK*/

    
    scanf("%d", &AGE); // Isme ek baar age daalni padegi
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", i); // Zero iss line ki wajah se aa raha hai
        // scanf("%d", &AGE); //baar baar value daalni padegi cause loop me baar baar scanf aayega
        if (AGE < 10)
        {
            continue;
        }

        printf("No continue Statement Found\n");
    }

    /*CONTINUE END*/





    /*GOTO Statement Start*/


label:
    printf("We are inside loop\n");
    goto end; // This is not termination but command to go to end statement
    // Because of this Hello world print nahi hoyega aur end statement print hogi
    // Agar yeh naa hota toh goto label par wapas aa jata kyunki neeche goto label hai aur infinit eloop chalu ho jayega
    printf("Hello World\n");
    goto label;
end:
    printf("We are at end\n");

    /* for loop me agar break lagao toh woh sirf previous for loop se bahar nikalta hai lekin agar goto end bana de aur sab loops se bahar ek end statement me break laga de toh woh saare loops se bahar nikaal dega*/


    /*GOTO Statement END*/








    /*TYPECASTING START*/
    // IMPORTANT*********
    // Typecasting is changing type of variable from one into another

    // float c = 54/5;  //float me agar koi integral arithmetic karoge toh compiler usko automatically integral me kar deg yaani 10 aayega naa ki 10.8
    a = 5;
    float bb = a;    // implicit typecast (int → float)
    float cc = (float)a;  // explicit typecast (same effect, but you control it)

    /*Type 1*/
    /*DIDNOT UNDERSTAND*/
    cc = 54/5;
    /*
Both 54 and 5 are integers. So the division happens in integer arithmetic first:
    54 / 5 = 10   // fractional part is thrown away
Then that integer 10 is converted to float after division → c = 10.0. That’s why you got 10.0, not 10.8.
    


c = (float)54 / 5;
Here    (float)54 → 54.0 (we explicitly make it a float)
Now we have 54.0 / 5 → float division.
Result = 10.8

Because if any operand in / is float, the entire operation is done in floating-point arithmetic.

You could also do:  c = 54 / (float)5;
*/
    printf("The value of a is %f\n", a);

    /*Type 2*/
    c = 2.55;
    printf("The value of b is %f\n", (float)c);

    /*TYPECASTING END*/




    /*FUNCTIONS START*/

    // Function can be declared beforehand and can be called when needed like in firstnotes I had to define different int for value but that could have been avvoided if I had declared a and b beforehand and called when needed but I had to declare new functions if I want them to perform different tasks like greater than or less than operators
    // Functions has to be declared then defined and then called
    // If I call a function first and then declare it it will show a warning that function was declared later


    /*Part of Int Sum*/
    a = 9, b = 27, c;
    c = sum(a, b);
    printf("The sum is %d \n", c);
    /*Part of Int Sum and Example of With argument and with return*/




    /*Part of Void printstar*/
    printstar(7);
    /*Part of Void printstar and Example of With argument and without return */




    /*Example of Without argument and with return*/
    {
        // int d;

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
    printf("Enter the number whose Table you want\n");
    scanf("%d", &a);
    printf("Table of %d - \n", a);
    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d \n", a, i, a * i);
    }
    /*Exercise 2*/



    /*Exercise 3*/
    /*Factorial*/
    int numb;
    printf("Hello World\n");
    printf("Enter the number whose Factorial you want\n");
    scanf("%d", &numb);
    printf("Factorial of %d is %d\n", numb, factorial(numb));
    /*Factorial*/
    /*Exercise 3*/




    /*ARRAYS START*/

    int Marks[4] = {54, 67, 87, 67}; // Agar user se input lena hota toh = ke aage wala nahi likhte aur For 1D array agar 4 nahi bhi likhoge toh woh apne aap gin lega
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
        printf("The marks of %d is %d \n", i + 1, Marks[i]);
    }


    /* 2D ARRAY*/

    int MarKs[2][4] = {{23, 54, 26, 44}, {3, 25, 34, 12}};

    for (int k = 0; k < 2; k++) // Sabse pehle loop yahan se start hoga from k =0 se
    {
        for (int j = 0; j < 4; j++) // Phir loop k=0 saath andar jaayega aur dekhega ki ek aur loop hai aur phir woh k,j ka k=1 ke saath j=1 to 4 ka loop chalayega
        {
            printf("%d ", MarKs[k][j]); // iss loop ke andar value print hone lagenge
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
    // Bina original value badle value change kardi under same variable






    /*PASSING ARRAY AS FUNCTION ARGUMENT START*/

    int array[] = {23, 13, 3, 43};

    printf("The value at index 0 is %d\n", array[2]);
    // func1(array);
    func2(array);
    printf("The value at index 0 is %d\n", array[2]);

    /*PASSING ARRAY AS FUNCTION ARGUMENT END*/





    /*STRING START*/
    // char name[27]; // Iska matlab hai ek character jisme 27 letters/characters hai agar sirf 5-6 characters use kiye toh uske aage garbage value aa jayegi aur usi se bachne ke liye humnull ka use karte hai toh ek name likhne ke liye word length + 1 ie null value daalne ki space jitni length chahiye hoti hai
    char str[] = "Akshat";
    printf("Using custom function ");
    name(str);

    printf("Using manual way ");
    char Array[] = {'A', 'k', 's', 'h', 'a', 't', '\0'};
    name(Array);

    printf("Strings using different methods \n");
    gets(str);
    printf("Using printf %s\n", str);
    printf("Using puts: ");
    puts(str);
    printf("\n");
    // Scanf ka use karke whitespaces nahi le paayenge issliye gets ka use kiya
    // C me string exists nahi karti instead upar sab methods ka use karke string banate hai

    /*STRING END*/





    /*STRING LIBRARY START*/

    char s1[] = "Harry";
    char s2[] = "Ravi";
    char s3[50];

    // puts(strcat(s1,s2)); This joins harry and ravi as harryravi and assign it in s1
    printf("Length of Harry is %d\n", strlen(s1)); // Maine strcat ka use karke s1 and s2 ko join kardiya hai isliye strlen me s1 yaa s2 daalne par harryravi wala length milega

    // s3 = strcat(s1,s2);  This will be false instead
    strcpy(s3, strcat(s1, s2)); // This will work
    puts(s3);
    // HarryRavi bana kar usko s3 me store kar liya

    printf("Reverse is \n");

    puts(strrev(s1));
    // puts(strrev(s1,s2));
    /*
    Compiler is not letting this code run saying too many arguments(Reason was that I could only use s1 not s1,s2) while chatgpt is saying that vs studio doesn't recognise strrev function and is saying to use below method(it does recognise just too many arguments)
    */

    /*STRING LIBRARY END*/





    /*MISCELLANEOUS 2 START*/
    printf("Reverse Again is ");
    reverse(s1);
    puts(s1);
    /*MISCELLANEOUS 2 END*/



    // You can find other string functions and use them the same way







    /*STRUCTURE START*/

    struct student akshat, sahil; // yahan par structure ek local variable hai aur iss liye ise baar baar call nahi kar sakte
                                  // XXXXX data feed karne ka ek aur tareeka bhi hai jo ki screenshots me milega XXXXXX
    akshat.roll = 2;
    sahil.roll = 5;
    akshat.grade = 'b';

    printf("Akshat roll no is %d\n", akshat.roll);

    strcpy(akshat.name, "Akshat");
    printf("%s\n", akshat.name);
    /*STRUCTURE END*/









    /*TYPEDEF START*/
    // Syntax  --  tyypedef <previous_name> <alias_name> ;
    /*Eg 1*/
    typedef unsigned long ul;
    ul l1, l2, l3;
    /*Eg 1*/

    /*Eg 2*/
    std s4, s5;
    s4.grade = 'A';
    // Instead of student std is used
    /*Eg 2*/

    /*Eg 3*/
    /* int *a,b;
    int c;
    a = &c;
    b = &c;
    This will give error
    In this a is a pointer but b is stored as a simple integer but with typedef*/
    typedef int *intptr;
    intptr pa, pb;
    int e;
    pa = &e;
    pb = &e;
    /*TYPEDEF END*/





    /*UNION START*/
    /*
    union student
        s5 = {2,487,'A'};
        strcpy(s5.name,"Akshat");

        printf("Roll no. %d\n", s5.roll);
        printf("Marks %d\n", s5.marks);
        printf("Grade %c\n", s5.grade);
        printf("Name %s\n", s5.name);
    */
    // This programme will give error as we are using multiple data types in same memory location

    /*UNION END*/








    /*MISCELLANEOUS 1 START*/
    e = 4;
    printf("The address of e inside main is %d\n", &e);
    func1(e);
    /*MISCELLANEOUS 1 END*/








    /*GLOBAL,LOCAL AND STATIC VARIABLE START*/
    int f;
    int val = func3(f);
    val = func3(f);
    /*GLOBAL,LOCAL AND STATIC VARIABLE END*/






    // Lecture 44 of C of code with harry is good for making custom snippets ie custom formats of code





    /*DYNAMIC MEMORY ALLOCATION START*/

    // Malloc me data void me store hota hai isliye typecast ka use karke int/char me change kar sakte hai

    // Malloc me ek specific byte size maangne ki jagah size of ke terms me maang lo kyunki har ek computer me int/data type ka size alag hota hai

    // Malloc and Calloc are almost same but two differences
    // 1) Malloc me direct x byte data allocate hota hai aur calloc me n times x byte data store hota hai
    // 2) Malloc me memory exceed hone par garbage value aati hai aur calloc me 0

    int *iptr, pn = 3;
    printf("Size of memory you want to assign\n");
    // scanf(%d,&n);
    iptr = (int *)calloc(pn, sizeof(int));
    // ptr = (int*) malloc((n+1)*sizeof (int) or 37);

    for (int i = 0; i < pn; i++)
    {
        printf("Value of %d is %d \n", i, &iptr[i]);
    }
    // Using scanf and another for loop you can also give value to your data instead of just there address

    iptr = (int *)realloc(iptr, (pn + 1) * sizeof(int));

    for (int i = 0; i < pn + 1; i++)
    {
        printf("New Value of %d is %d \n", i, &iptr[i]);
    }
    // The old values and new values are same this means same memory is reallocated

    free(iptr); // This frees all the memories

    /*DYNAMIC MEMORY ALLOCATION END*/







    /*VOID POINTER START*/
    a = 54;
    void *vptr;
    vptr = &a;

    printf("This will give garbage value %d\n", vptr);          // type is void so no answer
    printf("This will give proper value %d\n", *((int *)vptr)); // type is now changed to int
    /*VOID POINTER END*/






    /*NULL POINTER START*/
    b = 34;
    int *Ptr = NULL; // If this is uninitialised(int *ptr;) then there is no guarantee what will happen and any statement can be printed
    // printf("%d", *ptr);   // Here now pointer is now a null pointer and it can not be dereferenced, if you try to  dereference it then code will crash

    // To prevent that we can use if else statment
    if (Ptr != NULL)
    {
        printf("Address of b is %d\n", *Ptr);
    }
    else
    {
        printf("Pointer is null pointer\n");
    }
    /*NULL POINTER END*/







    /*WILD POINTER START*/
    b = 6;
    int *pTr; // This is a wild pointer
    pTr = &b; // No longer a wild pointer as it is dereferenced properly otherwise code will give bug
    /*WILD POINTER START*/





    /*USE OF PREPROCESSOR START*/
    d = 7;
    printf("Area of circle of radius 7 units is %f\n", pi * square(d));
    /*USE OF PREPROCESSOR END*/




    /*PREDETERMINED MACRO START*/
    printf("Today's Date is %s\n", __DATE__);
    printf("Time is %s\n", __TIME__);
    printf("File Name is %s\n", __FILE__);
    printf("Line is %d\n", __LINE__);
    printf("ASCI is %d\n", __STDC__);
    /*PREDETERMINED MACRO START*/

// FILE *ptr = NULL;
FILE *ptr; 

    /*FILE I/O OPERATIONS START*/
    /*Reading a file*/
    
    /*Type1*/
    ptr = fopen("file.txt", "r");  //Opening with intention of reading the file
    char read[100];   //To store the text written in file
    fscanf(ptr,"%s", read);   //This will store the content of file until a white space appears
    printf("%s\n",read);  //This is to print the stored string
fclose(ptr);

/*Type 2*/
ptr = fopen("file.txt","r");
char character = fgetc(ptr);
printf(" %c\n",character);
fclose(ptr);

/*Type 3*/
ptr = fopen("file.txt","r");
char string[100];
fgets(string,13 , ptr);
printf("%s",string);
fclose(ptr);

/*Type 4*/ //(IMPORTANT)
ptr = fopen("file.txt", "r");
char multistring [100];
// read line by line until EOF
    while (fgets(multistring, sizeof(multistring), ptr)) {
        printf("%s", multistring);  // each line already ends with '\n'
    }
    
    
    /*Appending A file*/
    ptr = fopen("file.txt","a");    //Opening with intention of appending in the file
    char append[200] = "This content will appear in the file without removing all others and will append everytime you run the program\n";
    fprintf(ptr,"%s",append);   //(file ptr, format specifier, address of variable)
    fclose(ptr);
    
    
    /*Writing in a file*/
    
    /*Type 1*/
    ptr = fopen("file.txt","w");    //Opening with intention of writing in the file and at this point the file is cleared
char write[100] = "This content will appear in the file replacing all others\n";
// fprintf(ptr, "This content will appear in the file replacing all others\n");   
fprintf(ptr,"%s",write);
fclose(ptr);

/*Type 2*/
ptr = fopen("file.txt","w");
fputc('p',ptr);
fclose(ptr);

/*Type 3*/
ptr = fopen("file.txt","w");  
fputs("I am an NITIAN",ptr);    


/*Function of read and write ie r+*/
ptr = fopen("file.txt","r+");   //This replaces the text in the starting
fputs("I am an NITIAN",ptr);    

/*
Example-
(Before) This is an already written file to check the function of r+
(After)  I am an NITIANeady written file to check the function of r+
*/

    /*FILE I/O OPERATIONS END*/

    
return 0;
}
