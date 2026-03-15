#include <stdio.h>
#include <string.h> // library hai in string
#include <stdlib.h> // for memory allocation 

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

void name (char string[]) {
    for (int i = 0; string[i]!='\0'; i++)
    {
        printf("%c",string[i]);
    }

    printf("\n");       //String print thru function but for loop
}

                        /*STRING END*/
    



                        /*STRUCTURE START*/
struct student {
    int roll;
    int marks;
    char grade; 
    char name[];
}/*akshat,sahil;*/;  //Aise pre define bhi kar sakte hai

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

typedef /**/ struct Student{int roll;  int marks;char grade;} /**/ std ;
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
//This shows that even if we use same variable it is not exactly same and are actually saved into two different spots
int func1 (int e) 
{
    printf("the address of e inside function is %d\n",&e);
    return e*10;
}
                        /*MISCELLANEOUS 1 END*/



                        /*GLOBAL,LOCAL AND STATIC VARIABLE START*/
int d; //This is a global variable since it can be used in entire code         
int func2 (int f) 
{
int loc;//This is a local variable since it can only be used inside the function 
    static int myvar = 0; //If my var is not given any value then it starts from 0
    printf("The value of myvar is %d\n", myvar);
    myvar++;
    return f+myvar;
//Instead of staring from the start the function remebers its last value when it was called then start from that value when called again
}
                        /*GLOBAL,LOCAL AND STATIC VARIABLE END*/


                        
                        /*MISCELLANEOUS 2 START*/
void reverse(char str[]) {
    int len = strlen(str);
    for(int j = 0; j < len / 2; j++) {
        char temp = str[j];
        str[j] = str[len - j - 1];
        str[len - j - 1] = temp;
    }
}
                        /*MISCELLANEOUS 2 END*/

                         
int main()
{
    printf("Hello World\n");

                        /*STRING START*/
// char name[27]; // Iska matlab hai ek character jisme 27 letters/characters hai agar sirf 5-6 characters use kiye toh uske aage garbage value aa jayegi aur usi se bachne ke liye humnull ka use karte hai toh ek name likhne ke liye word length + 1 ie null value daalne ki space jitni length chahiye hoti hai
char str[] = "Akshat";
printf("Using custom function ");
name (str);

printf("Using manual way ");
char arr[] = {'A','k','s','h','a','t','\0'};
name (arr); 


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

//puts(strcat(s1,s2)); This joins harry and ravi as harryravi and assign it in s1
printf("Length of Harry is %d\n", strlen(s1)); //Maine strcat ka use karke s1 and s2 ko join kardiya hai isliye strlen me s1 yaa s2 daalne par harryravi wala length milega

// s3 = strcat(s1,s2);  This will be false instead
strcpy(s3 ,strcat(s1,s2)); //This will work
puts(s3);
//HarryRavi bana kar usko s3 me store kar liya


printf("Reverse is \n");

puts(strrev(s1));
//puts(strrev(s1,s2));
/*
Compiler is not letting this code run saying too many arguments(Reason was that I could only use s1 not s1,s2) while chatgpt is saying that vs studio doesn't recognise strrev function and is saying to use below method(it does recognise just too many arguments)
*/

                        /*MISCELLANEOUS 2 START*/
printf("Reverse Again is ");
reverse(s1);
puts(s1);
                        /*MISCELLANEOUS 2 END*/

//You can find other string functions and use them the same way





                            /*STRUCTURE START*/

    struct student akshat,sahil; // yahan par structure ek local variable hai aur iss liye ise baar baar call nahi kar sakte
    // XXXXX data feed karne ka ek aur tareeka bhi hai jo ki screenshots me milega XXXXXX
  akshat.roll = 2;
  sahil.roll = 5;
  akshat.grade = 'b';
 
  printf("Akshat roll no is %d\n",akshat.roll);

  strcpy(akshat.name, "Akshat");
  printf("%s\n",akshat.name);
                            /*STRUCTURE END*/



                            /*TYPEDEF START*/    
//Syntax  --  tyypedef <previous_name> <alias_name> ;
/*Eg 1*/
typedef unsigned long ul;
ul l1,l2,l3;
/*Eg 1*/

/*Eg 2*/
std s4,s5;
s4.grade='A';
// Instead of student std is used
/*Eg 2*/

/*Eg 3*/
/* int *a,b; 
int c;
a = &c;
b = &c; 
This will give error
In this a is a pointer but b is stored as a simple integer but with typedef*/
typedef int* intptr;
intptr a,b;
int c;
a = &c;
b = &c; 
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
//This programme will give error as we are using multiple data types in same memory location

                            /*UNION END*/



                            /*MISCELLANEOUS 1 START*/
    int e = 4;
    printf("The address of e inside main is %d\n",&e);
    func1(e);
                            /*MISCELLANEOUS 1 END*/




                        /*GLOBAL,LOCAL AND STATIC VARIABLE START*/
    int f;                  
    int val = func2(f);
    val = func2(f);
                        /*GLOBAL,LOCAL AND STATIC VARIABLE END*/

// Lecture 44 of C of code with harry is good for making custom snippets ie custom formats of code





                        /*DYNAMIC MEMORY ALLOCATION START*/


    //Malloc me data void me store hota hai isliye typecast ka use karke int/char me change kar sakte hai

    // Malloc me ek specific byte size maangne ki jagah size of ke terms me maang lo kyunki har ek computer me int/data type ka size alag hota hai

    //Malloc and Calloc are almost same but two differences 
    //1) Malloc me direct x byte data allocate hota hai aur calloc me n times x byte data store hota hai
    //2) Malloc me memory exceed hone par garbage value aati hai aur calloc me 0

    int *ptr, n = 3;
    printf("Size of memory you want to assign\n");
    //scanf(%d,&n);
    ptr = (int*) calloc(n, sizeof (int));
    // ptr = (int*) malloc((n+1)*sizeof (int) or 37);

    for (int i = 0; i < n; i++)
    {
        printf("Value of %d is %d \n",i, &ptr[i]);
    }
    //Using scanf and another for loop you can also give value to your data instead of just there address

    ptr = (int*) realloc(ptr, (n+1)*sizeof (int));

    for (int i = 0; i < n+1; i++)
    {
        printf("New Value of %d is %d \n",i, &ptr[i]);
    } 
    //The old values and new values are same this means same memory is reallocated
    
    free(ptr); //This frees all the memories

    
                        /*DYNAMIC MEMORY ALLOCATION END*/

return 0;
}
