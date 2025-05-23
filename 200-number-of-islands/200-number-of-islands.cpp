class Solution {
public:
    
    void markIsland(vector<vector<char>>& matrix,int x,int y, int r, int c){
        if(x<0 || y<0 || x>=r || y>=c || matrix[x][y]!='1') return;
        matrix[x][y]='2';
        
        markIsland(matrix,x+1,y,r,c);
        markIsland(matrix,x-1,y,r,c);
        markIsland(matrix,x,y+1,r,c);
        markIsland(matrix,x,y-1,r,c);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows==0) return 0;
        int cols = grid[0].size();
        int islands = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    markIsland(grid,i,j,rows,cols);
                    islands+=1;
                }
            }
        }
        return islands;
    }
};