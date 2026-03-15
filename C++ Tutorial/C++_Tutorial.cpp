#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
/*

#include <bits/stdc++.h>

Meaning - 
This line includes all standard C++ header files in one go.

#include → is a preprocessor directive that tells the compiler to include the contents of another file before compilation.

<bits/stdc++.h> → is a non-standard header file that comes with GCC (GNU Compiler Collection), mainly used in competitive programming.

The name bits/stdc++.h literally means:
bits/ → refers to the folder inside the GCC include directory.
stdc++.h → stands for Standard C++ Headers.

So this line essentially means:

“Include all the standard C++ libraries at once.”


🔹 What It Actually Includes

It includes almost everything you might need:

All standard C and C++ headers like
<iostream>, <vector>, <string>, <map>, <algorithm>, <cmath>, <set>, <queue>, etc.

Basically, you won’t have to write multiple #include statements manually.


🔹 Why It’s Not Recommended in Real Projects

Non-standard: It’s not part of the official C++ standard, so it won’t work on compilers like MSVC (Microsoft Visual C++).

Slower compilation: It includes all libraries, even if you only need one or two.

Poor readability: It hides which libraries your program actually depends on.

🔹 When It’s OK to Use

Competitive programming (Codeforces, LeetCode, AtCoder, etc.) &
Quick prototypes or learning/testing code.

✅ Better (Standard) Way

Instead of:
#include <bits/stdc++.h>

You should write:

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


This is portable, faster to compile, and standard-compliant.
*/


using namespace std;

// In contrast to C, C++ supports classes and objects, while C does not



    /******LOCAL AND GLOBAL VARIABLE START******/

int A = 5; // global variable

void func(){
    cout <<"Global variable is " << A << endl;
}

    /******LOCAL AND GLOBAL VARIABLE END******/






    /*******STRUCTURE START******/

    /*
    struct eymployee
    {
        int eID;
        char favchar;
        long salary;
    };
    Typedef used to shorten the  names
    In C++ typedef is by default
    */

    typedef struct Employee
    {
        int eID;
        char favchar;
        long salary;
    } ep;

    /*******STRUCTURE END******/
    




    /*******UNION START******/
    union form_of_money
    {
        int rice;
        char car;
        long salary;
    };
    /*
    Since we will be using only datatype one at a time then why not give them just one memory block and use the one in use. That's what union do. To preserve space
    */
    
    /*******UNION END******/



    /*******ENUM START*******/
    enum Meal
    {breakfast, lunch, dinner};
    /*******ENUM END*******/




   /******FUNCTION PROTOTYPING START******/

    int sum(int a, int b);
    // int sum(int a, int b) {} this will not work

   /******FUNCTION PROTOTYPING END******/


   /******CLASSES START******/
   class employee {
    private:
        int salary, contractyears;      //These cannot be accessed directly
    public:                             //These can be accessed directly
        int experience, age;
        char favchar;


        //All this below needs to be inside the class if you want the functions to be outside class you need to use function prototyping  

        //This is to get all the data
        void getdata() {
         cout << "Employees salary is " << salary << endl;
         cout << "Employees fav char is " << favchar << endl;
         cout << "Employees contract is " << contractyears << " years" << endl;
         cout << "Employees age is " << age << endl;
         cout << "Employees experience is " << experience << " years" << endl;
        }
     
        //This is to set data in private class
        void setdata(int a,int b) {
         salary = a;
         contractyears = b;
        }

   };

   //Class declaration is same as structure
   
   
   class binary {
       string s;
       public:
       void read();
       void chk_bin();
    };
    
    //Way to use function prototyping in class
    void binary :: read() {
        cout << "Enter the binary number" << endl;
        cin >> s;
    }
    
    void binary :: chk_bin() {
        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) != '0' && s.at(i) != '1')   //s.at is a string function which is used to traverse a string
            {
                cout << "Invalid Binary" << endl;
                exit(0);    //This is used because otherwise 
            }
        }
    }
    
    
    /******CLASSES END******/


int main()
{

    /******CONSTANT VARIABLE******/

    const float PI = 3.14; // value cannot be changed afterwards.
    // PI = 3.00; //error - since changing a const variable is not allowed.

    /******CONSTANT VARIABLE******/
    
    
    /******INPUT AND OUTPUT START******/
    //cout<<   //This is insertion operator(<<)
    //cin>>   //This is extraction operator(>>)
    int num;
    cout << "Enter the number" << endl;
    cin>>num;
    cout << "Your number is " << num << endl;
    /******INPUT AND OUTPUT END******/

    

    cout << "Hello World" << endl;
    std::cout << "Hello World\n";


    cout<< endl << endl;
    /******HOW TO TAKE ENTIRE LINE AS INPUT START******/
    //Method 1-
    cout << "Enter a two word string"<< endl;
    string s1,s2;
    cin >> s1 >> s2;
    cout << s1 << " " << s2 << endl;
    //But only two words possible so not preferable
    
    
    /*If you used cin >> before getline that is something like this before:
    
    int x;
    cin >> x;
    getline(cin, str); // <-- this will SKIP input
    
    
    Then getline reads the leftover newline (\n) from the previous input and ends immediately.
    
    Fix:
    Add an extra cin.ignore() before getline:
    
    int x;
    cin >> x;
    cin.ignore();       // clear leftover newline
    getline(cin, str);*/
    
    
    //Method 2-
    string str;
    cin.ignore();
    cout << "Enter a line string"<< endl;
    getline(cin,str);
    cout << str << endl;
    
cout<< endl << endl;

    /******HOW TO TAKE ENTIRE LINE AS INPUT END******/


    /******LOCAL AND GLOBAL VARIABLE START******/
    int A = 10; // local variable
    cout << A << endl;  //Precedence is given to local variable
    func();
    cout <<"Global variable through scope resolution operator "<< ::A << endl;    // Way to get global variable through scope resolution operator in int maincout<< endl << endl;
    /******LOCAL AND GLOBAL VARIABLE END******/





    /******OPERATORS START******/
    
    int a = 4, b = 5;
    
    /*ARITHMETIC OPERATORS*/
    cout << "The value of a + b is " << a + b << endl;
    cout << "The value of a - b is " << a - b << endl;
    cout << "The value of a * b is " << a * b << endl;
    cout << "The value of a / b is " << a / b << endl;
    cout << "The value of a % b is " << a % b << endl;
    cout << "The value of a++ is " << a++ << endl;
    cout << "The value of a-- is " << a-- << endl;
    cout << "The value of ++a is " << ++a << endl;
    cout << "The value of --a is " << --a << endl;
    /*ARITHMETIC OPERATORS*/
    
    /*RELATIONAL OPERATORS*/
    cout << "The value of a == b is " << (a == b) << endl;
    cout << "The value of a < b is " << (a < b) << endl;
    cout << "The value of a > b is " << (a > b) << endl;
    /*RELATIONAL OPERATORS*/
    
    /*LOGICAL OPERATORS*/
    cout << "The value of a && b is " << (a && b) << endl;  //All non-zero values are considered true
    cout << "The value of a || b is " << (a || b) << endl;
    cout << "The value of !a is " << (!a) << endl;
    /*LOGICAL OPERATORS*/
    
    /*BITWISE OPERATORS*/
    cout << "The value of a & b is " << (a & b) << endl;
    cout << "The value of a | b is " << (a | b) << endl;
    cout << "The value of a ^ b is " << (a ^ b) << endl;
    cout << "The value of ~a is " << (~a) << endl; //??????
    cout << "The value of a >> 2 is " << (a >> 2) << endl;  
    cout << "The value of a << 2 is " << (a << 2) << endl;  
    /*BITWISE OPERATORS*/
    cout<< endl << endl;
    /******OPERATORS END******/



    /******TYPECASTING START******/
    float d = 34.4f;
    long double e = 34.4l;
    
    cout << "Size of 34.4 is " << sizeof(34.4) << endl;     //By default value is taken as double in C++
    cout << "Size of 34.4f is " << sizeof(34.4f) << endl;   // Explicitly Typecasted to float
    cout << "Size of 34.4F is " << sizeof(34.4F) << endl;   // Explicitly Typecasted to float
    cout << "Size of 34.4l is " << sizeof(34.4l) << endl;   // Explicitly Typecasted to long double
    cout << "Size of 34.4L is " << sizeof(34.4L) << endl;   // // Explicitly Typecasted to long double
    
    /*
    1) 34.4 → is a double literal by default.
    2) You’re assigning it to a float variable (d).
    3) So, the compiler converts (or casts) the double to a float. (implicit typecasting)
    
    Expression	            Literal Type    Variable Type	Conversion?
    float d = 34.4;	        double          float           ✅ Yes (double → float)
    float d = 34.4f;	    float	        float           ❌ No conversion
    long double e = 34.4;	double	        long double     ✅ Yes (double → long double)
    long double e = 34.4L;	long double	    long double	    ❌ No conversion
    */

    cout << "Value of d in integer datatype is " << (int)d << endl;
    cout << "Value of e in integer datatype is " << int(e) << endl;
        //Both ways are correct
cout<< endl << endl;
    /******TYPECASTING END******/
    


    
    /******REFERENCE VARIABLE START******/  //IMPORTANT

    //Alias to a variable changing in one changes both
    d = 54.6;
    // int &y = d;   Will throw error due to float and int
    float &D = d;

    cout << d << endl;
    cout << D << endl;

    cout << "Address of d is " << &d << endl;
    cout << "Address of D is " << &D << endl;

    //int& r = x;               //Reinitialization is not allowed
    // &r = y;                 // 1. Compile Error
cout<< endl << endl;
    /******REFERENCE VARIABLE END******/



    /******MANIPULATOR START******/
    a = 2;
    b = 45;
    int c = 456;

    cout << "The value of a with setw is " << setw(5) << a << endl;
    cout << "The value of b with setw is " << setw(5) << b << endl;
    cout << "The value of c with setw is " << setw(5) << c << endl;
cout<< endl << endl;
    // This leaves width of 5 in a,b,c
    /******MANIPULATOR END******/
    
    
    /******IF-ELSE(CONTROL STATEMENT) START******/
    int age;
    cout << "Enter a number: ";
    cin >> age;
    if (age >= 50)
    {
        cout << "Input number is greater than 50!" << endl;
    }
    else if (age == 50) //elif doesn't work
    {
        cout << "Input number is equal to 50!" << endl;
    }
    else
    {
        cout << "Input number is less than 50!" << endl;
    }cout<< endl << endl;
    /******IF-ELSE(CONTROL STATEMENT) END******/
    
    
    
    /******SWITCH START******/
    a = 2;
    switch (a)
    {
        case 1:
        cout << "Statement 1" << endl;
        break;
        
        case 2:
        cout << "Statement 2" << endl;
        break;
        
        default:
        cout << "Default statement!" << endl;
    }
cout<< endl << endl;
    //If there is no break statement then all cases after the case which is true will print
    /******SWITCH END******/
    
    
    /******LOOPS START******/
    
    /*FOR LOOP*/
    for (int i = 0; i < 10; i++)    //i is only in scope of for loop and not outside the loop
    {
        cout << i << " ";
    }
    cout<<endl;
    /*FOR LOOP*/
    
    /*WHILE LOOP*/
    int i = 0;
    while (i < 10)
    {
        cout << i << " ";
        i++;
    }
    cout<<endl;
    /*WHILE LOOP*/

    
    /*DO WHILE LOOP*/
    do
    {
        cout << i << " ";
        i++;
    } while (i < 5);
    cout<<endl;
    /*DO WHILE LOOP*/
cout<< endl << endl;

    /******LOOPS END******/


    /*
    There are break and continue statements as well in C which does the same work as they do in every other language in control statements only
    */

    /******ARRAY START******/
    // int arr[] = {1, 2, 3};  Both correct
    int arr[3];
    arr[0] = 1, arr[1] = 2, arr[2] = 3;
    arr[2] = 8; //changing the element on index 2

    int mul_arr[3][4];  //Multidimensional array
    mul_arr[1][2] = 34;
    cout << mul_arr[1][2] << endl;

cout<< endl << endl;
    //VERY IMPORTANT - In functions arrays always goes by reference and not the copy so any change in function will be reflected in the array itself and not just its copy
    /******ARRAY END******/




    /******POINTERS START*******/
    
    /*
    The ‘&’(ampersand) operator is called the ‘address of’ operator, and the ‘*’(asterisk) operator is called the ‘value at’ dereference operator. 
    */
   a = 100;
   int *f = &a;
   int **g = &f;
   
   
   cout << "Address of variable a is " << &a << endl;
   cout << "Address of variable a using f is " << f << endl;
   // cout << "Address of variable a is " << g << endl;   //address of a using g?   Wrong, this will give adress of f
   cout << "Address of variable a using gis " << *g << endl;       //    *g dereferences g (which is &f) → gives f; f = &a; ✅ So *g == &a
   
   
   cout << "Value of variable a is " << a << endl;
   cout << "Value of variable a/ Value at address f is " << *f << endl;
   cout << "Value of variable a/ Value at address g is " << **g << endl;
   
   cout << "Value of variable a stored at address of a is " << (*(&a)) << endl;    //Indirection Operator
   
   cout << "Address of pointer f is " << &f << endl;
   cout << "Address of pointer f is " << g << endl;
   
   cout << "Value at pointer f is " << *f << endl;
   cout << "Value at pointer f through g is " << **g << endl;
   
   cout << "Address of pointer g is " << &g << endl;
   cout << "Value at pointer g is " << **g << endl;
   cout<< endl << endl;
   /******POINTERS END*******/


   /******POINTERS AND ARRAY START*******/

   int marks[] = {2,4,3,65,12,32};
    //int *p = &marks[0];  //Both are same
   int *p = marks;

   for(int i = 0; i< (sizeof(marks)/sizeof(int)); i++) {
    cout << "Value at index " << i << "  is " << *(p+i) << endl;
   }cout<< endl << endl;
   /******POINTERS AND ARRAY END*******/


   /******STRINGS START******/
    str = "CodeWithHarry";       //string string_name = "string_line";
    cout << str << endl;

    //To typecast to string
    a = 40;
    string conversion = to_string(a);

    cout <<"Typecasted to string integer" << conversion << endl;
    cout<< endl << endl;


    /*Slicing in C++ Start*/
    // This is wrong - s[0][0:3] (like we do in python)
    // In c++ we do
    
    cout<< s[0].substr(0,3)<< endl;
    /*Slicing in C++ End*/


   /******STRINGS END******/

    /*******STRUCTURE START******/
    ep harry;
    harry.eID = 225;
    harry.salary = 1200000;
    harry.favchar = 'H';
    /*******STRUCTURE END******/


    /*******UNION START******/
    union form_of_money m1_union;
    m1_union.rice = 34;
    /*******UNION END******/

    /*******ENUM START*******/
    Meal m1 = dinner;
    cout << "The value of dinner is " << dinner << endl;
    /*******ENUM END*******/
    
    
    
    /*******CALLING OF FUNCTION START*******/
    /*
    int a = 5, b = 6;
    
    //CALL BY VALUE//
    //    A copy is taken and no change in actual values
    
    void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    }
    Before -> a=5, b=6
    After -> a=5, b=6
    
    
    //CALL BY REFERENCE//
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    Before -> a=5, b=6
    After -> a=6, b=5
    
    
    //CALL BY POINTER//
    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    Before -> a=5, b=6
    After -> a=6, b=5
    
    */
    /*******CALLING OF FUNCTION END*******/

   /******FUNCTION PROTOTYPING START******/
   a = 2, b = 3;    //This also works
   cout<< sum(a,b);
   /******FUNCTION PROTOTYPING END******/
   
   
   /******FUNCTION OVERLOADING START******/
   
   /*
   Function overloading means having multiple functions with the same name but different parameters (either in type, number, or order).
   The compiler automatically decides which function to call based on the arguments you pass.
   
   Example of parameter number and order
   void add(int a, int b);
   void add(double a, double b);
   void add(int a, double b);
   These all coexist without conflict because the parameter signatures are different.
   
   Invalid overloading example
   You cannot overload by return type alone:
   int sum(int a, int b);
   double sum(int a, int b); // ❌ ERROR: same parameter list
   */
  
  /******FUNCTION OVERLOADING END******/

   /******STRIVERS BASIC C++ ONE SHOT******/
   string s = "Akshat";
   cout << s[2]<< endl;
   int len = s.size();
   cout << s[len-1]<< endl;
   s[3] = 'r';cout<< endl << endl;
   /******STRIVERS BASIC C++ ONE SHOT******/



    /*******CLASSES START******/
    employee akshat;

    //Setting public class
    akshat.age = 18;
    akshat.experience = 2;
    akshat.favchar = 'L';
    //akshat.salary = 200000;   This will throw error because it is private class

    akshat.setdata(200000,5);
    akshat.getdata();


    binary bin;

    bin.read();
    bin.chk_bin();
cout<< endl << endl;
    /*******CLASSES END******/

  return 0;
}

    /******FUNCTION PROTOTYPING START******/
    int sum (int a, int b) {
    return a+b;
}
    /******FUNCTION PROTOTYPING END******/