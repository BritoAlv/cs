#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define sz size()
#define vi vector<int>
#define vl vector<ll>
#define exist(container, obj) (container.find(obj) != container.end())
#define yesno(obj) cout << (obj ? "YES" : "NO") << endl
#define print(x, name)                                                                                                 \
    cout << name << endl;                                                                                              \
    for (auto z : x)                                                                                                   \
        cout << z << wp;                                                                                               \
    cout << endl;
// je m appelle Alvaro j ai 21 ans.
int test_cases;
int test_cases_original;
#define t_number test_cases_original - test_cases

using namespace std;

vector<int> seq_odd;
vector<int> seq_even;

void init_odd()
{
    seq_odd = {1, 1};
    int next_i = 3;
    while (seq_odd.sz < 1e6)
    {
        for (int i = 2; i < next_i - 1; i += 2)
        {
            seq_odd.pb(next_i - 1);
            seq_odd.pb(i);
            seq_odd.pb(next_i);
            seq_odd.pb(i + 1);
        }
        seq_odd.pb(next_i - 1);
        seq_odd.pb(next_i - 1);
        seq_odd.pb(next_i);
        seq_odd.pb(next_i);
        seq_odd.pb(1);
        next_i += 2;
    }
}

void init_even()
{
    seq_even = {1, 1, 2, 2};
    int next_i = 4;
    int last_ev = 2;
    while (seq_even.sz < 1e6)
    {
        // print(seq_even, "EV");
        queue<int> q;
        for (int i = 1; i < next_i; i++)
        {
            if (i != last_ev)
                q.push(i);
        }
        seq_even.pb(next_i - 1);
        seq_even.pb(next_i - 1);
        seq_even.pb(q.front());
        q.pop();
        seq_even.pb(next_i);
        seq_even.pb(next_i);
        seq_even.pb(q.front());
        q.pop();
        while (q.sz > 0)
        {
            seq_even.pb(next_i - 1);
            seq_even.pb(q.front());
            q.pop();
            seq_even.pb(next_i);
            seq_even.pb(q.front());
            q.pop();
        };
        next_i += 2;
        last_ev = seq_even.back();
    }
}

int primes[300000];
vector<int> primes2;
void init()
{
    init_odd();
    init_even();
    for (int i = 0; i < 300000; i++)
    {
        primes[i] = i;
    }
    for (int i = 2; i < 300000; i++)
    {
        if (primes[i] == i)
        {
            primes2.pb(i);
            for (int j = 2 * i; j < 300000; j += i)
            {
                if (primes[j] == j)
                {
                    primes[j] = i;
                }
            }
        }
    }
}

int valid(vector<int> &a)
{
    set<int> o;
    for (int i = 1; i < a.sz; i++)
    {
        if (exist(o, a[i] * a[i - 1]))
            return 0;
        o.insert(a[i] * a[i - 1]);
    }
    return 1;
}

void Solve()
{
    int n;
    cin >> n;
    set<int> seq1;
    set<int> seq2;
    vector<int> ans;
    forn
    {
        seq1.insert(seq_odd[i]);
        seq2.insert(seq_even[i]);
    }
    if (seq1.sz < seq2.sz)
    {
        forn
        {
            ans.pb(primes2[seq_odd[i]]);
            // cout << seq_odd[i] << wp;
        }
        // cout << endl;
    }
    else
    {
        forn
        {
            ans.pb(primes2[seq_even[i]]);
            // cout << seq_even[i] << wp;
        }
        // cout << endl;
    }
    forn
    {
        cout << ans[i] << wp;
    }
    cout << endl;
}

int main()
{
    init();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> test_cases_original;
    test_cases = test_cases_original;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
