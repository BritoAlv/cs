#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back
#define ull unsigned long long
using namespace std;

int nrows, ncolumns;

void Solve()
{
    int xa, ya, xb, yb;
    cin >> nrows >> ncolumns >> xa >> ya >> xb >> yb;
    if (xa >= xb)
    {
        cout << "Draw" << endl;
    }
    else
    {
        int distance = xb - xa - 1;
        if (distance % 2 == 0)
        {
            vector<pair<int, int>> A;
            vector<pair<int, int>> B;
            if (ya < yb)
            {
                A.pb({xa, ya});
                int ax = A.back().first;
                int ay = A.back().second;
                while (ax < nrows)
                {
                    A.pb({ax + 1, min(ncolumns, ay + 1)});
                    ax++;
                    ay++;
                }
                B.pb({xb, yb});
                int bx = B.back().first;
                int by = B.back().second;
                while (bx > 1)
                {
                    B.pb({bx - 1, min(ncolumns, (by + 1))});
                    bx--;
                    by++;
                }
                for (int i = 1; i < min(A.size(), B.size() + 1); i++)
                {
                    if (A[i] == B[i - 1])
                    {
                        cout << "Alice" << endl;
                        return;
                    }
                }
                cout << "Draw" << endl;
                return;
            }
            else if (ya > yb)
            {
                A.pb({xa, ya});
                int ax = A.back().first;
                int ay = A.back().second;
                while (ax < nrows)
                {
                    A.pb({ax + 1, max(1, ay - 1)});
                    ax++;
                    ay--;
                }
                B.pb({xb, yb});
                int bx = B.back().first;
                int by = B.back().second;
                while (bx > 1)
                {
                    B.pb({bx - 1, max(1, (by - 1))});
                    bx--;
                    by--;
                }
                for (int i = 1; i < min(A.size(), B.size() + 1); i++)
                {
                    if (A[i] == B[i - 1])
                    {
                        cout << "Alice" << endl;
                        return;
                    }
                }
                cout << "Draw" << endl;
                return;
            }
            else
            {
                cout << "Alice" << endl;
            }
        }
        else
        {
            vector<pair<int, int>> A;
            vector<pair<int, int>> B;
            if (ya < yb)
            {
                A.pb({xa, ya});
                int ax = A.back().first;
                int ay = A.back().second;
                while (ax < nrows)
                {
                    A.pb({ax + 1, max(1, ay - 1)});
                    ax++;
                    ay--;
                }
                B.pb({xb, yb});
                int bx = B.back().first;
                int by = B.back().second;
                while (bx > 1)
                {
                    B.pb({bx - 1, max(1, by - 1)});
                    bx--;
                    by--;
                }
                for (int i = 1; i < min(B.size(), A.size()); i++)
                {
                    if (A[i] == B[i])
                    {
                        cout << "Bob" << endl;
                        return;
                    }
                }
                cout << "Draw" << endl;
                return;
            }
            else if (ya > yb)
            {
                A.pb({xa, ya});
                int ax = A.back().first;
                int ay = A.back().second;
                while (ax < nrows)
                {
                    A.pb({ax + 1, min(ncolumns, ay + 1)});
                    ax++;
                    ay++;
                }
                B.pb({xb, yb});
                int bx = B.back().first;
                int by = B.back().second;
                while (bx >= 1)
                {
                    B.pb({bx - 1, min(ncolumns, (by + 1))});
                    bx--;
                    by++;
                }
                for (int i = 1; i < min(B.size(), A.size()); i++)
                {
                    if (A[i] == B[i])
                    {
                        cout << "Bob" << endl;
                        return;
                    }
                }
                cout << "Draw" << endl;
                return;
            }
            else
            {
                cout << "Bob" << endl;
            }
        }
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
