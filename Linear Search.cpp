#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Input Target: ";
    cin >> target;

    cout << endl;

    int result = linear_search(arr, n, target);

    if (result != -1)
    {
        cout << target << " is found at index: " << result << endl;
    }
    else
    {
        cout << target << " is not found" << endl;
    }

    return 0;
}
