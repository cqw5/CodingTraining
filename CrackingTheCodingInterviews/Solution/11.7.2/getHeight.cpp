/*! Author: qwchen
 *! Date  : 2017-02-25
 *! 查找与排序：11.7.2 叠罗汉II
 *! 题目描述：
 *    叠罗汉是一个著名的游戏，游戏中一个人要站在另一个人的肩膀上。
 *    为了使叠成的罗汉更稳固，我们应该让上面的人比下面的人更轻一点。
 *    现在一个马戏团要表演这个节目，为了视觉效果，我们还要求下面的人的身高比上面的人高。
 *    请编写一个算法，计算最多能叠多少人，注意这里所有演员都同时出现。
 *    给定一个二维int的数组actors，每个元素有两个值，分别代表一个演员的身高和体重。同时给定演员总数n，请返回最多能叠的人数。
 *    保证总人数小于等于500。
 */

/*
 * 思路：
 *   这个叠罗汉问题有两个受限条件，身高和体重，先将所有罗汉安装身高或者体重排序，那么剩下的问题就转化成前面叠罗汉I的问题了。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n)
 */
class Stack {
public:
    int getHeight(vector<vector<int> > actors, int n) {
        int res = 0;
        if (n <= 0) return res;
        // 使用冒泡排序，按照一个限制条件从小到大排序
        for (int i = n; i > 1; i--) {
            for (int j = 0; j < i - 1; j++) {
                if (actors[j][0] > actors[j + 1][0]) {
                    swap(actors[j], actors[j + 1]);
                }
            }
        }
        vector<int> num(n, 1);
        for (int i = 1; i < n; i++) {
            int maxNum = 0;
            for (int j = 0; j < i; j++) {
                if (actors[j][1] < actors[i][1]) {
                    maxNum = max(maxNum, num[j]);
                }
            }
            num[i] = maxNum + 1;
            res = max(res, num[i]);
        }
        return res;
    }
};



// 与上面的解放一致，只是调用库函数来完成排序过程
class Stack {
public:
    int getHeight(vector<vector<int> > actors, int n) {
        int res = 0;
        if (n <= 0) return res;
        sort(actors.begin(), actors.end(), comp);
        vector<int> num(n, 1);
        for (int i = 1; i < n; i++) {
            int maxNum = 0;
            for (int j = 0; j < i; j++) {
                if (actors[j][1] < actors[i][1]) {
                    maxNum = max(maxNum, num[j]);
                }
            }
            num[i] = maxNum + 1;
            res = max(res, num[i]);
        }
        return res;
    }
    
    static bool comp(vector<int> a, vector<int> b) {  // 自定义比较函数若作为类的成员函数，必须是静态的
        return a[0] < b[0];
    }
};

