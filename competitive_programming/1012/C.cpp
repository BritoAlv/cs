// You might break and that's okay.
// Tags:
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

int test_cases;
using namespace std;

template <typename T> void print(const T &container)
{
    for (const auto &element : container)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

set<vi> free_cells;
set<vi> free_tables;

int cd(int x, int y)
{
    if (x % 3 == 2 && y % 3 == 2)
    {
        return x + y + 2;
    }
    else
    {
        return x + y;
    }
}

void insert(vi cur, set<vi> &used_tables, set<vi> &used_cells)
{
    used_cells.insert(cur);
    free_cells.erase(cur);
    while (cur[1] % 3 > 1)
    {
        cur[1]--;
    }
    while (cur[2] % 3 > 1)
    {
        cur[2]--;
    }
    vi root = {cd(cur[1], cur[2]), cur[1], cur[2]};
    used_tables.insert(root);
    if (free_tables.count(root))
    {
        free_tables.erase(root);
    }
}

void Solve()
{
    set<vi> used_tables;
    set<vi> used_cells;

    int n;
    cin >> n;
    fori(0, n - 1)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            vi next = *free_cells.begin();
            insert(next, used_tables, used_cells);
            cout << next[1] << wp << next[2] << endl;
        }
        else
        {
            vi next = *free_tables.begin();
            insert(next, used_tables, used_cells);
            cout << next[1] << wp << next[2] << endl;
        }
    }
    for (auto z : used_tables)
    {
        free_tables.insert(z);
    }
    for (auto z : used_cells)
    {
        free_cells.insert(z);
    }
    used_tables.clear();
    used_cells.clear();
}

int main()
{
    set<vi> G;
    G.insert({2, 1, 1});
    while (free_tables.size() < 50000)
    {
        vi top = *G.begin();

        free_tables.insert(top);
        fori(0, 1) forj(0, 1)
        {
            int x = top[1] + i;
            int y = top[2] + j;
            free_cells.insert({cd(x, y), x, y});
        }
        G.erase(top);
        G.insert({cd(top[1] + 3, top[2]), top[1] + 3, top[2]});
        G.insert({cd(top[1], top[2] + 3), top[1], top[2] + 3});
        G.insert({cd(top[1] + 3, top[2] + 3), top[1] + 3, top[2] + 3});
    }
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}