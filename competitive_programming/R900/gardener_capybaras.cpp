// Problem: A2. Gardener and the Capybaras (hard version)
// Contest: Codeforces - Codeforces Round 843 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1775/A2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    string input;
    cin >> input;
    if (input[0] == input[input.size() - 1])
    {
        cout << input[0] << ' ' << input.substr(1, input.size() - 2) << ' ' << input[input.size() - 1] << '\n';
    }
    else
    {
        if (input[0] == 'a')
        {
            int index = 0;
            while (input[index + 1] != 'b')
            {
                index++;
            }
            if (index > 0)
            {
                for (int i = 0; i < index; i++)
                {
                    cout << input[i];
                }
                cout << ' ' << input[index] << ' ' << input.substr(index + 1) << '\n';
            }
            else
            {
                cout << input[0] << ' ' << input.substr(1, input.size() - 2) << ' ' << 'b' << '\n';
            }
        }
        else
        {
            int index = 0;
            while (input[index + 1] != 'a')
            {
                index++;
            }
            if (index == 0)
            {
                cout << input[0] << ' ' << input[1] << ' ' << input.substr(2) << '\n';
            }
            else
            {
                cout << input[0] << ' ';
                for (int i = 1; i <= index; i++)
                {
                    cout << input[i];
                }
                cout << ' ' << input.substr(index + 1) << '\n';
            }
        }
    }
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
