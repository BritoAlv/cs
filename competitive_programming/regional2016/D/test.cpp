#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define ld long double
using namespace std;

ld si_max = 100;
const ld PI = 3.14159265358979323846;

ld area_calculator(vector<int> clasif)
{
    int n = clasif.size();
    ld triangle_area = sin(( (PI/ 180) * (360.0 / (ld)n))) * si_max * si_max;
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
    deque<int> vals;
    vector<int> clas(n);
    forn
    {
        cin >> clas[i];
    }
    sort(clas.begin(), clas.end());
    int right = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if(right)
        {
            vals.push_front(clas[i]);
        }
        else
        {
            vals.push_back(clas[i]);
        }
        right = !right;
    }
    clas = vector<int>();
    while(vals.size() > 0)
    {
        clas.push_back(vals.front());
        vals.pop_front();
    }
    ld maxx = area_calculator(clas);
    maxx = round(maxx * 1000) / 1000;
    printf("%.3Lf", maxx);
    cout << endl;
}