/*! Source: https://leetcode.com/problems/simplify-path/
 *! Author: qwchen
 *! Date  : 2016-12-26
 *  获取Linux目录的简单路径
 */

/*
 * 思路：
 *   将路径按照'/'拆分，然后对拆分后的每个元素：
 *   * 如果为空或者"."，则不处理
 *   * 如果为".."并且栈非空，则出栈回退
 *   * 否则，如果为非".."，则入栈
 *   最后将栈中元素如此，构成路径；如果路径还是为空，返回"/"
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
class Solution {
public:
    string simplifyPath(string path) {
        string newPath = "";
        string str;
        stack<string> s;
        stringstream spath(path);
        while(getline(spath, str, '/')) {  // getline函数可以将stringstream对象按指定字符拆分
            if (str == "" || str == ".") continue;
            if (str == ".." && !s.empty()) s.pop();
            if (str != "..") s.push(str);
        }
        while (!s.empty()) {
            newPath = "/" + s.top() + newPath;
            s.pop();
        }
        return newPath.empty()? "/": newPath;
    }
};

