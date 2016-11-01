/*! Source: https://leetcode.com/problems/4sum/
 *! Author: qwchen
 *! Date  : 2016-11-01
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;


/* [Time Limit Exceeded]
 * 用一个unordered_map缓存所有的两数之和，key是两数之和，value是一个set，不重复的保存和为该key的数对pair。(O(n^2))
 * 将问题转化为两个数之和的问题。由001题的方法，可以求两个数之和时间复杂度可以降到O(n)。
 * 但是，当出现所有的两个数之和等于同一个数，而target又等于这个数的两倍时，时间复杂度为O(n^3)
 * 时间复杂度：平均情况：O(n^2)，最坏情况：O(n^3)
 * 空间复杂度：O(n^2)
 * 不过测试用例可能出现有O(n^3)的测试，结果超时。
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int, set<pair<int, int>>> mapping; // 用于缓存所有两数之和，key是两数之和，value是一个set，不重复的保存和为该key的数对pair。
        set<vector<int>> value_set;
        vector<int> vec;
        int numSize = nums.size();
        for (int i = 0; i < numSize; i++){
            for (int j = i+1; j < numSize; j++){
                mapping[nums[i] + nums[j]].insert(make_pair(i, j));  // 都是 i < j
            }
        }
        for(auto it = mapping.begin(); it != mapping.end(); it++){
            int gap = target - it->first;
            if(it->first <= gap && mapping.find(gap) != mapping.end()){ // 为了避免重复，只需要比较it->first <= gap
                for (auto left: mapping[it->first]){
                    for (auto right: mapping[gap]){
                        set<int> unique = {left.first, left.second, right.first, right.second}; // 去重
                        if (unique.size() == 4){ // =4说明没有重复元素
                            vec = {nums[left.first], nums[left.second], nums[right.first], nums[right.second]};
                            sort(vec.begin(), vec.end()); // 结果集合内要求排序
                            value_set.insert(vec);
                        }
                    }
                }
            }
        }
        vector<vector<int>> result;
        for (auto i: value_set){
            result.push_back(i);
        }
        return result;
    }
};


/* [Runtim beats 93.29% of cpp submissions]
 * 有点类似暴力解法，思路简单，不过多加了一些规则(即考虑特殊情况)，而且在最后求两个数之和时，由于本身已经排好序，因此用左右夹逼法。
 * 此时求两个数之和的时间复杂度降到O(n)，此O(n)前面的系数要比在数据未排序情况下用的hash方法小很多。
 * 
 * 先对数组进行排序，这样重复元素会连在一块，而后面的数就一定比前面的数大，可以利用很多规则。
 * - 寻找4个数中的第一个，剩下的转化为3Sum问题
 * - 寻找3个数中的第一个，剩下的转化为2Sum问题
 * - 2Sum问题，由于数组本身有序，因此使用夹逼法来求解，不用hash法。
 * 规则见代码行间注释注释
 * 时间复杂度：O(n^3)，加上一些规则后，n^3前面的系数很小
 * 空间复杂度：O(1)
 */
class Solution2{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 当长度不足时，直接返回
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) 
            return result;
        sort(nums.begin(), nums.end());
        // 4个最小都大于target 或 4个最大都小于target，则一定找不到解
        int min = nums[0];
        int max = nums[n-1];
        if (4 * min > target || 4 * max < target) 
            return result;
        // 寻找第一个数，将剩下的转化为3Sum
        for (int i = 0; i < n; i++){
            // 重复元素不需要考虑
            if (i > 0 && nums[i] == nums[i-1]) 
                continue;
            // 4个最小都大于target，不用再考虑后面大的数了
            if (4 * nums[i] > target) 
                break;
            // 当前数+3个最大都小于target，不用再考虑当前这个数了
            if (nums[i] + 3 * max < target) 
                continue;
            if (4 * nums[i] == target){
                if (i + 3 < n && nums[i] == nums[i+3])
                    result.push_back({nums[i], nums[i], nums[i], nums[i]});
                break;
            }
            threeSum(nums, target - nums[i], i+1, n-1, result, nums[i]);
        }
        return result;
    }

private:
    /*
     * 3Sum
     * Parament：
     *     nums和target是原来的数
     *     low是当前4Sum中第二个元素的起点，high指向数组最后一个元素
     *     result保存结果
     *     z1是4Sum中的第一个元素
     */
    void threeSum(vector<int>& nums, int target, int low, int high, vector<vector<int>>& result, int z1){
        if (low + 1 >= high)
            return;
        int min = nums[low];
        int max = nums[high];
        if (3 * min > target || 3 * max < target)
            return;
        for(int i = low; i <= high; i++){
            if (i > low && nums[i] == nums[i-1])
                continue;
            if (3 * nums[i] > target)
                break;
            if (nums[i] + 2 * max < target)
                continue;
            if (3 * nums[i] == target)
                if (i + 2 <= high && nums[i] == nums[i+2]){
                    result.push_back({z1, nums[i], nums[i], nums[i]});
                    break;
                }
            twoSum(nums, target - nums[i], i+1, high, result, z1, nums[i]);
        }

    }

    /*
     * 2Sum
     * Parament：
     *     nums和target是原来的数
     *     low是当前4Sum中第三个元素的起点，high指向数组最后一个元素
     *     result保存结果
     *     z1是4Sum中的第一个元素，z2是4Sum中的第二个元素
     */
    void twoSum(vector<int>& nums, int target, int low, int high, vector<vector<int>>& result, int z1, int z2){
        if (low >= high)
            return;
        if (2 * nums[low] > target || 2 * nums[high] < target)
            return;
        int i = low, j = high;
        while(i < j){
            if (i > low && nums[i] == nums[i-1]){
                i++;
                continue;
            }
            if (j < high && nums[j] == nums[j+1]){
                j--;
                continue;
            }
            int sum = nums[i] + nums[j];
            if(sum == target){
                result.push_back({z1, z2, nums[i++], nums[j]});
            }
            else if(sum < target)
                i++;
            else 
                j--;
        }
    }    
};


void testSolution(){
    vector<int> s = {1, 0, -1, 0, -2, 2};
    int target = 0;
    /*
    vector<int> s = {91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,
        -64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,
        83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,
        -749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,
        -67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,
        -44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,
        93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,
        47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,
        16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,
        92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,
        -90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,
        38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,
        -49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,
        -47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245};
    int target = -236727523;
    */
    Solution solution;
    Solution2 solution2;
    vector<vector<int>> result = solution2.fourSum(s, target);
    cout << "[" << endl;
    for (int i = 0; i < result.size(); i++){
        cout << "[" << result[i][0] << ", " << result[i][1] << ", " << result[i][2] << ", " << result[i][3] << "]" << endl;
    }
    cout << "]" << endl;
}

int main(){
    testSolution();
    return 0;
}