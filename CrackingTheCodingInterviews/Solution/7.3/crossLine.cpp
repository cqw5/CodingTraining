/*! Author: qwchen
 *! Date  : 2017-02-15
 *! 计算几何: 7.3 判断直线相交
 *！题目描述：
 *    给定直角坐标系上的两条直线，确定这两条直线会不会相交。
 *    线段以斜率和截距的形式给出，即double s1，double s2，double y1，double y2，分别代表直线1和2的斜率(即s1,s2)和截距(即y1,y2)，
 *    请返回一个bool，代表给定的两条直线是否相交。这里两直线重合也认为相交。
 */


/*
 * 思路：
 *   当两个直线不平行，或者平行但重合时，两个直线有交点
 */
class CrossLine {
public:
    bool checkCrossLine(double s1, double s2, double y1, double y2) {
        return (s1 != s2) || (s1 == s2 && y1 == y2); 
    }
};

