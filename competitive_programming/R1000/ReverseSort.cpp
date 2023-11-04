// Problem: B. Reverse Sort
// Contest: Codeforces - Codeforces Round 754 (Div. 2)
// URL: https://codeforces.com/contest/1605/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<char> S(n);
    int zero_count = 0;
    forn
    {
        cin >> S[i];
        zero_count += S[i] == '0';
    }
    vector<int> choosen_index;
    for (int i = 0; i < zero_count; i++)
    {
        if (S[i] == '1')
        {
            choosen_index.push_back(i + 1);
        }
    }
    for (int i = zero_count; i < n; i++)
    {
        if (S[i] == '0')
        {
            choosen_index.push_back(i + 1);
        }
    }
    cout << (choosen_index.size() > 0 ? 1 : 0) << endl;
    if (choosen_index.size() > 0)
    {
        cout << choosen_index.size() << wp;
        for (auto x : choosen_index)
        {
            cout << x << wp;
        }
        cout << endl;
    }

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
