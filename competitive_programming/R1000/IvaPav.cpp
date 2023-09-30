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
    vector<vector<bool>> matrix;
    for (int i = 0; i < 32; i++)
    {
        vector<bool> a(n);
        matrix.push_back(a);
    }
    forn
    {
        long long t;
        cin >> t;
        for (int poww = 0; poww < 32; poww++)
        {

            matrix[poww][i] = (t & (1ll << poww));
        }
    }

    vector<vector<long long>> op_matrix;
    for (auto y : matrix)
    {
        vector<long long> row(n);
        row[n - 1] = (y[n - 1] ? 1 : 0);
        for (int i = n - 2; i >= 0; i--)
        {
            if (!y[i])
            {
                row[i] = 0;
            }
            else
            {
                row[i] = row[i + 1] + 1;
            }
        }
        op_matrix.push_back(row);
    }

    int q;
    cin >> q;
    while (q > 0)
    {
        int l, k;
        cin >> l >> k;
        l--;
        vector<bool> b(32);
        vector<int> answers;
        for (int poww = 0; poww < 32; poww++)
        {
            b[poww] = (k & (1ll << poww));
        }

        int previous_max = 32;
        int prev_k_min = n;
        bool solution = true;
        for (int i = 31; i >= 0; i--)
        {
            if (b[i])
            {
                int not_pow_k_max_round = 0;
                int pow_k_min_round = 0;
                for (int j = previous_max - 1; j >= i; j--)
                {
                    int count = op_matrix[j][l];
                    if (j != i)
                    {
                        not_pow_k_max_round = max(not_pow_k_max_round, count);
                    }
                    else
                    {
                        pow_k_min_round = count;
                    }
                }
                previous_max = i;
                if (not_pow_k_max_round > 0)
                {
                    answers.push_back(l + min(not_pow_k_max_round, prev_k_min));
                    prev_k_min = min(prev_k_min, pow_k_min_round);
                }
                else if (not_pow_k_max_round == 0)
                {
                    if (pow_k_min_round > 0)
                    {
                        prev_k_min = min(prev_k_min, pow_k_min_round);
                    }
                    else
                    {
                        solution = false;
                        break;
                    }
                }
            }
        }
        if (solution)
        {
            answers.push_back(l + prev_k_min);
        }
        int max = -1;
        for (int j = 0; j < answers.size(); j++)
        {
            if (answers[j] > max)
            {
                max = answers[j];
            }
        }
        cout << max << wp;
        q--;
    }
    cout << endl;
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