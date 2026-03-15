#include <stdio.h>
#include <string.h>



int main() {

char numb[34];
printf("Enter the number\n");
scanf("%s",numb);

char original[34];
strcpy(original,numb);

strrev(numb);
printf("The reversed number is %s\n",numb);


if (strcmp(original,numb) == 0)
{
    printf("Number is palindrome");
}
else
{
    printf("Number is not palindrome");
}
return 0;

}