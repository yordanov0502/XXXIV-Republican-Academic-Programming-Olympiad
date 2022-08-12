#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 12346;//broj promenlivi


int main() {

    unsigned int m;//modul
    unsigned int n;//broj promoenlivi

    int DP[2][MAX_N];

    int a[MAX_N];

 

    while (true) {
    
        cin >> n;
        cin >> m;

        if (n == 0 && m == 0) { break; }

        DP[0][n] = 0;


        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            DP[0][i] = 0;

        }
        
        DP[0][0] = 1;

        for (int w = 0; w < n; w++)
        {
            DP[1][0] = 1;

            for (int j = 1; j <= n; j++)
            {
                DP[1][j] = (DP[0][j] + (long long)a[w] * DP[0][j - 1]) % m;
            }

            for (int j = 0; j <= n; j++)
            {
                DP[0][j] = DP[1][j];
            }

            
        }

        long long max=DP[1][0];

        for (int j = 1; j <= n; j++)
        {
           if (DP[1][j] > max) { max = DP[1][j]; }
        }

        cout << max << endl;
        
    }


    return 0;
}
