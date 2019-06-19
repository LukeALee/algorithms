#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<list>
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        std::map<std::pair<int, int>, vector<TreeNode*>> mem;
        return _generateTrees(1, n, mem);
    }
private:
    vector<TreeNode*> _generateTrees(int left, int right,
    std::map<std::pair<int, int>, vector<TreeNode*>>& mem)
    {
        std::vector<TreeNode*> result;
        if(left > right)
        {
            result.push_back(NULL);
            return result;
        }
        
        if(mem.find(std::make_pair(left,right)) != mem.end())
        {
             return mem[make_pair(left, right)];
         }

        for(int k = left; k <= right; k++)
        {
            auto leftNodes = _generateTrees(left, k-1, mem);
            auto rightNodes = _generateTrees(k+1, right, mem);
            for(auto leftnode : leftNodes)
                for(auto rightnode : rightNodes)
                {
                    TreeNode* root = new TreeNode(k);
                    root->left = leftnode;
                    root->right = rightnode;
                    result.push_back(root);
                }
        }
        mem[make_pair(left,right)] = result;
        return result;
    }

};
