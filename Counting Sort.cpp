#include <iostream>
using namespace std;

void counting_sort(int arr[], int n)
{

    int c_arr[100] = {0};

    cout << "Array: ";

    for (int i = 0; i<=n; i++)
    {
        cout << c_arr[i] << " ";
    }

    cout << endl;

    for (int j = 0; j < n; j++)
    {
        c_arr[arr[j]] = c_arr[arr[j]] + 1;
    }

    cout << "Counting Array: ";

    for (int i = 0; i<=n; i++)
    {
        cout << c_arr[i] << " ";
    }

    cout << endl;

    for (int i = 1; i <=n; i++)
    {
        c_arr[i] = c_arr[i] + c_arr[i - 1];
    }

    cout << "Update Count: ";

    for (int i = 0; i<=n; i++)
    {
        cout << c_arr[i] << " ";
    }

    cout << endl;

    cout << "Output Array: ";

    int o_arr[n];

    for (int j = n - 1; j >= 0; j--)
    {
        o_arr[c_arr[arr[j]] - 1] = arr[j];
        c_arr[arr[j]] = c_arr[arr[j]] - 1;

        cout << c_arr[arr[j]] << " ";
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = o_arr[i];
    }
}

int main()
{
    int arr[] = {1, 4, 1, 2, 7, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);


    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    counting_sort(arr, n);

    cout << endl;

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

