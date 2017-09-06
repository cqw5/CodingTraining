# -*- coding: utf-8 -*-
# Author: qwchen
# Date  : 2017-09-03
# 判断地址是否为IPv4地址


def check(str):
    num = 0
    if str[0] == '0' and len(str) == 0:
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
    ip = '123.123.123.323'
    if validIPAddress(ip):
        print '{0} is a ip address'.format(ip)
    else:
        print '{0} is not a ip address'.format(ip)

