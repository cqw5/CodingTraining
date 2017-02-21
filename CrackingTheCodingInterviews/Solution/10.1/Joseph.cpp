/*! Author: qwchen
 *! Date  : 2017-02-21
 *! 链表：10.1 约瑟夫问题I
 *! 题目描述：
 *    约瑟夫问题是一个非常著名的趣题，即由n个人坐成一圈，按顺时针由1开始给他们编号。然后由第一个人开始报数，数到m的人出局。
 *    现在需要求的是最后一个出局的人的编号。
 *    给定两个int n和m，代表游戏的人数。请返回最后一个出局的人的编号。保证n和m小于等于1000。
 */


/*
 * 思路：
 *   模拟这个游戏的过程。
 *   用一个数组表示这n个人，每次从中删除被选中的那个，最终剩下的元素就是了。
 * 时间复杂度：O(n*m)
 * 空间复杂度：O(n)
 */
class Joseph {
public:
    int getResult(int n, int m) {
        if (n <= 0 || m <= 0) return 0;
        vector<int> circle(n, 0);
        for (int i = 0; i < n; i++) {
            circle[i] = i + 1;
        }
        int cur = 0;
        while (n > 1) {
            cur = (cur + m - 1) % n;
            deleteElem(circle, cur, n);
            n--;
        }
        return circle[0];
    }
    
    void deleteElem(vector<int> &circle, int index, int n) {
        for (int i = index; i < n - 1; i++) {
            circle[i] = circle[i + 1];
        }
    }
};

