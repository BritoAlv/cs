#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define ld long double
using namespace std;

ld si_max = 100;
ld area_calculator(vector<int> clasif)
{
    int n = clasif.size();
    ld triangle_area = sin(( (M_PI/ 180) * (360.0 / (ld)n))) * si_max * si_max;
    triangle_area /= 2;

    auto query_area = [&triangle_area](ld a, ld b) -> ld { return triangle_area * (a / si_max) * (b / si_max); };

    ld result = 0;
    for (int i = 0; i < n; i++)
    {
        result += query_area( clasif[i], clasif[(i + 1) % n]);
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> clas(n);
    forn
    {
        cin >> clas[i];
        assert(clas[i] <= si_max);
    }
    cout << setprecision(6);
    ld maxx = area_calculator(clas);
    vector<int> result = clas;
    while (next_permutation(clas.begin(), clas.end()))
    {
        auto area = area_calculator(clas);
        if(area > maxx)
        {
            maxx = area;
            result = vector<int>();
            for(auto z : clas)
            {
                result.pb(z);
            }
        }
    }
    cout << maxx << endl;
    for(auto e: result)
    {
        cout << e << wp;
    }
    cout << endl;
}