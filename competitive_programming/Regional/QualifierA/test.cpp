#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

struct HashInfo
{
    vector<ll> bases;
    vector<ll> mods;
    const static int maxn = 1e6 + 3;
    vector<array<ll, maxn>> pows;
    vector<array<ll, maxn>> invs;

    HashInfo(vector<pair<ll, ll>> &info)
    {
        for (auto &p : info)
        {
            bases.pb(p.first);
            mods.pb(p.second);
            pows.pb(array<ll, maxn>());
            invs.pb(array<ll, maxn>());
        }

        for (int i = 0; i < bases.size(); i++)
        {
            ll base = bases[i];
            ll mod = mods[i];

            pows[i][0] = 1;
            invs[i][0] = 1;

            ll inv11 = inv(base, mod);

            for (int j = 1; j < maxn; j++)
            {
                pows[i][j] = (pows[i][j - 1] * base) % mod;
                invs[i][j] = (invs[i][j - 1] * inv11) % mod;
            }
        }
    }

    ll f_pow(ll base, ll exp, ll mod)
    {
        if (exp == 0)
            return 1;
        if (exp == 1)
            return base % mod;
        ll middle = f_pow(base, exp / 2, mod);
        middle *= middle;
        middle %= mod;
        if (exp % 2)
        {
            middle *= base;
            middle %= mod;
        }
        return middle;
    }

    ll inv(ll base, ll mod)
    {
        return f_pow(base, mod - 2, mod);
    }
};

struct ValueHash
{
    vector<ll> values;
    HashInfo *hashinfo;
    int length;

    ValueHash(vector<ll> values, int len, HashInfo *p) : hashinfo(p), values(values), length(len)
    {
        mod();
    }

    ValueHash(ll seed, int len, HashInfo *p) : hashinfo(p), values(vector<ll>(p->mods.size(), seed)), length(len)
    {
        mod();
    }

    ValueHash() : hashinfo(nullptr)
    {
    }

    bool operator==(const ValueHash &other) const
    {
        return values == other.values && length == other.length;
    }

    void mod()
    {
        for (int i = 0; i < values.size(); i++)
        {
            values[i] %= this->hashinfo->mods[i];
        }
    }

    void plus(ValueHash &o)
    {
        for (int i = 0; i < values.size(); i++)
        {
            values[i] += o.values[i];
        }
        mod();
    }

    void minus(ValueHash &o)
    {
        for (int i = 0; i < values.size(); i++)
        {
            values[i] += this->hashinfo->mods[i];
            values[i] -= o.values[i];
        }
        mod();
    }

    void pow(int index)
    {
        for (int i = 0; i < values.size(); i++)
        {
            values[i] *= this->hashinfo->pows[i][index];
        }
        mod();
    }

    void inv(int index)
    {
        for (int i = 0; i < values.size(); i++)
        {
            values[i] *= this->hashinfo->invs[i][index];
        }
        mod();
    }
};

struct HashOp
{
    size_t operator()(const ValueHash &x) const
    {
        ll result = 0;
        for (auto z : x.values)
        {
            result += z;
        }
        return hash<long long>()( x.length + result);
    }
};

vector<vector<ValueHash>> p;
vector<vector<ValueHash>> s;
unordered_map<ValueHash, int, HashOp> P;
unordered_map<ValueHash, int, HashOp> S;
unordered_map<ValueHash, int, HashOp> F;
vector<pair<ll, ll>> info = {{31, 1e9 + 7}};
HashInfo h = HashInfo(info);

void init(vector<string> &R)
{
    for (auto &st : R)
    {
        int n = st.size();
        vector<ValueHash> pp(n);
        vector<ValueHash> ss(n);
        forn
        {
            pp[i] = ValueHash((long long)(st[i] - 'a' + 1), i + 1, &h);
            pp[i].pow(i + 1);
            if (i > 0)
            {
                pp[i].plus(pp[i - 1]);
            }
            P[pp[i]]++;
            if (i == n - 1)
            {
                F[pp[i]]++;
            }
        }
        forn
        {
            ss[i] = ValueHash(pp[n - 1].values, n - i , &h);
            if (i > 0)
            {
                ss[i].minus(pp[i - 1]);
            }
            ss[i].inv(i);
            S[ss[i]]++;
        }
        p.push_back(pp);
        s.push_back(ss);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> R(n);
    forn
    {
        cin >> R[i];
    }
    init(R);
    set<int> ans;
    forn
    {
        auto current = p[i].back();
        if (P[current] > 1 || S[current] > 1)
        {
            ans.insert(i);
        }
        for (int j = 0; j < R[i].size() - 1; j++)
        {
            auto full_part = p[i][j];
            auto pref_part = s[i][j + 1];
            if (F[full_part] > 0 && P[pref_part] > 0)
            {
                ans.insert(i);
            }
        }
        for (int j = 1; j < R[i].size(); j++)
        {
            auto full_part = s[i][j];
            auto suf_part = p[i][j - 1];
            if (F[full_part] > 0 && S[suf_part] > 0)
            {
                ans.insert(i);
            }
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x + 1 << endl;
    }
    cout << endl;
}