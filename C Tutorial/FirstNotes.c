#include <stdio.h>
#define pie 3.14    //Value of pie is absolute defined if any other value is specified then it will show error

int main()
{

       printf ("Hello World\n");

       // \n for end line or called escape sequence and is one single character
       // other backslash sequences can be used for different purposes

       printf("Hello \t \"New World\n");
       // \t will give tab space and \" or \' for quotes
    
    //Start of Algebraic
        int a,b;
        a=4;
        printf ("Number A is %d\n", a);
        printf ("Number B is ");
        scanf("%d", &b);

        printf("Sum %d and %d is %d\n",a,b, a+b);
        //This ends Algebraic

        /*  $$ %d means make space for a integral value
        if %d(format specifier) used two time then has to assign both times and if three so three time and so on $$ */


        //Sizeof Start

    
    printf("Size of Int is %zu\n", __SIZEOF_INT__);
    printf("Size of Float is %zu\n", sizeof(float));
    printf("%zu\n", sizeof(char));
    
    /*Sizeof End
    Int only gives integer 
    Float gives 6 decimal points
    Double and long double even furthur*/


    /*Operators Start
    $$You can use Alt + Click for multi cursor$$*/
    
    int c,h;
    c=34;
    h=6;

    printf("c+h = %d\n", c+h);
    printf("c-h = %d\n", c-h);
    printf("c*h = %d\n", c*h);
    printf("c/h = %d\n", c/h);
    printf("ch = %d\n", c%h);

    //This end Integer Operators
    //Start of Float Operators

int a = 65;
    int e;
    float f;
    e=34;
    f=6.34;

    printf("e+f = %f\n", e+f);
    printf("e-f = %f\n", e-f);
    printf("e*f = %f\n", e*f);
    printf("e/f = %f\n", e/f);

    /*  %d is for integers while %f is for floating variables
    For some reason int%float does not work and shows error (Answer- modulus operator % only works with integer types.)
    % gives remainder and is called modulus
    $$ I am unable to take fraction/float value and use it as an integral value $$
    */


   /*Relational Operators*/
    int i,j;
    i=34;
    j=6;

    printf("i is equal to j = %d\n", i==j);
    printf("i is not equal to j = %d\n", i!=j);
    printf("i is greater than j = %d\n", i>j);
    printf("i is less than j = %d\n", i<j);
    printf("i is greater or equal to than j = %d\n", i>=j);
    printf("i is less or equal to than j = %d\n", i<=j);
    
    //For true 1 and For false 0 is returned
    /*Relational Operators Ends*/

    /*Logical Operators Start*/

    int k,l;

   k=0;
   l=34;

   printf("Both Satisfy = %d\n", k&&l);
   printf("Atleast One Satisfy = %d\n", k||l);
   printf("Condition of Both Satisfy then output Reversed = %d\n", !k&&l);

   /*These condition are only satisfied when input is integer except 0 ie 32 and 42 satisfy conditions
   For not output put ! mark*/
   /*Logical Operators Ends*/



   /*Bitwise Operator Start*/

   /* & is and: | is or: ^ is Xor gates and 
   are calculated in binary form*/

    /*Eg 2 = 10 and 3 = 11
    So first place of both is compared and then second place of both is compared*/

    int m,n;

   m=1;
   n=2;

   printf("And Gate = %d\n", m&n);
   printf("Or Gate = %d\n", m|n);
   printf("XOR Gate = %d\n", m^n);

   /* a & b gives a non-zero result only if at least one bit position is 1 in both a and b.
   eg int a = 6;  // Binary: 00000110
        int b = 3;  // Binary: 00000011*/

        // Not only 1 and 0 but &/| in binary and answer in numeral
        // Useful for fast calculations and low runtime
        // $$Do not confuse OR/AND for addition$$
    /*Bitwise Operator End*/

      
   float o;

   o=8.356;
   
   printf("Value of b is %9.6f\n",o);
   printf("%10.2f", 3.14);
   printf("%010.2f", 3.14);   // width = 10, padded with zeros → "0000003.14"

   /* 9.6 tell us to leave space for characters and upto 6decimal places
    if we add negative sign then succeeding space left otherwise preceeding space is vacant  */

    //////// In C constant is something which cannot be changed or absolute value

    int p = 3;
    p= 4;
    printf("%d\n",p);

    // This is to tell that if there are no operators then I can change my variable 'p from 3 to 4'
    // To prevent this use const function or predefined function(at top)

   /*
    const int q = 5;
    q=7;
    printf("%d",q);
    */   // This program will show error


                        /*My exerecise 1 Start*/

    
    /*char ch= 'M';
    char ch= 'S';
    char ch= 'MS';
    This is wrong only below part is needed*/

    char ch= 'Q'; //Still not sure about declarations
    // char ch = 'A';  Correct way
    // char ch = 'AB"; Wrong cannot use 2 letters

    printf("We are giving gifts to students who have passed exams of \n 1) Maths(Q)\n 2) Science(S)\n 3)Maths and Science Both(R)\n Please enter which Exam you passed\n");

    
    scanf(" %c", &ch); //This part is weak
    

    if (ch=='Q'||ch=='q')  /*character should always be in inverted quotes
     ||(or gate) is used for mulitple commands*/ 

    {
        printf("You are awarded 15 Points\n");
    }
    
    else if(ch == 'S'||ch == 's')
    {
        printf("You are awarded 15 Points\n");
    }

    else if(ch=='R'||ch=='r')  //char==MS cannot be used as it is two letters
    {
        printf("You are awarded 45 Points\n");
    }

    /*Very Important concept of using space before %c
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
                        /*Exercise 1 End*/



                        /*Switch Start*/

        /*Switch Program Type 1*/
        /*In this type marks input is inside case function*/
    int age, marks; //Error made ---> int=age,marks;
    age = 3;
    marks = 45;
     
     
     /*  1) No semicolon in switch and curly brackets for cases until end
    2)Switch is a substitute for if else if 
   3)Break can be removed but if there is no break then code will not terminate after finding correct case but will execute complete code and will give default statement as weel so use according to need
   4) case 3 is not third case but case where entered value is 3   */


   switch(age)
    {
    case 3:
        printf("Enter Your Age - 3\n");
        printf("Your Age is 3\n");

        printf("Enter Your Marks - 45\n");
        //scanf("%d", &marks);      (If marks input from user)

            switch(marks)
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

int AGE,MARKS;
AGE=3;
MARKS=45;

printf("Enter Your AGE - 3\n");
//scanf("%d", &AGE);    (If age input from user)
printf("Enter Your MARKS - 45\n");
//scanf("%d", &MARKS);      (If marks input from user)

    switch(AGE)
    {
    case 3:
        printf("Your AGE is 3\n");

            switch(MARKS)
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

int num, index=0;    //Mistake was not defining starting point of I

printf("Enter Your Number\n");
scanf("%d", &num);

    /*Do While Start*/
    
do {
   printf("Loop numbers are %d\n", index);
   index=index+1;       //Forgot to write this
}
while (index<num);  

    /*Do While End*/


    /*Do While without user input*/

int IN=0;
do
{
    printf("%d", IN);
    IN=IN+1;
} 
while (IN<20);

    /*Do While without user input*/


    /*While Loop Start*/

int I=0;

    while (I<20)
    {
        printf("%d", I);
        I=I+1;
    }

    /*While Loop End*/

    /*For Loop Start*/

    /*Different Ways to write For Loop*/


    int x;
    for(x=0; x<5; x++) { //agar kaafi saari condition daal di toh execute toh   sabko karega lekin maanega sirf last wale ko
        printf(" 1st For %d \n",x);
    }

    int X=0; //pehele define kar diya toh bhi chalega
    for(; X<5; X++) {      //semicolon lagega par aur 1st expression khali rahega
        printf("2nd For %d\n",X);
     }

    int y, z=0; //saath me do bhi define kar sakte hai
    for(y=0; z<5; z++) {      //semicolon lagega par aur 1st expression khali rahega
        printf("3rd For %d %d\n",z,y);
     }

    int w=0;   //pehele define kar diya toh bhi chalega
    for(; w<5;) {      //semicolon lagega par aur 1st expression khali rahega
        printf("Pehle Define %d\n",w);
        w++;        // baad me bhi define kar sakte hai
     }

     //Basically jab marzi tab jo chahe woh define karlo

    int try=0;
     for(;try<=10;try++)            //Agar sirf ek hi line hai toh curly brackets ki need nahi hai
        printf("Try %d\n",try);

    for(int newtry=0; newtry<8; newtry++)       //int for me bhi define kar sakte ho
    printf("New Try %d\n", newtry);

   return 0;
}
