class Robot {
public:
    int w, h, x, y, dir;
    int cycle;
    
    vector<string> dirs = {"East", "North", "West", "South"};
    
    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0; // East
        
        cycle = 2 * (w + h - 2);
    }
    
    void step(int num) {
        num %= cycle;
        
        // 🔥 FIX HERE
        if (num == 0) num = cycle;
        
        while (num--) {
            int nx = x, ny = y;
            
            if (dir == 0) nx++;
            else if (dir == 1) ny++;
            else if (dir == 2) nx--;
            else ny--;
            
            // boundary check
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4;
                
                if (dir == 0) nx = x + 1, ny = y;
                else if (dir == 1) nx = x, ny = y + 1;
                else if (dir == 2) nx = x - 1, ny = y;
                else nx = x, ny = y - 1;
            }
            
            x = nx;
            y = ny;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dirs[dir];
    }
};