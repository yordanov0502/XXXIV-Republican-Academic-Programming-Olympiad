#include <iostream>
using namespace std;

int occ[13001];
int vals[10000001];

int main()
{

    int tests;
    cin >> tests;

    for (int t = 0; t < tests; t++)
    {


        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= k; i++)
            occ[i] = 0;

        int firstPosition = 1;
        int lastPosition = 1;

        for (int i = 1; i <= n; i++)
            cin >> vals[i];            

        int pos = 1;
        int diff = 0;

        int min = n + 1;

        int minFirstPosition = -1;
        int minLastPosition = -1;
        int diff_kind_count = 0;

        while (true)
        {
            if (diff_kind_count == k) {
                while (true)
                {
                    occ[vals[firstPosition]]--;
                    if (occ[vals[firstPosition]] == 0) {
                        diff_kind_count--;
                        if (min > lastPosition - firstPosition)
                        {
                            min = lastPosition - firstPosition;
                            minFirstPosition = firstPosition;
                            minLastPosition = lastPosition - 1;
                        }
                        firstPosition++;
                        break;
                    }
                    firstPosition++;
                }
            }

            if (lastPosition <= n) {
                if (occ[vals[lastPosition]] == 0)
                    diff_kind_count++;
                occ[vals[lastPosition]]++;
                lastPosition++;
            } else 
                break;
        }

        cout << minFirstPosition << " " << minLastPosition << endl;
    }

    return 0;
}