#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int CountWays(int distance)
{
    int* counter = new int[distance + 1];

    counter[0] = 1;
    counter[1] = 1;
    counter[2] = 2;
    counter[3] = 3;
    counter[4] = 5;
    counter[5] = 8;

    for (int i = 6; i <= distance; i++)
    {
        counter[i] = counter[i - 1] + counter[i - 2];

        if (i == distance) {break;}
    }

    return counter[distance];
}

int main() {
   
    int N;//broj testove
    cin >> N;

    int* D = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> D[i];
        cout << CountWays(D[i]) << endl;
    }

    delete[] D;
    return 0;
}