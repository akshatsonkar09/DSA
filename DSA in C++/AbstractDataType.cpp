#include <iostream>
#include <vector>

using namespace std;

class myArray
{

private:
    int reservesize;
    int usageSize;
    vector<int> data;

public:
    // Constructor? -- learned but be cautious
    // Constructor = createarray -> instead of assigning things in createarray function we can directly assign them on the spot. Basically it is struct array and create array in one

    myArray(int max, int usage)
        : reservesize(max), usageSize(usage), data(max) {}

    void enterArray()
    {
        for (int i = 0; i < usageSize; i++)
        {
            cout << "Enter " << i << " element: ";
            cin >> data[i];
        }
        cout << "\n";
    }

    void showArray() const
    {
        for (int i = 0; i < usageSize; i++)
        {
            cout << "Element " << i << " : " << data[i] << '\n';
        }
        cout << "\n";
    }
};

int main()
{
    myArray arr(10, 2);
    arr.enterArray();
    arr.showArray();

    return 0;
}