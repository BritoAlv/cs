// Problem: A. Ela Sorting Books
// Contest: Codeforces - Dytechlab Cup 2022
// URL: https://codeforces.com/problemset/problem/1737/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: it's greedy becuase you have to maximize
// the answer for the first compartment, no matter what, then
// for the second, and so on. So how to maximize it for first
// compartment.
//
// Powered by CP Editor (https://cpeditor.org)
#include <bits/stdc++.h>
using namespace std;

int test_cases;
map<char, int> count_letter;
char algorithm(int t)
{
    char it = 'a';
    if (count_letter[it] == 0)
    {
        return it;
    }
    int count = 0;
    while (count_letter[it] > 0 && count < t)
    {
        count++;
        count_letter[it]--;
        it++;
    }

    return it;
}

void initialize()
{
    for (char i = 'a'; i <= 'z'; i++)
    {
        count_letter[i] = 0;
    }
    return;
}

void Solve()
{
    initialize();
    int n, k;
    cin >> n >> k;
    int tt = n / k;
    while (n > 0)
    {
        char t;
        cin >> t;
        count_letter[t]++;
        n--;
    }
    string answer = "";
    while (k > 0)
    {
        answer += algorithm(tt);
        k--;
    }
    cout << answer << '\n';
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
