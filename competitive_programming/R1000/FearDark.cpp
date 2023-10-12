// Problem: B. Fear of the Dark
// Contest: Codeforces - Educational Codeforces Round 156 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1886/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

double distance(int a, int b, int c, int d)
{
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

void Solve()
{
    int Mx, My;
    cin >> Mx >> My;
    int Ax, Ay;
    cin >> Ax >> Ay;
    int Bx, By;
    cin >> Bx >> By;

    double min_distAO = distance(0, 0, Ax, Ay);
    double min_distAP = distance(Mx, My, Ax, Ay);
    double min_distBO = distance(0, 0, Bx, By);
    double min_distBP = distance(Bx, By, Mx, My);

    double distanceAB = distance(Ax, Ay, Bx, By) / 2;

    vector<double> dist;
    dist.push_back(max(min_distAO, min_distAP));
    dist.push_back(max(min_distBO, min_distBP));

    double candidate = distanceAB;
    candidate = max(candidate, min(min_distAP, min_distBP));
    candidate = max(candidate, min(min_distAO, min_distBO));
    dist.push_back(candidate);

    double min = dist[0];
    for (auto x : dist)
    {
        if (x < min)
        {
            min = x;
        }
    }
    printf("%0.6f\n", min);
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
