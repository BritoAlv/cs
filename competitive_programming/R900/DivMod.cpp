// Problem: B. DIV + MOD
// Contest: Codeforces - Codeforces Round 776 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1650/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: if l != r, then goal is find element that gives remainder (a-1) but if it not found, then candidate
// is this number of check if there is a number divisible by a in the interval, that will
// find remainder (a-1), notice that in any case is the greater number in the interval divisible by (a-1).
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

int f(int x, int a)
{
    return x / a + x % a;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int get_ans(int l, int r, int a, int previous_answer)
{
    if (l > r)
    {
        return previous_answer;
    }
    else if (l == r)
    {
        return max(previous_answer, f(l, a));
    }
    else if (r % a == 0)
    {
        return max(f(r - 1, a), max(previous_answer, f(r, a)));
    }
    else
    {
        return get_ans(l, r - r % a, a, max(previous_answer, f(r, a)));
    }
}

void Solve()
{
    int l, r, a;
    cin >> l >> r >> a;
    cout << get_ans(l, r, a, f(l, a)) << endl;
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
