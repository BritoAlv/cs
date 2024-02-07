// Problem: B. Minimize Inversions
// Contest: Codeforces - Codeforces Round 922 (Div. 2)
// URL: https://codeforces.com/contest/1918/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back
#define ull unsigned long long

// je m appelle Alvaro j ai 21 ans.

using namespace std;

void simulate(vector<int> A, vector<int> B)
{
    int n = A.size();
    vector<int> pos_A(n);
    forn
    {
        pos_A[A[i]] = i;
    }
    vector<pair<int, int>> steps_a;
    forn
    {
        if (pos_A[i] != i)
        {
            int x = pos_A[i];
            int temp = A[i];
            A[i] = i;
            A[x] = temp;
            pos_A[temp] = x;
            pos_A[i] = i;
            steps_a.pb({i, x});
        }
    }
    for (auto x : steps_a)
    {
        int temp = B[x.first];
        B[x.first] = B[x.second];
        B[x.second] = temp;
    }
    forn
    {
        cout << A[i] + 1 << wp;
    }
    cout << endl;
    forn
    {
        cout << B[i] + 1 << wp;
    }
    cout << endl;
}

void Solve()
{
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    forn
    {
        cin >> A[i];
        A[i]--;
    }
    forn
    {
        cin >> B[i];
        B[i]--;
    }
    simulate(A, B);
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
