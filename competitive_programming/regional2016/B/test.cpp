#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

vector<pair<int, int>> find_edges(int top, set<pair<int, int>> &edges)
{
    vector<pair<int, int>> result;
    while (edges.size() > 0)
    {
        auto next = edges.lower_bound({top, -1});
        if (next == edges.end() || (*next).first != top)
        {
            break;
        }
        else
        {
            auto current = *next;
            auto reverse = *edges.find({current.second, current.first});
            result.push_back(current);
            edges.erase(current);
            edges.erase(reverse);
        }
    }
    return result;
}

int A, B;
int main()
{
    int n, m;
    cin >> n >> m >> A >> B;
    map<int, int> degrees;
    set<pair<int, int>> rev;
    set<pair<int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        degrees[a]++;
        degrees[b]++;
        edges.insert({a, b});
        edges.insert({b, a});
    }
    for (auto z : degrees)
    {
        rev.insert({z.second, z.first});
    }

    while (rev.size() > 0)
    {
        int good = 1;
        auto st = *rev.begin();
        if (st.first < A)
        {
            good = 0;
            rev.erase(st);
            degrees[st.second] = 0;
            int top = st.second;
            vector<pair<int, int>> remove_edges = find_edges(top, edges);
            for (auto &z : remove_edges)
            {
                int first = z.first;
                int second = z.second;
                if (degrees[second] > 0)
                {
                    auto old = rev.find({degrees[second], second});
                    rev.erase(old);
                    degrees[second]--;
                    rev.insert({degrees[second], second});
                }
            }
        }
        if (!good)
        {
            continue;
        }
        
        auto ed = *(rev.rbegin());
        if (rev.size() < B + 1 || ed.first > rev.size() - 1 - B)
        {
            good = 0;
            rev.erase(ed);
            degrees[ed.second] = 0;
            int top = ed.second;
            vector<pair<int, int>> remove_edges = find_edges(top, edges);
            for (auto &z : remove_edges)
            {
                int first = z.first;
                int second = z.second;
                if (degrees[second] > 0)
                {
                    auto old = rev.find({degrees[second], second});
                    rev.erase(old);
                    degrees[second]--;
                    rev.insert({degrees[second], second});
                }
            }
        }

        if (good)
            break;
    }
    cout << rev.size() << endl;
}