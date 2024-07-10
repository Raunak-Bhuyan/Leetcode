class Solution {
private:
    void dfs(int row, int column, vector<vector<int>> &ans, vector<vector<int>> &image,
     int color,int delRow[], int delCol[], int initial_color){
        ans[row][column] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i=0;i<4; i++){
            int nrow = row + delRow[i];
            int ncol = column + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && image[nrow][ncol] == initial_color && ans[nrow][ncol] != color){
                    dfs(nrow, ncol, ans, image, color, delRow, delCol, initial_color);
                }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial_color = image[sr][sc];
        if(initial_color == color) return image;
        vector<vector<int>> ans = image;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,-1,0,+1};
        dfs(sr, sc, ans, image, color, delRow, delCol, initial_color);
        return ans;
    }
};