#include <iostream>
using namespace std;


int partition (int arr[],  int low, int high)
{
    int left, right, pivot_item;
    pivot_item = arr[low];
    int pivot = left = low;
    right = high;

    while (left < right)
    {
        while (arr[left] <= pivot_item)
        {
            left++;
        }
        while (arr[right] >= pivot_item)
        {
            right--;
        }
        if (left < right)
        {
            swap (arr[left], arr[right]);
        }
    }
    arr[low] = arr[right];
    arr[right] = pivot_item;
    return right;
}


void Quick_Sort(int arr[], int low, int high)
{
   int pivot;

   if (high > low)
   {
       pivot = partition (arr, low, high);
       Quick_Sort(arr, low, pivot-1);
       Quick_Sort(arr, pivot+1, high);
   }
}


int main ()
{
    int arr[] = {23, 12, -15, 38, -42, 18, 36, -29, 27};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    Quick_Sort(arr, 0, n - 1);

    cout << endl;

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
