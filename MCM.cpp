#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// MATRIX-CHAIN-ORDER function
void matrixChainOrder(vector<int> &p, vector<vector<int>> &m, vector<vector<int>> &s)
{
    int n = p.size() - 1;

    // Initialize the cost matrix m and split matrix s
    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    // l is the chain length
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

// PRINT-OPTIMAL-PARENS function
void printOptimalParens(vector<vector<int>> &s, int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

// Function to print the MCM table
void printMCMTable(const vector<vector<int>> &m, int n)
{
    cout << "MCM Table (m[i][j]):" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
                cout << m[i][j] << "\t";
            else
                cout << "-\t"; // Unused elements of the table
        }
        cout << endl;
    }
}

// Function to print the k table (s[i][j])
void printKTable(const vector<vector<int>> &s, int n)
{
    cout << "K Table (s[i][j]):" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i < j)
                cout << s[i][j] << "\t";
            else
                cout << "-\t"; // Unused elements of the table
        }
        cout << endl;
    }
}

int main()
{
    // Input number of matrices
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    cout << endl;

    // Input dimensions of matrices
    vector<int> p(n + 1);
    cout << "Enter the dimensions of matrices: " << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << "p[" << i << "] = ";
        cin >> p[i];
    }

    cout << endl;

    // Create m and s matrices
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));

    // Call matrix chain order function
    matrixChainOrder(p, m, s);

    // Print MCM table
    printMCMTable(m, n);

    cout << endl;
    cout << endl;

    // Output the minimum number of scalar multiplications
    cout << "Minimum number of multiplications: " << m[1][n] << endl;

    cout << endl;
    cout << endl;

    // Print K table
    printKTable(s, n);

    cout << endl;
    cout << endl;

    // Output the optimal parenthesization
    cout << "Optimal Parenthesization: ";
    printOptimalParens(s, 1, n);

    cout << endl;

    return 0;
}
