# -*- coding: utf-8 -*-
# Author: qwchen
# Date  : 2017-09-03
# 判断地址是否为IPv4地址

# 首先将IP地址按照'.'进行拆分，如果拆分后不是长度为4的话，就不是IP地址了。否则，判断段是否满足IP地址的要求。
# 对于每一段：
#   如果长度为0或者大于3，不是IP地址
#   如果首位为0，并且长度为1，则为IP地址；否则当当首位为0，长度又不是1的话，没法为IP地址【首位为0是比较容易忽略的点】
#   判断每一位是否为0~9的数字，如果有非数字，就不可能是IP地址
#   判断字符串转化为数字后，范围是否为0~255
def check(str):
    num = 0
    if len(str) == 0 or len(str) > 3:
        return False
    if str[0] == '0' and len(str) == 1:
        return True
    elif str[0] == '0':
        return False
    else:
        for s in str:
            if s not in '0123456789':
                return False
            num = num * 10 + int(s)
    if 0 < num < 256:
        return True
    else:
        return False


def validIPAddress(ip):
    ips = ip.split('.')
    if len(ips) != 4:
        return False
    return check(ips[0]) and check(ips[1]) and check(ips[2]) and check(ips[3])


if __name__ == '__main__':
    list_ip = ['123.123.123.123', '123.123.123.300', '123.00.123.123', '123..123.123', '123.123', '123.123.2s.123', '0.0.0.0', '255.255.255.255']
    for ip in list_ip:
        if validIPAddress(ip):
            print '{0} is a ip address'.format(ip)
        else:
            print '{0} is not a ip address'.format(ip)

