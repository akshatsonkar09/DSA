#include <stdio.h>




                        
                        /*FOR DISPLAYING ARRAY*/

void showarray(int arr[], int size) // Bracket ke andar woh parameters hai jinki need hai in function
// int arr[] is for selecting array int size is for defining how long I want the loop to run (using number instead of size will cause problem if we change the size of array later
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



                        /*FOR INSERTING ARRAY*/

int insertarray(int arr[], int size, int capacity, int index, int element) // constant mistake is writing int arr instead of int arr[]
{
    if (size >= capacity)
    {
        return -1;// Iss return -1 ki wajah se yeh int karna par raha hai warna void se bhi kaam ho jata (Future me - toh bhai return -1 hata ke simple printf kardete)
    }

    // This is wrong kyuki tumhe ek ek aage khiskana hai tab tak jab tak tumhara insert index khaali naa ho jaaye
    //     for (int i = 0; i < index; i++)
    //     {
    //         arr[i+1] = arr[i];
    //     }

    for (int i = size - 1; i >= index; i--) // size-1 likha hai instead of size kyunki array of size 4 sirf index 3 tak hota hai and initialize size-1 se hoga aur tabtak hoga jab tak insertion ke index tak naa aajaye ie jab tak i index se bada ho
    {
        arr[i + 1] = arr[i];
    }
    // Ab me loop se bahar hoon aur function ke andar
    arr[index] = element; // Mistake in this was not declaring element inside function

     return size + 1; // $$Function mujhe size badha ke dedega $$
}
/*
 "Left side is where I want to put the value, right side is what value I want to copy there."


 arr[i + 1] = arr[i];
✅ Meaning:
You want to move the value at i to i + 1.

You're shifting values to the right to make space.*/





                            /*FOR DELETING ARRAY*/
int deletearray(int arr[], int size, int index) {
for (int i = index ; i <= size-1; i++) //index+1 se isliye chalu nahi hoga kyunki neeche array i+1 ko i me laaya hun matlab index+1 me i hai index 3 ie 78 not 30 jo ki hai index 2 pe ie index 
{
    arr[i]= arr[i+1]; //array i+1 ko array i par laana hai
}
return size -=1;
}





int main()
{

    int arr[100] = {2, 4, 30, 78, 99};
    int insertarr[100];  //initialising new array as insertarr 
    int deletearr[100];
    int capacity = 100, index = 2, size = 5, element = 19;


    /*How to retain the original array even after insertion?*/
/*
1)Keep the original arr[] unchanged.
2)Make a new array like arr2[], copy the contents of arr into arr2.
3)Do insertion on arr2.
*/



    // Copy original array into insertarr
    for (int i = 0; i < size; i++) {
        insertarr[i] = arr[i];
    }
    // Copy original array into insertarr


    // Copy original array into deletearr
    for (int i = 0; i < size; i++) {
        deletearr[i] = arr[i];
    }
    // Copy original array into deletearr


    printf("Original Array:\n");
    showarray(arr, size);

    int incrementsize = insertarray(insertarr, size, capacity, index, element); // This line is calling the insertarray function, doing the insertion, and storing the new size of the array into the variable new_size. (Size = 5, new_size =6)

   /* int size = insertarray(insertarr, size, capacity, index, element); */ // This line is calling the insertarray function, doing the insertion, and storing and updating the int size of the array into new size ie size+1 .(Size = 5, Then size =6)
    
    
    //This is important because the array now contains one more element than before, so when you print it, you use new_size instead of the old size.

    printf("After Insertion (New Array):\n");
    showarray(insertarr, incrementsize);

    printf("Original Array Remains:\n");
    showarray(arr, size);

    // insertarray(arr, size, capacity, index, element);
    // size += 1;
    //showarray(arr,size);
    /*These two lines above are used when you dont want to retain original array and used to show array and update the size from 5 to 6*/

    /*What does size += 1; mean?
    It's a shorthand in C for:
    size = size + 1;
    It means you're increasing the value of size by 1.*/

    int decrementsize = deletearray(deletearr, size, index);

    printf("After Deletion (New Array):\n");
    showarray(deletearr, decrementsize);

    printf("Original Array Remains:\n");
    showarray(arr, size);

    return 0;
}