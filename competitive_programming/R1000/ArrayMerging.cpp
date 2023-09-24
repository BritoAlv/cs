// Problem: B. Array merging
// Contest: Codeforces - Codeforces Round 875 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1831/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: implementation but almost doesnt work.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    map<int, int> max_A;
    map<int, int> max_B;

    vector<pair<int, int>> A_tup;
    vector<pair<int, int>> B_tup;

    forn
    {
        int t;
        cin >> t;
        if (A_tup.size() == 0)
        {
            A_tup.push_back(make_pair(t, 1));
        }
        else
        {
            if (t == A_tup[A_tup.size() - 1].first)
            {
                A_tup[A_tup.size() - 1].second++;
            }
            else
            {
                if (max_A.find(A_tup[A_tup.size() - 1].first) == max_A.end())
                {
                    max_A[A_tup[A_tup.size() - 1].first] = A_tup[A_tup.size() - 1].second;
                }
                else
                {
                    max_A[A_tup[A_tup.size() - 1].first] =
                        max(max_A[A_tup[A_tup.size() - 1].first], A_tup[A_tup.size() - 1].second);
                }
                A_tup.push_back(make_pair(t, 1));
            }
        }
    }

    if (max_A.find(A_tup[A_tup.size() - 1].first) == max_A.end())
    {
        max_A[A_tup[A_tup.size() - 1].first] = A_tup[A_tup.size() - 1].second;
    }
    else
    {
        max_A[A_tup[A_tup.size() - 1].first] =
            max(max_A[A_tup[A_tup.size() - 1].first], A_tup[A_tup.size() - 1].second);
    }
    forn
    {
        int t;
        cin >> t;
        if (B_tup.size() == 0)
        {
            B_tup.push_back(make_pair(t, 1));
        }
        else
        {
            if (t == B_tup[B_tup.size() - 1].first)
            {
                B_tup[B_tup.size() - 1].second++;
            }
            else
            {
                if (max_B.find(B_tup[B_tup.size() - 1].first) == max_B.end())
                {
                    max_B[B_tup[B_tup.size() - 1].first] = B_tup[B_tup.size() - 1].second;
                }
                else
                {
                    max_B[B_tup[B_tup.size() - 1].first] =
                        max(max_B[B_tup[B_tup.size() - 1].first], B_tup[B_tup.size() - 1].second);
                }
                B_tup.push_back(make_pair(t, 1));
            }
        }
    }

    if (max_B.find(B_tup[B_tup.size() - 1].first) == max_B.end())
    {
        max_B[B_tup[B_tup.size() - 1].first] = B_tup[B_tup.size() - 1].second;
    }
    else
    {
        max_B[B_tup[B_tup.size() - 1].first] =
            max(max_B[B_tup[B_tup.size() - 1].first], B_tup[B_tup.size() - 1].second);
    }

    int answer = 0;

    for (const auto &myPair : max_A)
    {
        int result = myPair.second;
        if (max_B.find(myPair.first) != max_B.end())
        {
            result += max_B[myPair.first];
        }
        answer = max(answer, result);
    }

    for (const auto &myPair : max_B)
    {
        int result = myPair.second;
        if (max_A.find(myPair.first) != max_A.end())
        {
            result += max_A[myPair.first];
        }
        answer = max(answer, result);
    }
    cout << answer << endl;
    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
