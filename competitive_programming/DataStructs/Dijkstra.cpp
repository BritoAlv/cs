const int INF = 1e9;
vector<int> distances(int s, vector<vector<int>> g)
{
    int n = g.size();
    vector<int> d = vector<int>(n, INF);
    d[s] = 0;
    set<pair<int, int>> PQ;
    forn
    {
        PQ.insert({d[i], i});
    }
    while (PQ.size() > 0)
    {
        auto next = *(PQ.begin());
        PQ.erase(next);
        for (auto z : g[next.second])
        {
            int q_w = 1;
            if (d[z] > d[next.second] + q_w)
            {
                PQ.erase({d[z], z});
                d[z] = d[next.second] + q_w;
                PQ.insert({d[z], z});
            }
        }
    }
    return d;
}