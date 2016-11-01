/*! Source: https://leetcode.com/problems/two-sum/
 *! Author: qwchen
 *! Date  : 2016-10-30
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* 
 * 解法一：
 *     用一个hash表，以数组的值作为key，数组的下标作为value。
 *     先用hash表保存所有的元素；然后对于每个元素，从hash表中查找是否存在另外一个元素。
 *     但是这种方法如果是target等于两个相同的数之和，就会出问题。因此后面补一个暴力解法防止这种问题，一般情况下都不会执行到这一步。
 * 时间复杂度：平均：O(n)，最坏O(n^2)
 * 空间复杂度：O(n)
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        unordered_map<int, int> mapping;
        // 从后往前，使得如果有两个值相同，以排在前面的值的下标为准
        for (int i = nums.size() - 1; i >= 0; i--){
            mapping[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++){
            int gap = target - nums[i];
            if(mapping.find(gap) != mapping.end() && mapping[gap] != i){
                indices.push_back(i);
                indices.push_back(mapping[gap]);
                return indices;
            }
        }
        // 如果是target等于两个相同的数，上面的方法是无法求出来的，使用下面的暴力解法求解
        for (int i = 0; i < nums.size(); i++){
            for (int j = i+1; j < nums.size(); i++){
                if (nums[i] + nums[j] == target){
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }
        return indices;
    }
};

/*
 * 解法二：
 *     用一个hash表，以数组的值作为key，数组的下标作为value。
 *     与解法一不同，解法一是对数组进行两次遍历：一次构建hash表；一次对于每个元素，从hash表中寻找是否存在与其和等于target的值
 *     解法二只需要遍历数组一次；对于每一个元素，其前面的元素都已经存在hash表中；对于当前元素，如果能从hash找到与其和等于target的值，
 *     则将hash表中的元素及当前元素下标返回，否则将当前元素放到hash表中。
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        unordered_map<int, int> mapping;
        for (int i = 0; i < nums.size(); i++){
            int gap = target - nums[i];
            if (mapping.find(gap) != mapping.end()){
                indices.push_back(mapping[gap]);
                indices.push_back(i);
                break;
            }
            mapping[nums[i]] = i; 
        }
        return indices;
    }
};

void testSolution() {
    vector<int> nums = {3, 2, 4};
    vector<int> indices;
    
    Solution s;
    indices = s.twoSum(nums, 6);
    for (int i : indices){
        cout << i << " ";
    }
    cout << endl;

    Solution s2;
    indices = s2.twoSum(nums, 6);
    for (int i : indices){
        cout << i << " ";
    }
    cout << endl; 
}

int main(){
    testSolution();
    return 0;
}