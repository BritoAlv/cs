#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

int vote1(map<int, int> votes, int w, int option)
{
    map<int, int> copy;
    for (auto z : votes)
    {
        copy[z.first] = z.second;
    }
    copy[option]++;
    int maxn = copy[w];
    int max2 = 0;
    for (auto z : copy)
    {
        if (z.first != w)
        {
            max2 = max(max2, z.second);
        }
    }
    return max2 >= maxn;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> P(n);
    forn
    {
        cin >> P[i].first >> P[i].second;
    }
    forn
    {
        int w = i + 1;
        int good = 1;
        for (int t = 0; t < (1 << n); t++)
        {
            map<int, int> votes;
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    int first = (t & (1 << j)) > 0;
                    if (first)
                        votes[P[j].first]++;
                    else
                        votes[P[j].second]++;
                }
            }
            int good2 = vote1(votes, w, P[i].first);
            int good3 = vote1(votes, w, P[i].second);
            if (!good2 && !good3)
            {
                good = 0;
                break;
            }
        }
        if (good)
            cout << i << wp;
    }
    cout << endl;
}
