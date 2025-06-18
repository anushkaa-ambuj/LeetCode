class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int, vector<vector<int>>> mp;

        for(auto& point: points){
            int dist = point[0]*point[0] + point[1]*point[1];
            mp[dist].push_back(point);
        }

        vector<vector<int>> ans;
        for(auto& [dist, pointList]:mp){
            for(auto& point: pointList){
                ans.push_back(point);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};