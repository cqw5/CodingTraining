/*! Author: qwchen
 *! Date  : 2017-02-24
 *! 查找与排序：11.2 变位词排序
 *! 题目描述：
 *    请编写一个方法，对一个字符串数组进行排序，将所有变位词合并，保留其字典序最小的一个串。
 *    这里的变位词指变换其字母顺序所构成的新的词或短语。例如"triangle"和"integral"就是变位词。
 *    给定一个string的数组str和数组大小int n，请返回排序合并后的数组。保证字符串串长小于等于20，数组大小小于等于300。
 */


/*
 * 思路：
 *   属于一个map，key存放变分词的字典排序，value存放所有的变分词
 *   之后，对每一个key，找到其所有变分词中最小的那个就可以了
 *   将最后的结果排序
 * 时间复杂度：O(n)+O(n)+O(mlogm) 
 * 空间复杂度：O(n)
 */
class SortString {
public:
    vector<string> sortStrings(vector<string> str, int n) {
        vector<string> res;
        map<string, vector<string>> mapping;
        for (int i = 0; i < n; i++) {
            string copyStr(str[i]);
            sort(copyStr.begin(), copyStr.end());
            mapping[copyStr].push_back(str[i]);
        }
        for (auto it = mapping.begin(); it != mapping.end(); it++) {
            vector<string> temp = it->second;
            res.push_back(*min_element(temp.begin(), temp.end()));
        }
        sort(res.begin(), res.end());
        return res;
    }
};


/*
 * 思路：
 *   相对数组进行排序，因为最终也要对结果进行排序，此处排序后，原始元素的顺序也就和结果数组一致了，剩下的操作就上删除重复的变分词
 *   用一个set来存放变分词排序后的结果
 *   对于一个词，如果其排序后不在set中，就加入set和结果数组；否则都不加入
 * 时间复杂度：O(nlogn)+O(n) 
 * 空间复杂度：O(m)
 */
class SortString {
public:
    vector<string> sortStrings(vector<string> str, int n) {
        vector<string> res;
        set<string> set;
        sort(str.begin(), str.end());
        for (int i = 0; i < n; i++) {
            string temp(str[i]);
            sort(temp.begin(), temp.end());
            if (set.find(temp) == set.end()) {
                set.insert(temp);
                res.push_back(str[i]);
            }
        }
        return res;
    }
};

