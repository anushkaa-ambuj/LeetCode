class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        int count = 0;

        for (int i=0; i<n;i++){
            for (int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return count;
    }

private:
    void bfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>>& grid){
        visited[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            // traverse neighbours & mark them if its land
            vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // up, down, left, right
            for (auto [dx, dy] : directions) {
                int nrow = i + dx;
                int ncol = j + dy;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
};