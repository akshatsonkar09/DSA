#include <iostream>

using namespace std;

/******CLASSES START******/
class employee
{
private:
    int salary, contractyears; // These cannot be accessed directly
public:                        // These can be accessed directly
    int experience, age;
    char favchar;

    // All this below needs to be inside the class if you want the functions to be outside class you need to use function prototyping

    // This is to get all the data
    void getdata()
    {
        cout << "Employees salary is " << salary << endl;
        cout << "Employees fav char is " << favchar << endl;
        cout << "Employees contract is " << contractyears << " years" << endl;
        cout << "Employees age is " << age << endl;
        cout << "Employees experience is " << experience << " years" << endl;
    }

    // This is to set data in private class
    void setdata(int a, int b)
    {
        salary = a;
        contractyears = b;
    }
};

// Class declaration is same as structure

class binary
{
    string s;

public:
    void read();
    void chk_bin();
};

// Way to use function prototyping in class
void binary ::read()
{
    cout << "Enter the binary number" << endl;
    cin >> s;
}

void binary ::chk_bin()
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1') // s.at is a string function which is used to traverse a string
        {
            cout << "Invalid Binary" << endl;
            exit(0); // This is used because otherwise
        }
    }
}

class complex{
    int a,b;    //Even without writing private this belongs to private class 

    public:
        //This is a constructor and runs automatically(kinda like innit function of python/c)
    complex(void) {
        a = 10;
        b = 5;
        cout<< "The imaginary number is " << a << " + " << b << "i" << endl;
    }
};

/******CLASSES END******/

int main()
{

    /*******CLASSES START******/
    employee akshat;

    // Setting public class
    akshat.age = 18;
    akshat.experience = 2;
    akshat.favchar = 'L';
    // akshat.salary = 200000;   This will throw error because it is private class

    akshat.setdata(200000, 5);
    akshat.getdata();

    cout << endl << endl;

    
    binary bin;

    bin.read();
    bin.chk_bin();
    cout << endl << endl;


    complex number;
    
    /*******CLASSES END******/

    return 0;
}