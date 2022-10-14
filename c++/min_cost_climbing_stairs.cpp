// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
// You can either start from the step with index 0, or the step with index 1.
// Return the minimum cost to reach the top of the floor.

#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    for (int i = 2; i < n; i++)
        cost[i] += min(cost[i - 1], cost[i - 2]);
    return min(cost[n - 1], cost[n - 2]);
}

int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << minCostClimbingStairs(arr) << endl;
}
