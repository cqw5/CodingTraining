/*! Author: qwchen
 *! Date  : 2017-09-03
 *  进制的转化
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


/**
 * 十进制转化为其他进制（1~16）
 */
string decimalToAnyScale(int decimal, int scale){
    char transform[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                          '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};  
    string str;
    // 考虑负数
    string flag = "";
    if(decimal < 0) {
        flag = "-";
        decimal *= -1;
    } 
    while(decimal > 0){
        str = transform[decimal % scale] + str;
        decimal /= scale;
    }
    str = flag + str;
    return str;
}

/**
 * 其他进制转（1~16）换为十进制
 */
int anyScaleToDecimal(string num, int scale) {
    unordered_map<char, int> transform;
    transform['0'] = 0;
    transform['1'] = 1;
    transform['2'] = 2;
    transform['3'] = 3;
    transform['4'] = 4;
    transform['5'] = 5;
    transform['6'] = 6;
    transform['7'] = 7;
    transform['8'] = 8;
    transform['9'] = 9;
    transform['A'] = 10;
    transform['B'] = 11;
    transform['C'] = 12;
    transform['D'] = 13;
    transform['E'] = 14;
    transform['F'] = 15;
    int decimal = 0;
    int i = 0;
    int flag = 1;
    if(num[i] == '-') {
        flag = -1;
        i++;
    }
    for(; i < num.size(); i++) {
        decimal = decimal * scale + transform[num[i]];
    }
    return decimal;
}


int main(){
    cout << decimalToAnyScale(-12, 16) << endl;
    cout << anyScaleToDecimal("AA", 16) << endl;
    return 0;
}




