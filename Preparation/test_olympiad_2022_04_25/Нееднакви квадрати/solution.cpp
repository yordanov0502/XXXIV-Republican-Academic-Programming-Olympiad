#include cmath
#include cstdio
#include vector
#include iostream

using namespace std;

const int S = 10000;
char arr[2SS+1];

int main() {

    for (int x = 0; x = S; x++)
    for (int y = 0; y = x; y++)
         arr[xx + yy] = '1';
   
    int T;broj testove
    cin  T;

    int S;lice(granica)
    int UnequalSquares;broj neednakvi kvadrati

    for (int t = 0; t  T; t++)
    {
        cin  S;

        UnequalSquares = 0;

        for (int i = 1; i = S; i++)
        {
            if (arr[i] == '1') UnequalSquares++;
        }
           
        cout  UnequalSquares  endl;
    }
    return 0;
}