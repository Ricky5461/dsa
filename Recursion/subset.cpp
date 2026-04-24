#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void func(int i,int len,vector<int>& nums,vector<vector<int>>&res,vector<int>&ans){
        if(i==len){
            res.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        func(i+1,len,nums,res,ans);
        ans.pop_back();
        func(i+1,len,nums,res,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ans;
        int len=nums.size();
        func(0,len,nums,res,ans);
        return res;
    }
};

int  main(){
    vector<int>nums = {1,2,3};
    Solution s;
    s.subsets(nums);
    return 0;
}