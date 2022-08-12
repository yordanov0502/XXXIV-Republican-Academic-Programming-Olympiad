#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solve(vector<int> &blocks) {
    vector<int> maxes(blocks.size(), 0);
    int leftMax = 0;
    
    for(int i = 0; i < blocks.size(); i++) {
        int block = blocks[i];
        maxes[i] = leftMax;
        leftMax = max(leftMax, block);
    }
    
    int rightMax = 0;

    for(int i = blocks.size() - 1; i >= 0; i--) {
        int block = blocks[i];
        int minBlock = min(rightMax, maxes[i]);
        
        if (block < minBlock) {
            maxes[i] = minBlock - block;
        } else {
            maxes[i] = 0;
        }
        
        rightMax = max(rightMax, block);
    }
    
    long long total = 0;
    
    for(int i = 0; i < blocks.size(); i++) {
        total += maxes[i];
    }
    
    return total * 100;
}

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int N, H;
        cin >> N >> H;
        vector<int> blocks;
        while(N--) {
            int block;
            cin >> block;
            if (block > H)
                block = H;
            
            blocks.push_back(block);
        }
        
        cout << solve(blocks) << endl;
    }
    return 0;
}