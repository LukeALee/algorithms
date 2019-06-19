#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>

using namespace std;


class NumArray {
public:
    NumArray(vector<int>& nums) {
        int sLen = nums.size();
        row=sLen,col=sLen;
        dp=vector<vector<int>>(sLen,vector<int>(sLen,0));
        for(int i=0;i<sLen;i++){
            dp[i][i]=nums[i];
        }
        for(int len=2;len<=sLen;len++){
            for(int i=0;i<sLen-len+1;i++){
                int k = i+len-1;
                dp[i][k]=dp[i+1][k]+dp[i][k-1];
            }
        } 
    }
    
    int sumRange(int i, int j) {
        if(i>row || j>col)return 0;
        else return dp[i][j];
    }
private:
    vector<vector<int>> dp;
    int row,col;
};
int main(){
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numa(nums);
    int result = numa.sumRange(0, 5);
}
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */