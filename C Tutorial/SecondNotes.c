#include <stdio.h>


int main()
{
    printf("Hello World\n");

    /*LOOP START*/

    int i, age;
    for (i = 0; i < 10; i++)// First is kahan se start karna hai Second is kab band karna hai(more appropriate)\kab tak karna hai, last is increment karna hai yaa decrement in i
    {
        printf("%d\n Enter Your Age\n",i);  //break is basically used to break loop if undesired thing happens
        scanf("%d", &age);  //Isme scanf andar hai isliye yeh output maangta rahega tab tak jab loop naa pura hojaye yaa phir break statement naa lag jaaye
        if (age>10)
        {
            break;
        }
    }

        /*LOOP END*/

        /*CONTINUE START WEAK*/

    int I, AGE;
    scanf("%d", &AGE); //Isme ek baar age daalni padegi
    for(I=0; I<10; I++)
    {
        printf("%d\n",I); //Zero iss line ki wajah se aa raha hai
       // scanf("%d", &AGE); //baar baar value daalni padegi cause loop me baar baar scanf aayega 
        if (AGE<10)
        {
            continue;
        }

        printf("No continue Statement Found\n");
    }
        /*CONTINUE END*/
        /*Go To Statement Start*/
    
label:
    printf("We are inside loop\n");
      goto end;   //This is not termination but command to go to end statement 
      //Because of this Hello world print nahi hoyega aur end statement print hogi
      //Agar yeh naa hota toh goto label par wapas aa jata kyunki neeche goto label hai aur infinit eloop chalu ho jayega 
      printf("Hello World\n");
      goto label;
      end:
         printf("We are at end\n");
     
         /* for loop me agar break lagao toh woh sirf previous for loop se bahar nikalta hai lekin agar goto end bana de aur sab loops se bahar ek end statement me break laga de toh woh saare loops se bahar nikaal dega*/
        
         /*GOTO END*/






         /*TYPECASTING START*/


   //Typecasting is changing type of variable from one into another

   //float a = 54/5;  //float me agar koi integral arithmetic karoge toh compiler usko automatically integral me kar deg yaani 10 aayega naa ki 10.8
      /*Type 1*/
   float a = (float) 54/5; //isme typecast ne int to float me convert karwa diya aur value 10.8 aayegi

   printf("The value of a is %f\n", a);

      /*Type 2*/
   float b = 2.55;
   printf("The value of b is %f\n", (float) b);



               
    return 0;
}
