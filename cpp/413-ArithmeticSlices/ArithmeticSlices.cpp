#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class Solution2 {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3)
            return 0;
        vector<int> dp(A.size(),0);
        for(int i=2;i<A.size();i++)
            if(A[i]-A[i-1]==A[i-1]-A[i-2])
                dp[i]=dp[i-1]+1;
        int res=0;
        for(auto count:dp)
            res+=count;
        return res;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        //双指针动态规划
        int sLen = A.size();
        int result = 0;
        if(sLen<3)return result;
        vector<int> dp(sLen,0);
        dp[2]=1;//长度为3的数组只可能有一个等差子数组
        for(int i=3;i<sLen;i++){//长度为n的等差数组的子数组数量是固定的
            dp[i]=dp[i-1]+(i-1);
        }
        int i=0,j=i+2;
        while(j<sLen){
            while(i<sLen-2  && (A[i+1]-A[i] !=A[i+2]-A[i+1])){
                //寻找从i开始第一个等差子数组出现的位置
                i++;
                j++;
            }
            if(i<sLen-2){
                int subArrLen=3;
                int dis=A[i+1]-A[i];
                j+=1;
                while(j<sLen && A[j]-A[j-1]==dis){
                    j++;
                    subArrLen++;
                }
                result+=dp[subArrLen-1];
            }
            i=j;
            j=i+2;            
        }
        return result;
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    Solution2 sol;
    int result;
    result = sol.numberOfArithmeticSlices(nums);
    cout << result << endl;
}