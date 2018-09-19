#!/usr/bin/env python
# coding=utf-8

def sum():
    sum = 0
    x = 1
    while x < 1000001:
        sum = sum + x
        x += 1
    return sum
print(sum())
