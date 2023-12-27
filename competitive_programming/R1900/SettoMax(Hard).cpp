// Problem: D1. Set To Max (Easy Version)
// Contest: Codeforces - Codeforces Round 914 (Div. 2)
// URL: https://codeforces.com/contest/1904/problem/D1
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

using namespace std;

int lg[200001];

int stmin[18][200001];
int stmax[18][200001];

int get_max(int start, int end, int a[])
{
    int i = lg[end - start + 1];
    int maximum = max(stmax[i][start], stmax[i][end - (1 << i) + 1]);
    return maximum;
}

int get_min(int start, int end, int a[])
{
    int i = lg[end - start + 1];
    int minimum = min(stmin[i][start], stmin[i][end - (1 << i) + 1]);
    return minimum;
}

void Solve()
{
    int n;
    cin >> n;
    int a[n], b[n];
    map<int, vector<int>> vals;
    forn
    {
        cin >> a[i];
    }
    forn
    {
        cin >> b[i];
        if (vals.find(b[i]) == vals.end())
        {
            vals[b[i]] = vector<int>();
        }
        vals[b[i]].pb(i);
    }

    copy(b, b + n, stmin[0]);
    copy(a, a + n, stmax[0]);

    for (int i = 1; i <= 17; i++)
    {
        for (int j = 0; j + (1 << i) <= n; j++)
        {
            stmin[i][j] = min(stmin[i - 1][j], stmin[i - 1][j + (1 << (i - 1))]);
            stmax[i][j] = max(stmax[i - 1][j], stmax[i - 1][j + (1 << (i - 1))]);
        }
    }

    int works = 1;
    auto it = vals.end();
    while (it != vals.begin())
    {
        it--;
        vector<int> slice = (*it).second;
        int value = (*it).first;
        vector<pair<int, int>> segments;
        for (int i = 0; i < slice.size(); i++)
        {
            int start = i;
            int end = i;
            while (end + 1 < slice.size() && slice[end + 1] == slice[end] + 1)
            {
                end++;
            }
            segments.pb({slice[start], slice[end]});
            i = end;
        }
        for (auto x : segments)
        {
            int start = x.first;
            int end = x.second;
            int maxx = a[start];
            // find lowest index from [0, start] such that b[index] >= value.
            // find lowest index from [0, start] such that a[index] <= value.
            // set start = max(both).

            int index_end1 = 0;
            int index_s1 = start;
            while (index_s1 - index_end1 > 1)
            {
                int middle = (index_end1 + index_s1) / 2;
                if (get_min(middle, start, b) >= value)
                {
                    index_s1 = middle;
                }
                else
                {
                    index_end1 = middle + 1;
                }
            }
            if (get_min(index_s1 - 1, start, b) >= value)
            {
                index_s1 = index_s1 - 1;
            }
            int index_end2 = 0;
            int index_s2 = start;
            while (index_s2 - index_end2 > 1)
            {
                int middle = (index_end2 + index_s2) / 2;
                if (get_max(middle, start, a) <= value)
                {
                    index_s2 = middle;
                }
                else
                {
                    index_end2 = middle + 1;
                }
            }
            if (get_max(index_s2 - 1, start, a) <= value)
            {
                index_s2 = index_s2 - 1;
            }

            // find lowest index from [0, start] such that b[index] >= value.
            // find lowest index from [0, start] such that a[index] <= value.
            // set start = max(both).

            int index_end11 = n - 1;
            int index_s11 = end;
            while (index_end11 - index_s11 > 1)
            {
                int middle = (index_end11 + index_s11) / 2;
                if (get_min(end, middle, b) >= value)
                {
                    index_s11 = middle;
                }
                else
                {
                    index_end11 = middle - 1;
                }
            }
            if (index_s11 < n - 1 && get_min(end, index_s11 + 1, b) >= value)
            {
                index_s11 = index_s11 + 1;
            }
            int index_end22 = n - 1;
            int index_s22 = end;
            while (index_end22 - index_s22 > 1)
            {
                int middle = (index_end22 + index_s22) / 2;
                if (get_max(end, middle, a) <= value)
                {
                    index_s22 = middle;
                }
                else
                {
                    index_end22 = middle - 1;
                }
            }
            if (index_s22 + 1 < n && get_max(end, index_s22 + 1, a) <= value)
            {
                index_s22 = index_s22 + 1;
            }
            start = max(index_s1, index_s2);
            end = min(index_s22, index_s11);
            maxx = get_max(start, end, a);
            if (maxx != value)
            {
                works = 0;
                break;
            }
        }
    }
    cout << (works ? "YES" : "NO") << endl;
    return;
}

int main()
{
    lg[1] = 0;
    for (int i = 2; i <= 200000; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
