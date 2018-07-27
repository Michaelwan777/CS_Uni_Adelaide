// C++ program for insertion sort
#include <iostream>

using namespace std;

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        
        /* Move elements of arr[0..i-1], that are
         greater than key, to one position ahead
         of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

// A utility function ot print an array of size n
void printArray(int arr[], int n)
{
    int i;
    cout << "Sorted array by insertion sorting: " << endl;
    for (i=0; i < n; i++)
        cout << arr[i] << " ";
}

/* Driver program to test insertion sort */
int main()
{
    int arr[] = {9,7,8,3,6,1,2,4,3,2,1,4,6,7,8,6,4,4,5,6,5,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    insertionSort(arr, n);
    printArray(arr, n);
    cout << endl;
    
    return 0;
}