#!/usr/bin/env python

def kmp_table(p):
    table = [0]
    k = 0
    for i in range(1, len(p)):
        while k > 0 and p[k] != p[i]:
            k = table[k] - 1
        if p[k] == p[i]:
            k = k + 1
        table.append(k)
    return table

def kmp_matcher(s, p):
    table = kmp_table(p)
    m = len(p)
    k = 0
    for i in range(len(s)):
        while k > 0 and p[k] != s[i]:
            k = table[k-1]
        if p[k] == s[i]:
            k = k + 1
        if k == m:
            print 'Pattern occurs with shift %d' % (i-m+1,)
            return i-m+1
    if i == len(s) - 1 and k < m:
        print 'Pattern not found'
        return -1

if __name__ == '__main__':
    s = open('/home/yufw/Downloads/E.coli.txt').readline()
    p = 'atcaggcctacgccagacagcgcaatagcctgatttagcgtgattttgtaggtcggat'
    kmp_matcher(s, p)
