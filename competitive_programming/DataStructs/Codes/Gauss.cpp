#define ld long double


vector<ld> gauss(vector<vector<ld>> &mx)
{
    // matrix A, b
    int n_equations = (int)mx.size();
    int n_variables = (int)mx[0].size() - 1;
    for (int i = 0; i < n_variables; i++)
    {
        int pos = i;
        for (int j = i + 1; j < n_equations; j++)
        {
            auto one = mx[j][i];
            auto sec = mx[pos][i];
            if(one < 0)
            {
                one *= -1;
            }
            if(sec < 0)
            {
                sec *= -1;
            }
            if (one > sec)
            {
                pos = j;
            }
        }
        for (int j = 0; j < n_variables + 1; j++)
        {
            ld temp = mx[i][j];
            mx[i][j] = mx[pos][j];
            mx[pos][j] = temp;
        }
        /*
        assume that the absolute value is greater than zero.
        */
        ld now = mx[i][i];
        for (int j = 0; j < n_variables + 1; j++)
        {
            mx[i][j] /= now;
        }
        for (int j = 0; j < n_equations; j++)
        {
            if (j != i)
            {
                ld now = mx[j][i];
                for (int k = 0; k < n_variables + 1; k++)
                {
                    mx[j][k] -= (mx[i][k] * now);
                }
            }
        }
    }
    vector<ld> ret;
    for (int i = 0; i < n_variables; i++)
    {
        ret.pb(mx[i][n_variables]);
    }
    return ret;
}