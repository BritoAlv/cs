#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

const int maxn = 1e5 + 4;
int n;
vector<vector<ll>> NW(4, vector<ll>(maxn, 0));
vector<set<int>> NW_especial(4);

int in_interval(int l, int g, int index)
{
    auto pt = NW_especial[index].lower_bound(l);
    return pt != NW_especial[index].end() && *pt <= g;
}

int Mless(int l, int index)
{
    auto pt = NW_especial[index].upper_bound(l);
    if (pt == NW_especial[index].begin())
    {
        return -1;
    }
    pt--;
    return *pt;
}

int Mgreater(int g, int index)
{
    auto pt = NW_especial[index].upper_bound(g - 1);
    if (pt == NW_especial[index].end())
    {
        return -1;
    }
    return *pt;
}

ll ziz_zag(int stepSize, ll distance, int cost)
{
    int dif = abs(stepSize);
    int ceil_dif = 2 * (dif / 2);
    distance += ceil_dif * cost;
    return distance;
}

ll distance(pair<int, int> S, pair<int, int> E, int north, int west)
{
    ll distance = 0;

    int upper1 = max(E.first, S.first);
    int lower1 = min(E.first, S.first);

    int upper2 = max(E.second, S.second);
    int lower2 = min(E.second, S.second);

    if (upper1 > lower1)
    {
        distance += NW[north][upper1 - 1];
        if (lower1 > 0)
        {
            distance -= NW[north][lower1 - 1];
        }
    }

    if (upper2 > lower2)
    {
        distance += NW[west][upper2 - 1];
        if (lower2 > 0)
        {
            distance -= NW[west][lower2 - 1];
        }
    }
    return distance;
}

void solve(pair<int, int> P1, pair<int, int> P2, int north, int west)
{
    assert(P1.first <= P2.first);
    assert(P1.second <= P2.second);
    assert(abs(P1.first - P2.first) <= abs(P1.second - P2.second));

    int sep = abs(P1.first - P2.first);
    pair<int, int> sq = {P1.first + sep, P1.second + sep};
    vector<pair<ll, ll>> paths;
    ll result = distance(P1, sq, north, west);
    ll rem_distance = distance(P2, sq, north, west);
    int stepS = P2.second - sq.second;
    ll worst_path = ziz_zag(stepS, rem_distance, 5);
    paths.push_back({result, worst_path});
    if (in_interval(P1.first - 1, P2.first, north))
    {
        paths.push_back({result, ziz_zag(stepS, rem_distance, 1)});
    }

    auto i1 = Mless(P1.first - 2, north);
    if (i1 != -1)
    {
        int dist = P1.first - i1;
        if (2 * dist <= stepS)
        {
            pair<int, int> P3 = {i1, P1.second + dist};
            pair<int, int> P4 = {i1, P1.second + dist + stepS - 2 * dist};
            pair<int, int> P5 = {P1.first, P1.second + stepS};
            ll path = distance(P1, P3, north, west);
            path += distance(P4, P5, north, west);
            path += ziz_zag(stepS - 2 * dist, distance(P3, P4, north, west), 1);
            path += distance(P5, P2, north, west);
            paths.push_back({path, 0});
        }
    }
    auto i2 = Mgreater(P2.first + 1, north);
    if (i2 != -1)
    {
        pair<int, int> P3 = sq;
        int dist = i2 - P3.first;
        if (2 * dist <= stepS)
        {
            pair<int, int> P4 = {i2, P3.second + dist};
            pair<int, int> P5 = {i2, P3.second + dist + stepS - 2 * dist};
            ll path = distance(P3, P4, north, west);
            path += ziz_zag(stepS - 2 * dist, distance(P4, P5, north, west), 1);
            path += distance(P5, P2, north, west);
            paths.push_back({result, path});
        }
    }
    ll ans = paths[0].first + paths[0].second;
    for (auto p : paths)
    {
        ans = min(ans, p.first + p.second);
    }
    cout << ans << endl;
    // printf("Result is %Ld, Worst Path is %Ld \n", result, worst_path);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> NW[0][i];
        NW[1][n - 2 - i] = NW[0][i];
        if (NW[0][i] == 1)
        {
            NW_especial[0].insert(i);
            NW_especial[1].insert(n - 2 - i);
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> NW[2][i];
        NW[3][n - 2 - i] = NW[2][i];
        if (NW[2][i] == 1)
        {
            NW_especial[2].insert(i);
            NW_especial[3].insert(n - 2 - i);
        }
    }
    for (int j = 0; j < 4; j++)
    {
        for (int i = 1; i < n - 1; i++)
        {
            NW[j][i] += NW[j][i - 1];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int p1, p2, q1, q2;
        cin >> p1 >> p2 >> q1 >> q2;
        p1--, p2--, q1--, q2--;
        if (abs(p1 - q1) > abs(p2 - q2))
        {
            /*
            use north as east, and east as north.
            */
            pair<int, int> P1 = {p2, p1};
            pair<int, int> P2 = {q2, q1};

            if (P1.first > P2.first)
            {
                swap(P1, P2);
            }

            if (P1.second > P2.second)
            {
                P1 = {P1.first, n - 1 - P1.second};
                P2 = {P2.first, n - 1 - P2.second};
                solve(P1, P2, 2, 1);
            }
            else
            {
                solve(P1, P2, 2, 0);
            }
        }
        else
        {
            pair<int, int> P1 = {p1, p2};
            pair<int, int> P2 = {q1, q2};

            if (P1.first > P2.first)
            {
                swap(P1, P2);
            }

            if (P1.second > P2.second)
            {
                P1 = {P1.first, n - 1 - P1.second};
                P2 = {P2.first, n - 1 - P2.second};
                solve(P1, P2, 0, 3);
            }
            else
            {
                solve(P1, P2, 0, 2);
            }
        }
    }
}