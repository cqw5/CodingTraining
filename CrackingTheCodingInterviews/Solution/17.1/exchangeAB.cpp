/*! Author: qwchen
 *! Date  : 2017-03-09
 *! 编程基础：17.1 无缓存交换
 *! 题目描述：
 *    请编写一个函数，函数内不使用任何临时变量，直接交换两个数的值。
 *    给定一个int数组AB，其第零个元素和第一个元素为待交换的值，请返回交换后的数组。
 */

/*
 * 思路：
 *   一个数与0异或，等于自身
 *   一个数与自身异或，就被抵消了
 */
class Exchange {
public:
    vector<int> exchangeAB(vector<int> AB) {
    	AB[0] = AB[0] ^ AB[1];
        AB[1] = AB[0] ^ AB[1];
        AB[0] = AB[0] ^ AB[1];
        return AB;
    }
};

/*
 * 思路：
 *   类似互逆运算可以利用 加减 乘除等实现，但是应该考虑两数的和、积超出int取值范围情况，乘除法应该考虑0的情况。
 */
class Exchange {
public:
    vector<int> exchangeAB(vector<int> AB) {
    	AB[0] = AB[0] + AB[1];
        AB[1] = AB[0] - AB[1];
        AB[0] = AB[0] - AB[1];
        return AB;
    }
};