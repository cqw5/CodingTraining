/*! Source: https://leetcode.com/problems/sort-characters-by-frequency
 *! Author: qwchen
 *! Date  : 2017-04-01
 *  按频数排序字符串
 */

/*
 * 思路：
 *   先构建hash表，统计每个元素出现的次数；
 *   然后，根据元素出现的次数，来构建大顶堆，把hash表中值大于1的元素及其对应的值（打包成pair）放入大顶堆
 *   不断从大顶堆中取出出现次数最多的元素，并重复该元素出现的次数
 * 时间复杂度：O(n)：beats 91.48% of cpp submissions
 * 空间复杂度：O(n)
 */
class Solution {
public:
    string frequencySort(string s) {
        string res;
        // 构建hashTable，统计每个元素的出现的次数
        vector<int> hashTable(256, 0);
        for (int i = 0; i < s.size(); i++) {
            hashTable[s[i]]++;
        }
        // 根据元素出现的次数，构建大顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&comp)> heap(&comp);
        for (int i = 0; i < 256; i++) {
            if (hashTable[i] != 0) {
                heap.push(make_pair(i, hashTable[i]));
            }
        }
        // 不断从大顶堆中取出出现次数最多的元素，并重复该元素出现的次数
        while (!heap.empty()) {
            pair<int, int> ele = heap.top();
            string subStr(ele.second, ele.first);
            res += subStr;
            heap.pop();
        }
        return res;
    }

private:
    // 自定义比较函数
    static bool comp(pair<int, int> pair1, pair<int, int> pair2) {
        return pair1.second < pair2.second;
    } 
};


/*
 * 思路：
 *   这是一个排序问题，只是排序时对比的不是元素的大小，而是元素出现的次数。因此只需要自定义排序时的比较函数。
 *   由于在类中定义比较函数时需要用static，这样没法使用到成员函数生成的hashTable，因此使用lambda表示来定义比较函数。
 * 时间复杂度：O(nlogn)：beats 14.55% of cpp submissions.
 * 空间复杂度：O(logn) ：快速排序的递归栈
 */
class Solution {
public:
    string frequencySort(string s) {
        vector<int> hashTable(256, 0);
        for (int i = 0; i < s.size(); i++) {
            hashTable[s[i]]++;
        }
        sort(s.begin(), s.end(), [&](char a, char b){
            return hashTable[a] > hashTable[b] || (hashTable[a] == hashTable[b] && a < b);
        });
        return s;
    }
};

