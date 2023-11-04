// Problem: C. Torn Lucky Ticket
// Contest: Codeforces - Educational Codeforces Round 157 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1895/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<pair<string, int>> ss;
    vector<vector<int>> count;
    for (int i = 0; i < 46; i++)
    {
        count.push_back(vector<int>(6));
        for (int l = 0; l < 6; l++)
        {
            count[i][l] = 0;
        }
    }

    forn
    {
        char S[6];
        scanf("%s", S);
        int sum = 0;
        int len = 0;
        string g = "";
        for (int j = 0; j < 5; j++)
        {
            if (S[j] == '\0')
            {
                break;
            }
            else
            {
                g += S[j];
                sum += (S[j] - '0');
                len++;
            }
        }
        ss.push_back({g, sum});
        count[sum][len]++;
    }
    long long ans1 = 0;
    long long ans2 = 0;

    for (int i = 0; i < ss.size(); i++)
    {
        for (int len_s = 1; len_s <= ss[i].first.size(); len_s++)
        {
            int half_sum_preffix = 0;
            int half_sum_suffix = 0;
            for (int l = 0; l < len_s; l++)
            {
                half_sum_preffix += ss[i].first[l] - '0';
            }
            for (int l = ss[i].first.size() - len_s; l < ss[i].first.size(); l++)
            {
                half_sum_suffix += ss[i].first[l] - '0';
            }
            int rem_sum_preffix = ss[i].second - half_sum_preffix;
            int rem_sum_suffix = ss[i].second - half_sum_suffix;
            int required_len = 2 * len_s - ss[i].first.size();
            if (len_s == ss[i].first.size())
            {
                ans2 += count[max(0, half_sum_preffix - rem_sum_preffix)][max(0, required_len)];
                ans2 += count[max(0, half_sum_suffix - rem_sum_suffix)][max(0, required_len)];
            }
            else
            {
                ans1 += count[max(0, half_sum_preffix - rem_sum_preffix)][max(0, required_len)];
                ans1 += count[max(0, half_sum_suffix - rem_sum_suffix)][max(0, required_len)];
            }
        }
    }
    cout << ans1 + ans2 / 2 << endl;
    return;
}

int main()
{
    int test_cases = 1;

    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}