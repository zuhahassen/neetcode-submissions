class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)  {
        int fleets = 1; 
        vector<pair<int,int>> pos; 

        for (int i = 0; i < position.size(); i++) {
            pair<int,int> p = {position[i], speed[i]};
            pos.push_back(p);
        }

        sort(pos.rbegin(), pos.rend());

        double prevTime = (double)(target - pos[0].first) / pos[0].second; 

        for (int i = 1; i < pos.size(); i++) {
            double currTime = (double)(target - pos[i].first) / pos[i].second; 

            if (currTime > prevTime) {
                fleets++; 
                prevTime = currTime; 
            }
        }

        return fleets; 
    }
};
