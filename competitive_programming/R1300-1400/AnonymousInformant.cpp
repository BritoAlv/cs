// Problem: C. Anonymous Informant
// Contest: Codeforces - Codeforces Round 908 (Div. 2)
// URL: https://codeforces.com/contest/1894/problem/C
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

void print_vector(vector<int> &a)
{
    for (auto x : a)
    {
        cout << x << wp;
    }
    cout << endl;
}

void print_yes(int a)
{
    if (a != 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    set<int> visited;
    int ops = 0;
    int start_index = n - 1;
    int number_shift_done = 0;
    while (a[start_index] <= n && ops < k)
    {
        if (a[start_index] == n || visited.find(start_index) != visited.end())
        {
            cout << "Yes" << endl;
            return;
        }
        ops++;
        visited.insert(start_index);
        number_shift_done += a[start_index];
        number_shift_done %= n;
        start_index = (n - 1) - number_shift_done;
    }
    print_yes(ops == k);
    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
