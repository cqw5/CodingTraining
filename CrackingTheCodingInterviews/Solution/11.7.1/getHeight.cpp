/*! Author: qwchen
 *! Date  : 2017-02-25
 *! 查找与排序：11.7.1 叠罗汉I
 *! 题目描述：
 *    叠罗汉是一个著名的游戏，游戏中一个人要站在另一个人的肩膀上。同时我们应该让下面的人比上面的人更高一点。
 *    已知参加游戏的每个人的身高，请编写代码计算通过选择参与游戏的人，我们多能叠多少个人。
 *    注意这里的人都是先后到的，意味着参加游戏的人的先后顺序与原序列中的顺序应该一致。
 *    给定一个int数组men，代表依次来的每个人的身高。同时给定总人数n，请返回最多能叠的人数。保证n小于等于500。
 *    注意：在这个叠罗汉问题中，是前面的人只能站在后面的人上面，与前面堆箱子的问题正好相反。
 */

/*
 * 思路：
 *   动态规划，与前面的堆箱子问题相似
 *   用一个数组num来存放每一个人到来时，其跟前面的人所能叠成罗汉的最多人数
 *   每一个人i到来时，遍历比其先到来的每一个人0~i-1，如果对方j满足与其叠成罗汉的要求（即对方的身高比起小,men[j]<men[i]），
 *   就计算与其叠成罗汉后的人数maxNum，找到能叠成人数最多的那个num[i]=max(maxNum, num[j])
 *   最终res=max_element(num)
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n)
 */
class Stack {
public:
    int getHeight(vector<int> men, int n) {
        int res = 0;
        if (n <= 0) return res;
        vector<int> num(n, 1);
        for (int i = 1; i < n; i++) {
            int maxNum = 0;
            for (int j = 0; j < i; j++) {
                if (men[j] < men[i]) {
                    maxNum = max(maxNum, num[j]);
                }
            }
            num[i] = maxNum + 1;
            res = max(res, num[i]);
        }
        return res;
    }
};

