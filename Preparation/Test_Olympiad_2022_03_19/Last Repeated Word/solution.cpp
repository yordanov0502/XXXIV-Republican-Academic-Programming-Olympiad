#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <map>
using namespace std;


int main() {
    
    int N;//broj dumi
    cin >> N;

    string* array = new string[N];

    map<string, int> dictionary;
    map<string, int>::iterator it;

    int counter = 1;

   

    for (int i = 0; i < N; i++)
    {
        cin >> array[i];

        if (dictionary.count(array[i])) {it = dictionary.find(array[i]); it->second = it->second + 1;}

        else {dictionary.insert(std::pair<string, int>(array[i],counter));}
    }


    for (int i = N-1; i >=0; i--)
    {
        if (dictionary.count(array[i]))
        {
            it = dictionary.find(array[i]);
            if (it->second >= 3) { cout << i + 1; break; }
        }
    }



    return 0;
}