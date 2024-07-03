#include <iostream>
using namespace std;

void selection_sort (int arr[], int n)
{
    int start, current, minimum;

    for (start = 0; start < n-1; start++)
    {
        minimum = start;

        for (current = start + 1; current < n; current++)
        {
            if (arr[current] < arr[minimum])
            {
                minimum = current;
            }
        }

        if (minimum != start)
        {
           swap(arr[minimum], arr[start]);
        }
    }
}

int main ()
{
    int arr[] = {9, 5, 7, 1, 3};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << endl;

    selection_sort(arr, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;


}
