#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n)
{
    for (int start = 0; start < n; start++)
    {
        bool swapped = false;

        for (int current = 0; current < n-1; current++)
        {
            if (arr[current] > arr[current + 1])
            {
                swap(arr[current], arr[current + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }
    }
}

int main ()
{
    int arr[] = {9, 5, 7, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: " ;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " ;
    }

    cout << endl;
    cout << endl;

    bubble_sort(arr, n);

    cout << "Sorted array: " ;

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " " ;
    }

    cout << endl;
}
