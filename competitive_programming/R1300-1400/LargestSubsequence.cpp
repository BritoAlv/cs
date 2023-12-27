// Problem: C. Largest Subsequence
// Contest: Codeforces - Codeforces Round 915 (Div. 2)
// URL: https://codeforces.com/contest/1905/problem/C#
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
#define pb push_back

using namespace std;

int comparer(pair<char, int> A, pair<char, int> B)
{
    if (A.first < B.first)
    {
        return 1;
    }
    if (A.first > B.first)
    {
        return 0;
    }
    else
    {
        return A.second > B.second;
    }
}

void swap(int i, int j, vector<char> &S)
{
    char t = S[i];
    S[i] = S[j];
    S[j] = t;
    return;
}

void Solve()
{
    int n;
    cin >> n;
    vector<char> S(n);
    forn
    {
        cin >> S[i];
    }
    vector<int> index_max(n);
    index_max[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        index_max[i] = (S[i] >= S[index_max[i + 1]] ? i : index_max[i + 1]);
    }
    set<int> larg_sec;
    stack<int> larg_secc;
    int index_start = index_max[0];
    larg_sec.insert(index_start);
    larg_secc.push(index_start);
    while (index_start != n - 1)
    {
        index_start = index_max[index_start + 1];
        larg_sec.insert(index_start);
        larg_secc.push(index_start);
    }

    int largest_count = 0;
    for (auto x : larg_sec)
    {
        if (S[x] == S[*(larg_sec.begin())])
        {
            largest_count++;
        }
    }
    vector<char> SS(n);
    forn
    {
        if (larg_sec.find(i) == larg_sec.end())
        {
            SS[i] = S[i];
        }
        else
        {
            SS[i] = S[larg_secc.top()];
            larg_secc.pop();
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (SS[i] < SS[i - 1])
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << larg_sec.size() - largest_count << endl;
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
