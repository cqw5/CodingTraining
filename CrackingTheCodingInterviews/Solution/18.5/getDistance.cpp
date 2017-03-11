/*! Author: qwchen
 *! Date  : 2017-03-11
 *! 字符串 18.5 单词最近距离
 *! 题目描述：
 *    有一篇文章内含多个单词，现给定两个单词，请设计一个高效算法，找出文中这两个单词的最短距离
 *    (即最少相隔的单词数,也就是两个单词在文章中位置的差的绝对值)。
 *    给定一个string数组article，代表所给文章，同时给定文章的单词数n和待查找的两个单词x和y。请返回两个单词的最短距离。
 *    保证两个单词均在文中出现且不相同，同时保证文章单词数小于等于1000。
 */

/*
 * 思路：
 *   让i指向x，j指向y，并计算|i-j|，更新最小距离
 *   交替移动i和j，计算|i-j|，更新最小距离
 *   如果i<j，移动i；如果j<i，移动j
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Distance {
public:
    int getDistance(vector<string> article, int n, string x, string y) {
        int dist = INT_MAX;
        int i = 0, j = 0;
        while (article[i] != x) {
            i++;
        }
        while (article[j] != y) {
            j++;
        }
        while (true) {
            dist = min(dist, abs(i - j));
            if (i < j) {
                i++;
                while (i < n && article[i] != x) {
                    i++;
                }
                if (i == n) {
                    break;
                }
            }
            else {
                j++;
                while (j < n && article[j] != y) {
                    j++;
                }
                if (j == n) {
                    break;
                }
            }
        }
        return dist;
    }
};

/*
 * 思路：
 *   让lastx指向x，lasty指向y，初始化为-1
 *   遍历文章中每个字符串：
 *     如果当前字符串为x，更新lastx的位置，计算lastx-lasty，若结果小于dist，更新dist
 *     如果当前字符串为y，更新lasty的位置，计算lasty-lastx，若结果小于dist，更新dist
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Distance {
public:
    int getDistance(vector<string> article, int n, string x, string y) {
        int dist = INT_MAX;
        int lastx = -1, lasty = -1;
        for (int i = 0; i < n; i++) {
            if (article[i] == x) {
                lastx = i;
                if (lasty >= 0) {
                    dist = min(lastx-lasty, dist);
                } 
            }
            else if (article[i] == y) {
                lasty = i;
                if (lastx >= 0) {
                    dist = min(lasty - lastx, dist);
                }
            }
        }
        return dist;
    }
};

