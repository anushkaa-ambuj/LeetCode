class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(i, j, visited, grid);
                }
            }
        }
        return count;
    }

private:
    void dfs(int i, int j, vector<vector<int>>& visited, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if(i<0 || i>=n || j<0 || j>=m || visited[i][j] || grid[i][j]=='0'){
            return;
        }

        visited[i][j] = 1;

        dfs(i, j+1, visited, grid);
        dfs(i+1, j, visited, grid); 
        dfs(i, j-1, visited, grid);
        dfs(i-1, j, visited, grid);
    }
};