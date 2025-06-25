// Problem: C. Racing
// Contest: Codeforces - Codeforces Round 1026 (Div. 2)
// URL: https://codeforces.com/contest/2110/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

// je m appelle Alvaro Brito. J ai 22 ans.
#include <bits/stdc++.h>

#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define wp " "
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

template <typename T> void print(const T &container)
{
    for (const auto &element : container)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

template <typename K, typename V> void print(const std::map<K, V> &m)
{
    for (const auto &[key, value] : m)
    {
        std::cout << key << ": " << value << "\n";
    }
}

int test_cases;
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vl a(n);
    fori(0, n - 1) cin >> a[i];
    int cur_h = 0;
    queue<int> fix;
    vi marked(n, 0);
    fori(0, n - 1) marked[i] = (a[i] == -1);
    vector<pi> vals(n);
    fori(0, n - 1)
    {
        cin >> vals[i].first >> vals[i].second;
    }
    fori(0, n - 1)
    {
        a[i] = abs(a[i]);
        cur_h += a[i];
        if (marked[i])
        {
            fix.push(i);
        }
        int l = vals[i].first;
        int r = vals[i].second;
        if (cur_h < l)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            if (cur_h > r)
            {
                int needed = cur_h - r;
                if ((int)fix.size() >= needed)
                {
                    for (int j = 0; j < needed; j++)
                    {
                        int next = fix.front();
                        fix.pop();
                        a[next] = 0;
                        cur_h -= 1;
                    }
                }
                else
                {
                    cout << -1 << endl;
                    return;
                }
            }
            while ((int)fix.size() > cur_h - l)
            {
                fix.pop();
            }
        }
    }
    print(a);
}

int main()
{
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}
