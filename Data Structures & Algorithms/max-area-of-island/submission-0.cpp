class Solution {
public:

    int dfs(vector<vector<int>>& grid, int row, int col){
        if(row<0 || row>=grid.size() 
        || col<0 || col>=grid[0].size() 
        || grid[row][col]==0){
            return 0;
        }

        grid[row][col] =0;

        int area = 1;

        area += dfs(grid,row-1,col);
        area += dfs(grid,row+1,col);
        area += dfs(grid,row,col-1);
        area += dfs(grid,row,col+1);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid,i,j);
                    maxarea = max(area,maxarea);
                }
            }
        }
        return maxarea;
    }
};
