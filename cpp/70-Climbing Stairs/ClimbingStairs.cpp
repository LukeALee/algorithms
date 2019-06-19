#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    vector<int> methods={1,2};
public:
    int climbStairs(int n) {
        if(n<=2)return n;
        if(methods.size()<n){
            for(int i=2;i<n;i++){
                methods.push_back(methods[i-1]+methods[i-2]);
            }
        }
        return methods[n-1];
    }
};


int main(){
    int n = 10;
    Solution sol;
    int result;
    result = sol.climbStairs(n);
    cout << result;
}