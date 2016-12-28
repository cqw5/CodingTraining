/*! Author: qwchen
 *! Date  : 2016-12-28
 *! 字符串与数组: 1.1 
 *! 题目描述:
 *    请实现一个算法，确定一个字符串的所有字符是否全都不同。这里我们要求不允许使用额外的存储结构。
 *    给定一个string iniString，请返回一个bool值,True代表所有字符全都不同，False代表存在相同的字符。
 *    保证字符串中的字符为ASCII字符。字符串的长度小于等于3000。
 *  Solution为该文件下最优解决方案
 */

/*
 * 思路：
 *   考虑到字符串是ASCII码，因此hash表只需要是长度为256的bool数组(默认值为false)
 *   遍历字符串，将hash表中当前字符对应的元素设置为true，如果该元素本身就是true，说明是第二次遇到该元素了，则字符串中有重复元素，返回false
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    bool checkDifferent(string iniString) {
        if (iniString.size() > 256) return false; // 注意，如果字符串长度大于256，肯定有重复元素
        bool hashTable[256] = {false};
        for (int i = 0; i < iniString.size(); i++) {
            if (hashTable[iniString[i]]) return false;
            else                         hashTable[iniString[i]] = true;
        }
        return true;
    }
};

/* 
 * 思路：
 *   先对字符串进行排序，对于有序的字符串，相同的元素会相邻，因此只需要判断相邻元素是否相同
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(logn)，排序时的空间复杂度
 */
class Solution2 {
public:
    bool checkDifferent(string iniString) {
        if (iniString.size() > 256) return false;
        sort(iniString.begin(), iniString.end());
        for (int i = 0; i < iniString.size() - 1; i++) {
            if (iniString[i] == iniString[i+1]) return false;
        }
        return true;
    }
};

