#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void BruteSolve()
{
    return;
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> tokens = {};
    set<char> vals = {'+', '-', '*', ' '};
    int nn = n;
    while (nn > 0)
    {
        string S;
        cin >> S;
        if (vals.find(S[0]) == vals.end())
        {
            nn -= 1;
        }
        tokens.pb(S);
    }
    map<int, pi> assigned;
    vector<pi> seq_info;
    int number_index = 0;
    for (int i = 0; i < tokens.sz; i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-")
        {
            continue;
        }
        int r = stoi(tokens[i]);
        assigned[number_index++] = {seq_info.sz, r % 2};
        pi u = {0, 0};
        u.first += r % 2;
        u.second += !(r % 2);
        int ed = i;
        while (ed + 1 < tokens.sz && tokens[ed + 1] != "+" && tokens[ed + 1] != "-")
        {
            if (tokens[ed + 1] != "*")
            {
                int r = stoi(tokens[ed + 1]);
                assigned[number_index++] = {seq_info.sz, r % 2};
                u.first += r % 2;
                u.second += !(r % 2);
            }
            ed += 1;
        }
        seq_info.pb(u);
        i = ed;
    }
    int global_info = 0;
    for (auto x : seq_info)
    {
        if (x.second == 0)
        {
            global_info++;
        }
    }
    cout << (global_info % 2 ? "odd" : "even") << endl;

    while (m > 0)
    {
        int index, new_number;
        cin >> index >> new_number;
        index--;

        // update stuff
        pi pos = assigned[index];
        global_info -= (seq_info[pos.first].second == 0);
        seq_info[pos.first].first -= pos.second;
        seq_info[pos.first].second -= !(pos.second);

        seq_info[pos.first].first += new_number % 2;
        seq_info[pos.first].second += !(new_number % 2);

        assigned[index] = {assigned[index].first, new_number % 2};
        global_info += (seq_info[pos.first].second == 0);
        cout << (global_info % 2 ? "odd" : "even") << endl;
        m--;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
