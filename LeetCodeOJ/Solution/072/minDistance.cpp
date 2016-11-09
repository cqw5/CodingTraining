/*! Source: https://leetcode.com/problems/edit-distance/
 *! Author: qwchen
 *! Date  : 2016-11-09
 * Solution 为该文件最优的方案
 * test数据只用于测试是否语法错误，完整的测试见LeetCode。
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/*
 * 动态规划 + 滚动数组
 * 用一维数组distance[i]滚动保存中间状态，用一个变量upper_left记录distance[i-1][j-1]
 * 递归方程：
 *     distance(i,j) = | min(distance(i-1,j)+1, distance(i,j-1)+1, distance(i-1, j-1))      word1[i-1] == word[j-1]
 *                     | min(distance(i-1,j)+1, distance(i,j-1)+1, distance(i-1, j-1)+1)    word1[i-1] != word[j-1]
 * 迭代求解distance数组
 * 最终distance[word2.size()]就是要求的解
 * 时间复杂度：O(m*n)
 * 空间复杂度：O(n) if m > n; O(m) if m < n
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int numWord1 = word1.size();
        int numWord2 = word2.size();
        if (numWord1 == 0) return numWord2;
        if (numWord2 == 0) return numWord1;
        if (numWord1 < numWord2) return minDistance(word2, word1); // 选择word1和word2中小的长度作为保存中间状态的数组的长度
        vector<int> distance;
        for (int i = 0; i <= numWord2; i++){
            distance.push_back(i);
        }
        int upper_left = 0;
        for (int i = 1; i <= numWord1; i++){
            upper_left = distance[0];
            distance[0] = i;
            for (int j = 1; j <= numWord2; j++){
                int dist = min(distance[j], distance[j-1]) + 1;
                if (word1[i-1] == word2[j-1]) dist = min(dist, upper_left);
                else                          dist = min(dist, upper_left + 1);
                upper_left = distance[j];
                distance[j] = dist;
            }
        }
        return distance[numWord2];
    }
};

/*
 * 动态规划
 * 用二维数组distance[i][j]保存中间状态
 * 递归方程：
 *     distance(i,j) = | min(distance(i-1,j)+1, distance(i,j-1)+1, distance(i-1, j-1))      word1[i-1] == word[j-1]
 *                     | min(distance(i-1,j)+1, distance(i,j-1)+1, distance(i-1, j-1)+1)    word1[i-1] != word[j-1]
 * 迭代求解distance数组
 * 最终distance[word1.size()][word2.size()]就是要求的解
 * 时间复杂度：O(n*m)
 * 空间复杂度：O(n*m)
 */
class Solution1 {
public:
    int minDistance(string word1, string word2) {
        int numWord1 = word1.size();
        int numWord2 = word2.size();
        if (numWord1 == 0) return numWord2;
        if (numWord2 == 0) return numWord1;
        vector<vector<int>> distance;
        vector<int> dist0;
        for (int i = 0; i <= numWord2; i++){
            dist0.push_back(i);
        }
        distance.push_back(dist0);
        for (int i = 1; i <= numWord1; i++){
            vector<int> disti = {i};
            for (int j = 1; j <= numWord2; j++){
                int dist = min(disti[j-1], distance[i-1][j]) + 1;
                if (word1[i-1] == word2[j-1]){
                    dist = min(dist, distance[i-1][j-1]);       
                } else {
                    dist = min(dist, distance[i-1][j-1] + 1);
                }
                disti.push_back(dist);
            }
            distance.push_back(disti);
        }
        return distance[numWord1][numWord2];
    }
};


void testSolution(){
	string word1 = "oslo";
	string word2 = "snow";
	Solution sol;
	cout << sol.minDistance(word1, word2) << endl;
	Solution1 sol1;
	cout << sol1.minDistance(word1, word2) << endl;
}

int main(){
	testSolution();
	return 0;
}
