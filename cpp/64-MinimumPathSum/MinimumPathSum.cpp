#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()<1)return 0;
        int row=grid.size(),col=grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));
        dp[0][0]=grid[0][0];
        int i=0,j=0;
        for(int i=1;i<row;i++)dp[i][j]=dp[i-1][j]+grid[i][j];
        i=0;
        for(j=1;j<col;j++)dp[i][j]=dp[i][j-1]+grid[i][j];
        for(i=1;i<row;i++){
            for(j=1;j<col;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[row-1][col-1];
    }
};


int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    Solution sol;
    int result;
    result = sol.minPathSum(grid);
    cout << result;
}