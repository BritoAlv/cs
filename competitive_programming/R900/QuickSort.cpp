// Problem: B. Quick Sort
// Contest: Codeforces - Codeforces Round 842 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1768/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: notice that k doesnt matter the only
// thing that it does is speed up the process, so solve
// for k = 1, focus on counting the indexes that will no be
// replaced.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int a[n];
    int pos[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i] - 1] = i + 1;
    }
    int answer = n - 1;
    int index = 1;
    while (pos[index] > pos[index - 1])
    {
        answer--;
        index++;
        if (index == n)
            break;
    }

    cout << answer / k + (answer % k == 0 ? 0 : 1) << '\n';

    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
