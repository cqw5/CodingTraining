/*! Author: qwchen
 *! Date  : 2017-09-06
 *  字符串移位包含的问题（编程之美3.1）
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * 思路：
 *   判断s2是否为s1移位后的子串。如果s2是s1移动=位后的子串的话，s2一定在s1+s1合成的子串中
 * 时间复杂度:O(N)
 * 空间复杂度:O(N)
 */
bool shiftStr(string s1, string s2) {
	string s1s1 = s1 + s1;
	return strstr(s1s1.c_str(), s2.c_str()) != nullptr;
}


int main(){
	string s1 = "AABCD";
	string s2 = "CDAA";
	cout << shiftStr(s1, s2) << endl;
}
