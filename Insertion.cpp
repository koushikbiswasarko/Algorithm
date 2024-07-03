#include <iostream>
using namespace std;

void insertion_sort (int arr[], int n)
{
    int start, on_hand, current;

    for (start = 1; start < n; start++)
    {
        on_hand = arr[start];
        current = start - 1;

        while (current >= 0 && arr[current] > on_hand)
        {
            arr[current + 1] = arr[current];
            current = current - 1;
        }
        arr[current + 1] = on_hand;
    }
}

int main()
{
    int arr[] = {10, 9, 8, 7, -6, 5, -4, 3, -2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    insertion_sort(arr, n);

    cout << endl;

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
