// Problem: C1. Hacking Numbers (Easy Version)
// Contest: Codeforces - Codeforces Round 1025 (Div. 2)
// URL: https://codeforces.com/contest/2109/problem/C1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

// je m appelle Alvaro Brito. J ai 22 ans.
#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

int test_cases;
using namespace std;

int do_add(int y)
{
    cout << "add" << wp << y << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int do_mul(int y)
{
    cout << "mul" << wp << y << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int do_div(int y)
{
    cout << "div" << wp << y << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int do_digit()
{
    cout << "digit" << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int do_ans()
{
    cout << "!" << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void Solve()
{
    int n;
    cin >> n;
    do_mul(9);
    for (int i = 0; i < 2; i++)
    {
        do_digit();
    }
    do_add(n - 9);
    do_ans();
}

int main()
{
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}
