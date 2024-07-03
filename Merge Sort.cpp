#include <iostream>
using namespace std;

void MERGE(int arr[], int Start, int mid, int End)
{

    int n1 = mid - Start + 1;
    int n2 = End - mid;

    int Left[n1 + 1];
    int Right[n2 + 1];

    for (int i = 0; i < n1; i++)
    {
        Left[i] = arr[Start + i];
    }
    for (int j = 0; j < n2; j++)
    {
        Right[j] = arr[mid + 1 + j];
    }

    Left[n1] = 2147483647;
    Right[n2] = 2147483647;

    int i = 0;
    int j = 0;

    for (int k = Start; k <= End; k ++)
    {
        if (Left[i] <= Right[j])
        {
            arr[k] = Left[i];
            i = i+1;
        }

        else
        {
            arr[k] = Right[j];
            j = j+1;
        }
    }
}


void MERGE_SORT(int arr[], int Start, int End)
{
    if (Start < End)
    {
        int mid = (Start + End)/2;
        MERGE_SORT (arr, Start, mid);
        MERGE_SORT(arr, mid+1, End);
        MERGE(arr, Start, mid, End);
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

    MERGE_SORT(arr, 0, n - 1);

    cout << endl;

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
