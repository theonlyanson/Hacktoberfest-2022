#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int solve(int x, int y, string s1, string s2)
{
    if (x == -1 || y == -1)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    if (s1[x] == s2[y])
        return dp[x][y] = 1 + solve(x - 1, y - 1, s1, s2);
    int a = solve(x - 1, y, s1, s2);
    int b = solve(x, y - 1, s1, s2);
    return dp[x][y] = max(a, b);
}
int lcs(int x, int y, string s1, string s2)
{
    dp[x][y];
    memset(dp, -1, sizeof(dp));
    return solve(x - 1, y - 1, s1, s2);
}
int main()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a;
    cin >> b;
    cout << lcs(n, m, a, b);
}