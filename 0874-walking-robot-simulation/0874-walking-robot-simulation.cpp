class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int,int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        unordered_set<string> obs;
        for (auto &o : obstacles) {
            obs.insert(to_string(o[0]) + "," + to_string(o[1]));
        }
        
        int x = 0, y = 0;
        int d = 0; 
        
        int maxDist = 0;
        
        for (int cmd : commands) {
            if (cmd == -2) {
                d = (d + 3) % 4; 
            } 
            else if (cmd == -1) {
                d = (d + 1) % 4; 
            } 
            else {
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;
                    
                    string key = to_string(nx) + "," + to_string(ny);
                    
                    if (obs.count(key)) break; 
                    
                    x = nx;
                    y = ny;
                    
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        return maxDist;
    }
};