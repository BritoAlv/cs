// Problem: C. Save More Mice
// Contest: Codeforces - Codeforces Round 748 (Div. 3)
// URL: https://codeforces.com/contest/1593/problem/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Math Proof: ceiling and implementation
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    for (int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        if (m.find(t) == m.end())
        {
            m[t] = 0;
        }
        m[t]++;
    }

    int cat_position = 0;
    int answer = 0;

    map<int, int>::reverse_iterator it;
    for (it = m.rbegin(); it != m.rend(); ++it)
    {
        int cant_mouse = it->second;
        int distance_n = n - it->first;
        int position = it->first;

        if (position > cat_position)
        {
            int largest = (position - cat_position) / distance_n;
            if ((position - cat_position) % distance_n != 0)
            {
                largest++;
            }
            if (largest >= cant_mouse)
            {
                answer += cant_mouse;
                cat_position += cant_mouse * distance_n;
            }
            else
            {
                answer += largest;
                break;
            }
        }
        else
        {
            break;
        }
    }
    cout << answer << endl;
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
