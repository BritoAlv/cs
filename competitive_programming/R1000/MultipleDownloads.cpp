// Problem: M. Multiple Downloads
// Contest: Codeforces - 2023 Argentinian Programming Tournament (TAP)
// URL: https://codeforces.com/gym/104603/problem/M
// Memory Limit: 1024 MB
// Time Limit: 500 ms
// Math Proof:
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
    double initial_vel;

    cin >> n >> initial_vel;
    vector<double> sizeP;
    vector<double> sizeNP;

    while (n > 0)
    {
        char letter;
        double size;
        cin >> letter >> size;
        if (letter == 'P')
        {
            sizeP.push_back(size);
        }
        else
        {
            sizeNP.push_back(size);
        }
        n--;
    }
    sort(sizeP.begin(), sizeP.end());
    sort(sizeNP.begin(), sizeNP.end());

    double time_elapsedP = 0;
    double size_downloadedP = 0;
    for (int i = 0; i < sizeP.size(); i++)
    {
        if (sizeP[i] - size_downloadedP > 0)
        {
            double time = (sizeP.size() - i) * (sizeP[i] - size_downloadedP) / 3;
            time_elapsedP += time;
            size_downloadedP += (sizeP[i] - size_downloadedP);
        }
    }

    double time_elapsedNP = 0;
    double size_downloadedNP = 0;

    for (int i = 0; i < sizeNP.size(); i++)
    {
        if (sizeNP[i] - size_downloadedNP > 0)
        {
            double time = (sizeNP.size() - i) * (sizeNP[i] - size_downloadedNP);
            time_elapsedNP += time;
            size_downloadedNP += (sizeNP[i] - size_downloadedNP);
        }
    }
    if (time_elapsedP < time_elapsedNP)
    {
        cout << (4 * time_elapsedP + (time_elapsedNP - time_elapsedP)) / initial_vel << endl;
    }
    else
    {
        cout << (4 * time_elapsedNP + 3 * (time_elapsedP - time_elapsedNP)) / initial_vel << endl;
    }
    return;
}

int main()
{
    Solve();
    return 0;
}
