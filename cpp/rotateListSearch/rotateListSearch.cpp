#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()<1)return -1;
        int rotatePos=0;
        int begin=0,end=nums.size()-1,mid=(begin+end)/2;
        while(begin<=end){
            if(nums[mid]>=nums[0])begin=mid+1;
            if(nums[mid]<nums[0]){
                if(mid>=1){
                    if(nums[mid-1]>=nums[0]){
                        rotatePos=mid;
                        break;
                    }
                    else{
                        end=mid-1;
                    }
                }
            }
            mid=(begin+end)/2;
        }
        vector<int>::iterator front,back,iter=nums.begin();
        if( (! binary_search(iter,iter+mid,target)) && (! binary_search(iter+mid,nums.end(),target)) )return -1;
        front =lower_bound(iter,iter+mid,target);
        back =lower_bound(iter+mid,nums.end(),target);
        if(*front==target)return distance(iter,front);
        return distance(iter,back);
    }
};

int main(){
    vector<int> nums1 = {3,1};
    Solution sol;
    int result;
    result = sol.search(nums1, 0);
}