#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    unordered_map<int, int> pos;
    int prefix[n];
    forn
    {
        cin >> a[i];
        prefix[i] = 0;
    }

    prefix[0] = 0;
    pos[a[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        if (pos.find(a[i]) == pos.end())
        {
            prefix[i] = prefix[i - 1];
            pos[a[i]] = i;
        }
        else
        {
            int old_index = pos[a[i]];
            int prev_ans = (old_index > 0 ? prefix[old_index - 1] : 0);
            prefix[i] = max(prefix[i - 1], prev_ans + (i - old_index + 1));
            if (prev_ans + (i - old_index) < prefix[i - 1])
            {
                pos[a[i]] = i;
            }
        }
    }
    cout << prefix[n - 1] << endl;
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
