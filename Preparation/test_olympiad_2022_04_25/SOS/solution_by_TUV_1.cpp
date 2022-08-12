#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Point {
    int x, y;
};

struct HelpShip {
    string name;
    Point location;
    int maxSpeed;
    double dest = INT_MAX;
};

void calculateDest(vector<HelpShip> helpShips, Point targetLocation) {
    
    HelpShip currentMinDest = helpShips[0];
    
    for(int i = 0; i < helpShips.size(); i++) {
        double x = abs(helpShips[i].location.x - targetLocation.x);
        double y = abs(helpShips[i].location.y - targetLocation.y);
        
        
        double maxSpeed = helpShips[i].maxSpeed;
        
        
        helpShips[i].dest = (x / maxSpeed) + (y / maxSpeed);
        
       // cout << "calculated dest " <<  helpShips[i].dest << endl;
        
        if (helpShips[i].dest < currentMinDest.dest) {
            currentMinDest = helpShips[i];
        }
             
    }
    
    cout << currentMinDest.name << endl;
}


int main() {
    int T;
    cin >> T;
    Point target;
    while(T--) {
        cin >> target.x >> target.y;
        
        int N;
        cin >> N;
        vector<HelpShip> helpShips;
        for(int i = 0; i < N; i++) {
            string name;
            Point location;
            int maxSpeed;
            
            cin >> name >> location.x >> location.y >> maxSpeed;
            
            helpShips.push_back(HelpShip {name, location, maxSpeed});
            
        }
        
        calculateDest(helpShips, target);
    }
    return 0;
}
