#include <iostream>
using namespace std;

int binary_search (int arr[], int n, int target)
{
    int low = 0;
    int high = n-1;
    int mid;

    while (low <= high)
    {
        mid = (low + high)/2;

        if (arr[mid] == target)
        {
            return mid;
        }

        else if (arr[mid] < target)
        {
            low = mid +1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main ()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Input Target: ";
    cin >> target;

    cout << endl;

    int result = binary_search(arr, n, target);

    if (result != -1)
    {
        cout << target << " is found at index: " << result << endl;
    }
    else
    {
        cout << target << " is not found" << endl;
    }

}
