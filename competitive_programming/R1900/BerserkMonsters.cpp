#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back
#define ull unsigned long long
using namespace std;

int a[300000];
int d[300000];
queue<int> alive_marked;
set<int> alive;
int n;
void simulate()
{
    int deads = 0;
    set<int> next_round;
    vector<int> to_delete;
    while (alive_marked.size() > 0)
    {
        int monster = alive_marked.front();
        alive_marked.pop();
        int damage = 0;
        auto pos = alive.find(monster);
        int prev_works = 0;
        int next_works = 0;
        auto prev = pos;
        if (pos != alive.begin())
        {
            prev--;
            damage += a[*prev];
            prev_works = 1;
        }
        pos++;
        if (pos != alive.end())
        {
            damage += a[*pos];
            next_works = 1;
        }
        if (damage > d[monster])
        {
            deads++;
            to_delete.pb(monster);
            if (prev_works)
            {

                next_round.insert(*prev);
            }
            if (next_works)
            {
                next_round.insert(*pos);
            }
        }
    }
    for (auto x : to_delete)
    {
        alive.erase(x);
        a[x] = 0;
    }
    for (auto x : next_round)
    {
        if (a[x] > 0)
        {
            alive_marked.push(x);
        }
    }
    cout << deads << wp;
}

void Solve()
{
    cin >> n;
    forn
    {
        cin >> a[i];
        alive_marked.push(i);
        alive.insert(i);
    }
    forn
    {
        cin >> d[i];
    }
    forn
    {
        simulate();
    }
    cout << endl;
    alive_marked = queue<int>();
    alive = set<int>();
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