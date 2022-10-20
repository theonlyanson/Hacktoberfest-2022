#include <bits/stdc++.h>
using namespace std;

long long int count(int S[], int m, int n)
{

    long long int t[1001][1001];
    for (int j = 0; j < n + 1; j++)
        t[0][j] = 0;
    for (int i = 0; i < m + 1; i++)
        t[i][0] = 1;

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (S[i - 1] <= j)
                t[i][j] = t[i][j - S[i - 1]] + t[i - 1][j];

            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[m][n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++)
        {
            cin >> coins[i];
        }
        cout << count(coins, N, sum) << endl;
    }

    return 0;
}