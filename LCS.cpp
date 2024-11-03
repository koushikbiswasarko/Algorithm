#include <iostream>
using namespace std;

int LCS_Length(string S1, string S2, int B[100][100])
{
    int m = S1.length();
    int n = S2.length();

    int C[100][100]; // Array size should be defined in a safe upper limit

    // Initialize first row and column of C with 0
    for (int i = 0; i <= m; i++)
    {
        C[i][0] = 0;
    }

    for (int j = 0; j <= n; j++)
    {
        C[0][j] = 0;
    }

    // Fill C and B arrays
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (S1[i - 1] == S2[j - 1]) // Corrected index for string access
            {
                C[i][j] = C[i - 1][j - 1] + 1;
                B[i][j] = 'C'; // Diagonal move
            }
            else if (C[i - 1][j] >= C[i][j - 1])
            {
                C[i][j] = C[i - 1][j];
                B[i][j] = 'U'; // Move up
            }
            else
            {
                C[i][j] = C[i][j - 1];
                B[i][j] = 'L'; // Move left
            }
        }
    }

    // Print the LCS table
    cout << "LCS Table (C array):" << endl;
    cout << endl;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // Print the Direction Table (B array)
    cout << "Direction Table (B array):" << endl;
    cout << endl;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << (char)B[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    return C[m][n]; // Return the length of LCS
}

void LCS(int B[100][100], string S1, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }

    if (B[i][j] == 'C')
    {
        LCS(B, S1, i - 1, j - 1);
        cout << S1[i - 1] << " "; // Correct index for string
    }
    else if (B[i][j] == 'U')
    {
        LCS(B, S1, i - 1, j);
    }
    else
    {
        LCS(B, S1, i, j - 1);
    }
}

int main()
{
    string S1, S2;

    cout << "Write String 1: ";
    cin >> S1;

    cout << endl;

    cout << "Write String 2: ";
    cin >> S2;

    cout << endl;

    int B[100][100]; // Use a large enough array for backtracking

    int length = LCS_Length(S1, S2, B);

    cout << "Length of LCS: " << length << endl;

    cout << endl;

    cout << "LCS is: ";
    LCS(B, S1, S1.length(), S2.length()); // Trace back to print LCS

    cout << endl;

    return 0;
}
