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

vector<pi> s(int A, int B)
{
    vector<pi> solutions;
    if (A % 2 != B % 2)
    {
        return solutions;
    }
    for (int na = 0; na <= A; na++)
    {
        int nb = A - na;
        int sa = na - (A - B) / 2;
        int sb = B - sa;
        if (nb >= 0 && sa >= 0 && sb >= 0)
        {
            solutions.pb({na, sa});
        }
    }
    return solutions;
}

void Solve()
{
    int n;
    cin >> n;
    vector<char> ch(n);
    forn
    {
        cin >> ch[i];
    }
    vector<int> counts(4, 0);
    forn
    {
        counts[0] += (ch[i] == 'N');
        counts[1] += (ch[i] == 'S');
        counts[2] += (ch[i] == 'E');
        counts[3] += (ch[i] == 'W');
    }
    vector<pi> NS = s(counts[0], counts[1]);
    vector<pi> EW = s(counts[2], counts[3]);
    if (NS.sz == 0 || EW.sz == 0)
    {
        cout << "NO" << endl;
        return;
    }
    for (auto x : NS)
    {
        for (auto y : EW)
        {
            if (x.first + x.second + y.first + y.second == 0)
            {
                continue;
            }
            if ((counts[0] + counts[1] + counts[2] + counts[3]) - (x.first + x.second + y.first + y.second) == 0)
            {
                continue;
            }
            forn
            {
                if (ch[i] == 'N')
                {
                    if (x.first > 0)
                    {
                        cout << "H";
                        x.first--;
                    }
                    else
                    {
                        cout << "R";
                    }
                }
                if (ch[i] == 'S')
                {
                    if (x.second > 0)
                    {
                        cout << "H";
                        x.second--;
                    }
                    else
                    {
                        cout << "R";
                    }
                }
                if (ch[i] == 'E')
                {
                    if (y.first > 0)
                    {
                        cout << "H";
                        y.first--;
                    }
                    else
                    {
                        cout << "R";
                    }
                }
                if (ch[i] == 'W')
                {
                    if (y.second > 0)
                    {
                        cout << "H";
                        y.second--;
                    }
                    else
                    {
                        cout << "R";
                    }
                }
            }
            cout << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
