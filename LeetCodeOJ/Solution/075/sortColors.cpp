/*
 * 思路：箱子排序
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        queue<int> bin[3];
        for (int i = 0; i < nums.size(); i++) {
            bin[nums[i]].push(nums[i]);
        }
        int i = 0;
        for (int j = 0; j < 3; j++) {
            while(!bin[j].empty()) {
                nums[i++] = bin[j].front();
                bin[j].pop();
            }
        }
    }
};

/*
 * 思路：三向切分快速排序
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int lt = 0,
            mid = 0,
            gt = nums.size() - 1;
        while (mid <= gt) {
            if (nums[mid] < 1)      swap(nums[lt++], nums[mid++]);
            else if (nums[mid] > 1) swap(nums[gt--], nums[mid]);
            else                    mid++;
        }
    }
};