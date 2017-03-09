/*! Author: qwchen
 *! Date  : 2017-03-09
 *! 编程基础：17.9 词频统计
 *! 题目描述：
 *    请设计一个高效的方法，找出任意指定单词在一篇文章中的出现频数。
 *    给定一个string数组article和数组大小n及一个待统计单词word，请返回该单词在文章中的出现频数。保证文章的词数小于等于1000。
 */

/* 
 * 思路：
 *   用一个hash表统计每个词出现的次数
 */
class Frequency {
public:
    int getFrequency(vector<string> article, int n, string word) {
        if (n <= 0) return 0;
        map<string, int> mapping;
        for (int i = 0; i < n; i++) {
            mapping[article[i]]++;
        }
        return mapping[word];
    }
};

/*
 * 思路：
 *   直接变量字符串数组，统计word出现的次数
 */
class Frequency {
public:
    int getFrequency(vector<string> article, int n, string word) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (article[i] == word) {
                count++;
            }
        }
        return count;
    }
};

