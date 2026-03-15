#include <stdio.h>

 // Maine apne code me array daale ke value bana diya tha but switch me uski koi need hi nahi hai same int function can be used in different cases
int main() {


/*MY WAY*/

int num;
float value;

label:
    printf("Hello World\n");
    printf("Select What type of conversion you want\n");
    printf("For :\n");
    printf("1) Kilometer to Meters --> Press 1\n");
    printf("2) Inches to Foot --> Press 2\n");
    printf("3) Centimeters to Meters  --> Press 3\n");
    printf("For Exit Press 9 :\n");
    printf("For ReTry Press 0 :\n");

    scanf("%d", &num);

    switch (num)
    {
    case '1':
        printf("Enter the number ");
        scanf("%f", &value);
        printf("%f Kilometers in Miles is %f\n", value, value*1000);
        break;

    case 2:
        printf("Enter the number ");
        scanf("%f", &value);
        printf("%f Inces in Feet is is %f\n", value, value/12);
        break;
    

    case 3:
        printf("Enter the number ");
        scanf("%f", &value);
        printf("%f Centimeters in Meters is %f\n", value, value/100);
        break;

    case 0:
        goto label;
        break;

    case 9:
    goto end;
    break;
    
    default:
    printf("Not a valid Input\n");
    goto label;

        break;
     }
     goto label;

     end:
     printf("Thank You");

     /*My way*/

     /*Sir's Code*/
   /*  #include <stdio.h>

int main()
{
    char input;
    float kmsToMiles = 0.621371;
    float inchesToFoot = 0.0833333;
    float cmsToInches = 0.393701;
    float poundToKgs = 0.453592;
    float inchesToMeters = 0.0254;
    float first, second;

    while (1)
    {
        printf("Enter the input character. q to quit\n");
        printf("1. kms to miles\n2. inches to foot\n3. cms to inches\n4. pound to kgs\n5. inches to meters\n");

        scanf(" %c", &input); // Note: there is a space before %c to consume any leftover newline

        printf("Enter quantity in terms of first unit\n");
        scanf("%f", &first);

        switch (input)
        {
        case 'q':
            printf("Quitting the program...");
            goto end;
            break;

        case '1':
            second = first * kmsToMiles;
            printf("%f Kms is equal to %f Miles\n", first, second);
            break;

        case '2':
            second = first * inchesToFoot;
            printf("%f Inches is equal to %f Foot\n", first, second);
            break;

        case '3':
            second = first * cmsToInches;
            printf("%f Cms is equal to %f Inches\n", first, second);
            break;

        case '4':
            second = first * poundToKgs;
            printf("%f Pounds is equal to Kgs %f\n", first, second);
            break;

        case '5':
            second = first * inchesToMeters;
            printf("%f inches is equal to %f meters\n", first, second);
            break;

        default:
            printf("this");
            break;
        }
    }
end:
    return 0;
}
*/

    return 0;
}
