#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define D(x) cerr<<"at "<<__LINE__<<" "<<#x<<"="<<(x)<<endl;
using namespace std;

vector<vector<char>> map(10);
vector<string> words;
string res = "";


void init() {
    map[2] = {'A', 'B', 'C'};
    map[3] = {'D', 'E', 'F'};
    map[4] = {'G', 'H', 'I'};
    map[5] = {'J', 'K', 'L'};
    map[6] = {'M', 'N', 'O'};
    map[7] = {'P', 'Q', 'R', 'S'};
    map[8] = {'T', 'U', 'V'};
    map[9] = {'W', 'X', 'Y', 'Z'};
}

void try_to_match(vector<int> keys) {
    bool found = false;
    vector<int> vec(words.size());
    for(int i = 0; i < keys.size(); i++) {
        vector<char> chars = map[keys[i]];
        
        for(char c: chars) {

            for(int j = 0; j < words.size(); j++) {
                if(keys.size() <= words[j].size())
                   if(words[j].at(i) == c)
                       vec[j]++;
            }

        }  
       
    }
    vector<string> found_words;
    
     for(int i = 0; i < vec.size(); i++) {
         if(vec[i] == words[i].size()) {
             found_words.push_back(words[i]);
         }
     }
    
    if(found_words.size() > 1) {
        sort(found_words.begin(),found_words.end());
        res += found_words[0];
    } else if (found_words.size() == 1) {
        res += found_words[0];
    } else {
        string s = "";
        for(int i = 0; i < keys.size(); i++) {
            s.push_back('*');
        }
        
        res += s;
    }
    

    
    res.push_back(' ');

}


int main() {
    init();
    int T;
    cin >> T;
    while(T--) {
        
        int M;
        cin >> M;
        
        for(int i = 0; i < M; i++) {
            string word;
            cin >> word;
            words.push_back(word);
        }
        
        int K;
        cin >> K;
        queue<int> presses;
        for(int i = 0; i < K; i++) {
            int key;
            cin >> key;
            presses.push(key);
        }
        
        vector<int> keys;
        while(!presses.empty()) {
              
            int key = presses.front();
            if (key != 1) {
                keys.push_back(key);
            } else {
                try_to_match(keys);
                keys.clear();  
            }
            
            presses.pop();
            
        }
        
        try_to_match(keys);
        words.clear();
        keys.clear();  
        cout << res << endl;
        res = "";
    }
    return 0;
}
