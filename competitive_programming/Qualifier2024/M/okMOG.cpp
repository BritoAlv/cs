#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

struct ProcessorTime
{
    int id;
    int st;
    int ed;

    ProcessorTime(int id, int st, int ed)
    {
        this->id = id;
        this->st = st;
        this->ed = ed;
    }
};

struct Task
{
    int id;
    int st;
    int ed;
    Task(int id, int st, int ed)
    {
        this->id = id;
        this->st = st;
        this->ed = ed;
    }

    bool operator<(const Task &x) const
    {
        if (this->ed < x.ed)
        {
            return 1;
        }
        if (this->ed > x.ed)
        {
            return 0;
        }
        return this->id < x.id;
    }
};

set<Task> active_tasks;
map<int, vector<Task>> to_add;
vector<vector<ProcessorTime>> tt;
int n, m, ct;

void add_queue()
{
    for (auto &top : to_add[ct])
    {
        active_tasks.insert(top);
    }
}

void use_processor(Task &z, int duration, int cpu_id)
{
    if (tt[z.id].size() == 0 || tt[z.id].back().id != cpu_id || tt[z.id].back().ed != ct)
    {
        tt[z.id].push_back(ProcessorTime(cpu_id, ct, ct + duration));
    }
    else
    {
        tt[z.id].back().ed += duration;
    }
}

int process()
{
    for (int pp = 0; pp < m; pp++)
    {
        if (active_tasks.size() == 0)
        {
            break;
        }
        auto top = *active_tasks.begin();
        if (top.ed == ct)
        {
            return 0;
        }
        active_tasks.erase(top);
        use_processor(top, 1, pp + 1);
    }
    return 1;
}

void solve()
{
    cin >> n >> m;
    tt = vector<vector<ProcessorTime>>(n);
    forn
    {
        int d, s, e;
        cin >> s >> e >> d;
        for (int st = s; st <= s + d - 1; st++)
        {
            auto t = Task(i, st, e - d + 1 + (st - s));
            if (to_add.find(st) == to_add.end())
            {
                to_add[st] = vector<Task>();
            }
            to_add[st].pb(t);
        }
    }
    for (int i = 0; i <= 20; i++)
    {
        ct = i;
        add_queue();
        if (!process())
        {
            break;
        }
    }
    cout << (active_tasks.size() == 0 ? "YES" : "NO") << endl;
/*      if (pq.size() == 0)
    {
        for (auto z : tt)
        {
            cout << z.size() << wp;
            for (auto y : z)
            {
                cout << y.id << wp << y.st << wp << y.ed << wp;
            }
            cout << endl;
        }
    } */
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while(test_cases-- > 0)
    {
        active_tasks = set<Task>();
        to_add = map<int, vector<Task>>();
        solve();
    }
}