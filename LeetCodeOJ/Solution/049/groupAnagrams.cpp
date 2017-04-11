/*! Source: https://leetcode.com/problems/anagrams
 *! Author: qwchen
 *! Date: 2017-04-12
 *  回文分组
 *  For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 *  Return: [["ate", "eat","tea"],
 *           ["nat","tan"],
 *           ["bat"]]
 */

/*
 * 思路：
 *   建一个hash表，key为元素的排序后的值，value为所有排序后值为该key的元素组成的数组。
 * 时间复杂度：O(n). 49 ms. beats 27.17% of cpp submissions.
 * 空间复杂度：O(n)
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hashTable;
        for (auto str: strs) {
            string str2(str);  // 要重新复制，不要改变原始元素的值
            sort(str2.begin(), str2.end());
            hashTable[str2].push_back(str);
        }
        for (auto it = hashTable.begin(); it != hashTable.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};

