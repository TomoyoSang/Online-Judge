/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> my_ans(2, -1);
        int left = 0, right = nums.size() - 1;
        while (left <= right) 
        {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) {
                my_ans[0] = mid;
                right = mid - 1;
            } 
            else if (nums[mid] > target) 
            {
                right = mid - 1;
            } 
            else 
            {
                left = mid + 1;
            }
        }
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) 
            {
                my_ans[1] = mid;
                left = mid + 1;
            }
             else if (nums[mid] > target) 
             {
                right = mid - 1;
            } 
            else 
            {
                left = mid + 1;
            }
        }
        return my_ans;
    }
};

