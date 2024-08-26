/*
idea is notice that smallest value has to be updated, with one neighbour, by well ordering left most should have right
neighbour with equal value and this is forced, now there is a need to optimize the solution, noticing that operation
will be applied until equal to min between neighbours of greater value.
*/

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define fori(a, b) for (int i = a; i <= b; i++)
#define even(x) ((x) % 2 == 0)
#define odd(x) ((x) % 2 == 1)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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

#define sg pair<int, pi>

void Solve()
{
    int n;
    cin >> n;
    vi a(n);
    forn
    {
        cin >> a[i];
    }
    set<sg> A;
    set<sg> B;

    auto clone = [](sg A) -> sg { return {A.second.first, {A.first, A.second.second}}; };

    auto mix = [](sg A, sg B) -> sg {
        return {min(A.first, B.first), {max(A.second.first, B.second.first), A.second.second + B.second.second}};
    };

    forn
    {
        int ed = i;
        while (ed + 1 < n && a[ed + 1] == a[ed])
        {
            ed++;
        }
        sg x = {a[i], {i, ed - i + 1}};
        A.insert(x);
        B.insert(clone(x));
        i = ed;
    }
    while (sz(A) > 1)
    {
        auto m = *A.begin();
        if (odd(m.second.second))
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            sg clon = clone(m);
            auto pt = B.find(clon);
            vector<sg> candidates;
            if (pt != B.begin())
            {
                pt--;
                candidates.pb(*pt);
                pt++;
            }
            pt++;
            if (pt != B.end())
            {
                candidates.pb(*pt);
            }
            auto to_choose = candidates[0];
            if (sz(candidates) == 2 && candidates[1].second.first < candidates[0].second.first)
            {
                to_choose = candidates[1];
            }
            if (sz(candidates) == 2 && candidates[1].second.first == candidates[0].second.first)
            {
                B.erase(clon);
                B.erase(candidates[0]);
                B.erase(candidates[1]);
                B.insert(mix(mix(clon, candidates[0]), candidates[1]));
                A.erase(m);
                A.erase(clone(candidates[0]));
                A.erase(clone(candidates[1]));
                A.insert(clone(mix(mix(clon, candidates[0]), candidates[1])));
            }
            else
            {
                B.erase(clon);
                B.erase(to_choose);
                B.insert(mix(clon, to_choose));
                auto to_ch_clon = clone(to_choose);
                A.erase(m);
                A.erase(to_ch_clon);
                A.insert(clone(mix(clon, to_choose)));
            }
        }
    }
    cout << "YES" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}