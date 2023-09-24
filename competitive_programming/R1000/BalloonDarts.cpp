// Problem: B. Balloon Darts
// Contest: Codeforces - 2023-2024 ICPC German Collegiate Programming Contest (GCPC 2023)
// URL: https://codeforces.com/gym/104466/problem/B
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Math Proof: fix a point and iterate over all the lines that pass through it,
// now for every 5 points that are not on that fixed line, there should be 3 colinears,
// if it were possible doing it with that fixed line
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)

#define linea pair<pair<long long, long long>, pair<long long, long long>>
#define point pair<long long, long long>
using namespace std;

bool are_colinear(pair<long, long> A, pair<long, long> B, pair<long, long> C)
{
    return (A.second - B.second) * (A.first - C.first) == (A.first - B.first) * (A.second - C.second);
}

void Solve()
{
    int n;
    cin >> n;
    vector<pair<long long, long long>> points;
    int t = n;
    while (t > 0)
    {
        long long x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
        t--;
    }

    if (n <= 6)
    {
        cout << "possible" << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            vector<linea> set;
            set.push_back(make_pair(points[i], points[j]));
            vector<point> puntos;
            for (int z = 0; z < n; z++)
            {
                bool iss_colinear = false;
                for (int k = 0; k < set.size(); k++)
                {
                    if (are_colinear(set[k].first, set[k].second, points[z]))
                    {
                        iss_colinear = true;
                        break;
                    }
                }
                if (!iss_colinear)
                {
                    puntos.push_back(points[z]);
                }

                if (puntos.size() == 5)
                {
                    bool added = false;
                    pair<long long, long long> point1;
                    pair<long long, long long> point2;
                    pair<long long, long long> point3;
                    for (int h = 0; h < 5 && !added; h++)
                    {
                        for (int d = h + 1; d < 5 && !added; d++)
                        {
                            for (int r = d + 1; r < 5 && !added; r++)
                            {
                                if (are_colinear(puntos[h], puntos[d], puntos[r]))
                                {
                                    point1 = puntos[h];
                                    point2 = puntos[d];
                                    point3 = puntos[r];
                                    set.push_back(make_pair(puntos[h], puntos[d]));
                                    added = true;
                                    break;
                                }
                            }
                        }
                    }
                    vector<pair<long long, long long>> updated;
                    for (int t = 0; t < 5; t++)
                    {
                        if ((puntos[t] != point1) && (puntos[t] != point2) && (puntos[t] != point3))
                        {
                            updated.push_back(puntos[i]);
                        }
                    }
                    puntos = updated;
                }

                if (set.size() > 3)
                {
                    break;
                }
            }
        }
    }

    return;
}

int main()
{
    Solve();
    return 0;
}
