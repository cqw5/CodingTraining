/*! Source: https://leetcode.com/problems/reverse-integer/
 *! Author: qwchen
 *! Date  : 2016-12-21
 *  求数组中所有可能构成和为0的数
 */

/*
 * 思路：
 *   这是一个无序的数组，可以先对数据进行排序，时间复杂度为O(nlogn)
 *   从数组的第一个数开始，对于第i个数，寻找nums[i+1: n]中所有两数之和为0-nums[i]的数，和nums[i]就构成和为0的3个数。
 *   剩下的问题就是2sum问题，既然数组本身有序了，就使用夹逼法。
 *   主要结果是不重复的，因此对于相同的元素，直接就跳过。
 * 时间复杂度：O(n^2)
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        if (len < 3) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
            int target = 0 - nums[i];
            int front = i + 1;
            int back = len - 1;
            while (front < back) {
                int sum = nums[front] + nums[back];
                if (sum < target) {
                    front++;
                }
                else if (sum > target) {
                    back--;
                }
                else {
                    vector<int> temp(3, 0);
                    temp[0] = nums[i];
                    temp[1] = nums[front];
                    temp[2] = nums[back];
                    result.push_back(temp);
                    while (front < back && nums[front] == temp[1]) front++;
                    while (front < back && nums[back] == temp[2])  back--;
                }
            }
            while (i + 1 < len && nums[i] == nums[i+1]) i++;
        }
        return result;
    }
};

/**
 * 求有多少对3个数之和等于sum，不去重
 * 如，[1,1,2,2,3,3],sum=6,则count=6
 */
int threeSumHaveRepeat(vector<int>& nums, int sum) {
    int count = 0;
    if(nums.size() < 3) return count;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size()-2; i++) {
        int target = sum - nums[i];
        int low = i+1;
        int high = nums.size() - 1;
        while(low < high) {
            int curSum = nums[low] + nums[high];
            if(curSum < target) low++;
            else if(curSum > target) high--;
            else {
                if(nums[low] == nums[high]) {
                    count += (high - low + 1) * (high - low) / 2;
                    break;
                }
                else {
                    int a = low;
                    int b = high;
                    while(nums[low] == nums[a]) low++;
                    while(nums[high] == nums[b]) high--;
                    count += (low - a) * (b - high);
                }
            }
        }
    }
}

/**
 * 求有多少对3个数之和等于sum，不去重
 * 如，[1,1,2,2,3,3],sum=6,则count=1
 */
int threeSumUnRepeat(vector<int>& nums, int sum) {
    int count = 0;
    if(nums.size() < 3) return count;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 2; i++) {
        int target = sum - nums[i];
        int low = i + 1;
        int high = nums.size() - 1;
        while(low < high) {
            int curSum = nums[low] +  nums[high];
            if(curSum < target) low++;
            else if(curSum > target) high--;
            else {
                if(nums[low] == nums[high]) {
                    count++;
                    break;
                }
                else {
                    int a = low;
                    int b = high;
                    while(nums[low] == nums[a]) low++;
                    while(nums[high] == nums[b]) high--;
                    count++;
                }
            }
        }
        while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;
    }
    return count;
}

