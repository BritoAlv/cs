// Problem: B. Battle Cows
// Contest: Codeforces - Codeforces Global Round 25
// URL: https://codeforces.com/contest/1951/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void swap(int i, int j, vector<int> &a)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int count_wins(int j, vector<int> &a)
{
    int wins = 0;
    if (j > 0)
    {
        for (int i = 0; i < j; i++)
        {
            if (a[i] > a[j])
            {
                return 0;
            }
        }
        wins++;
    }
    for (int i = j + 1; i < a.sz; i++)
    {
        if (a[i] < a[j])
        {
            wins++;
        }
        else
        {
            break;
        }
    }
    return wins;
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    forn
    {
        cin >> a[i];
    }
    k--;
    swap(0, k, a);
    int maxx = count_wins(0, a);
    swap(0, k, a);
    for (int i = 0; i < k; i++)
    {
        if (a[i] > a[k])
        {
            swap(i, k, a);
            maxx = max(maxx, count_wins(i, a));
            swap(i, k, a);
            break;
        }
    }
    cout << maxx << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
