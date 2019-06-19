#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> uniTree(n+1);//for 0 :empty tree,for 1: root tree
        uniTree[0]=uniTree[1]=1;
        //vector<int> subUniTree(n);
        //uniTree[i]=subUniTree[1]+...+subUniTree[i]
        //subUniTree[i]=uniTree[i-1]*uniTree[n-i];1<=i<=n;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){//where i means n, j means i for subUnitree
                uniTree[i] += uniTree[j-1] * uniTree[i-j];//calculate the  uniTree[i]
            }
        }
        return uniTree[n];
    }
};


int main(){
    Solution sol;
    //int result;
    for (int i = 1; i < 10;i++)
        cout << sol.numTrees(i)<<endl;
}
