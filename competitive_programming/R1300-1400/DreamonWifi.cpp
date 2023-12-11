// Problem: B. Dreamoon and WiFi
// Contest: Codeforces - Codeforces Round 272 (Div. 2)
// URL: https://codeforces.com/problemset/problem/476/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back

int factorial(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}

using namespace std;

void Solve()
{
    string S, s;
    cin >> S >> s;
    int end_position = 0;
    int numberplus = 0;
    for (int i = 0; i < S.size(); i++)
    {
        end_position += (S[i] == '+');
        numberplus += (S[i] == '+');
        end_position -= (S[i] == '-');
    }
    int end_position2 = 0;
    int number_s = 0;
    for (int i = 0; i < S.size(); i++)
    {
        end_position2 += (s[i] == '+');
        end_position2 -= (s[i] == '-');
        number_s += (s[i] == '?');
        numberplus -= (s[i] == '+');
    }
    // create a string of len number_s such that:
    // end_position2 + number_s = end_position.
    if (numberplus < 0 || numberplus > number_s)
    {
        cout << 0 << endl;
    }
    else
    {
        double denominator = (double)(1 << number_s);
        double numerator = factorial(number_s);
        numerator /= (factorial(numberplus) * factorial(number_s - numberplus));
        printf("%0.9f\n", numerator / denominator);
    }

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
