#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
 typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<TreeNode*> genSubTrees(int l,int r) {
        vector<TreeNode *> subTrees;
        if(l>r)
            subTrees.push_back(nullptr);
        for (int k = l; k <= r;k++){//k作为root节点时
            vector<TreeNode *> left = genSubTrees(l, k - 1);
            vector<TreeNode *> right = genSubTrees(k + 1, r);
            for (int i = 0; i < left.size();i++){
                for (int j = 0; j < right.size();j++){
                    //new root Node
                    TreeNode *root = new TreeNode(k);
                    //for k as root, combine each possible case of node in  left
                    //and node in right as subtree's root node,
                    // and put it in subTree list(subTrees)
                    root->left = left[i];
                    root->right = right[j];
                    subTrees.push_back(root);
                }
            }
        }
        return subTrees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return vector<TreeNode *>(0);
        return genSubTrees(1, n);
    }
};

int main(){
    vector<int> dp(5);
    return 0;
}