// Problem: H. Handling the Blocks
// Contest: Codeforces - 2021-2022 ACM-ICPC Brazil Subregional Programming Contest
// URL: https://codeforces.com/gym/103388/problem/H
// Memory Limit: 1024 MB
// Time Limit: 500 ms
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
    int n, k;
    cin >> n >> k;
    int col[n];
    int num[n];
    forn
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        col[a] = b;
        num[i] = a;
    }
    forn
    {
        if (col[i] != col[num[i]])
        {
            cout << "N" << endl;
            return;
        }
    }
    cout << "Y" << endl;
    return;
}

int main()
{
    Solve();
    return 0;
}
