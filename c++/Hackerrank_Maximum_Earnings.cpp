/*
Question – Maximize Earnings
Problem Statement -: A company has a list of jobs to perform. Each job has a start time, end time and profit value. The manager has asked his employee Anirudh to pick jobs of his choice. Anirudh being greedy wants to select jobs for him in such a way that would maximize his earnings. 

Given a list of jobs how many jobs and total earning are left for other employees once Anirudh

Picks jobs of his choice.

Note: Anirudh can perform only one job at a time.

 

Input format:

Each Job has 3 pieces of info – Start Time,End Time and Profit

The first line contains the number of Jobs for the day. Say ‘n’. So there will be ‘3n lines following as each job has 3 lines.

Each of the next ‘3n’ lines contains jobs in the following format:

start_time
end-time
Profit
start-time and end-time are in HHMM 24HRS format i.e. 9am is 0900 and 9PM is 2100

 

Constraints

The number of jobs in the day is less than 10000 i.e. 0<_n<_10000
Start-time is always less than end time.
 

Output format :-

Program should return an array of 2 integers where 1st one is number of jobs left and earnings of other employees.

 

Sample Input 1 :

3

0900

1030

100

1000

1200

500

53

1100

1200

300

Sample Output 1:

2

400

Sample Explanation 1

Anirudh chooses 1000-1200 jobs. His earnings is 500. The 1st and 3rd jobs i.e. 0900-1030 and 1100-1200 respectively overlap with the 2nd jobs. But profit earned from them will be 400 only. Hence Anirudh chooses 2nd one. Remaining 2 Jobs & 400 cash for other employees.

 

Sample Input 2:

5

0805

0830

100

0835

0900

100

0905

0930

100

0935

1000

100

1005

1030

100

Sample output 2:

0

0

Sample Explanation 2:

Anirudh can work on all appointments as there are none overlapping. Hence 0 appointments and 0 earnings for other employees.

*/

#include <bits/stdc++.h>
using namespace std;
class job
{
public:
    int st, ed, cost;
};
int getTime(string s)
{
    int hr = (s[0] – ‘0’) * 10 + (s[1] – ‘0’);
    int min = (s[2] – ‘0’) * 10 + (s[3] – ‘0’);
 
    return hr * 60 + min;
}
bool compare(job A, job B)
{
    return A.ed < B.ed;
}
int searchJob(job arr[], int st, int ed, int key)
{
    int ans = –1;
    while (st <= ed)
    {
        int mid = (st + ed) / 2;
        if (arr[mid].ed <= key)
        {
            ans = mid;
            st = mid + 1;
        }
        else
        {
            ed = mid – 1;
        }
    }
    return ans;
}
pair<int, int> solve(job arr[], int n)
{
    int dp[n] = {0};
    int numOfJobs[n] = {0};
 
    dp[0] = arr[0].cost;
    numOfJobs[0] = 1;
 
    for (int i = 1; i < n; i++)
    {
        int cur = arr[i].cost;
        int num = 1;
        int idx = searchJob(arr, 0, i – 1, arr[i].st);
 
        if (idx != cur)
        {
            cur += dp[idx];
            num += numOfJobs[idx];
        }
        if (cur > dp[i – 1])
        {
            dp[i] = cur;
            numOfJobs[i] = num;
        }
        else
        {
            dp[i] = dp[i – 1];
            numOfJobs[i] = numOfJobs[i – 1];
        }
    }
    return {numOfJobs[n – 1], dp[n – 1]};
}
int main()
{
    int n;
    cin >> n;
 
    job arr[n];
    int cost;
    string st, ed;
    int total = 0;
 
    for (int i = 0; i < n; i++)
    {
        cin >> st >> ed >> cost;
        arr[i].st = getTime(st);
        arr[i].ed = getTime(ed);
        arr[i].cost = cost;
        total += cost;
    }
    sort(arr, arr + n, compare);
 
    pair<int, int> res = solve(arr, n);
 
    cout << n – res.first << endl;
    cout << total – res.second << endl;
 
    return 0;
}
