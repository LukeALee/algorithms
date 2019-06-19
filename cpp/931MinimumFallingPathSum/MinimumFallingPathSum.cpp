#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int size=A.size();
        if(size==1)return A[0][0];
        for(int i=0;i<size-1;i++){
            for(int j=size-1;j>=0;j--){
                if(j==0)A[i+1][j]+=min(A[i][0],A[i][1]);
                else if(j==size-1)A[i+1][j]+=min(A[i][j],A[i][j-1]);
                else A[i+1][j]+=min(min(A[i][j-1],A[i][j]),A[i][j+1]);
            }
        }
        return *min_element(A[size-1].begin(),A[size-1].end());
    }
};


int main(){
    vector<vector<int>>A={{-84,-36,2},{87,-79,10},{42,10,63}};
    Solution sol;
    int result;
    result = sol.minFallingPathSum(A);
    cout << result << endl;
}