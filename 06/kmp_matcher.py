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
    mcount = 0                  # how many times compared
    found = 0
    for i in range(len(s)):
        while k > 0 and p[k] != s[i]:
            k = table[k-1]
            mcount = mcount + 1
        if p[k] == s[i]:
            k = k + 1
            mcount = mcount + 1
        if k == m:
            print 'Pattern occurs with shift %d' % (i-m+1)
            print 'Compared %d times' % mcount
	    found = 1
	    k = table[k-1]
    if not found:
        print 'Pattern not found'
        return -1

def naive_matcher(s, p):
    mcount = 0
    m = len(p)
    for i in range(len(s) - m):
        for j in range(m):
            if s[i+j] != p[j]:
                mcount = mcount + 1
                break
            if s[i+j] == p[j]:
                mcount = mcount + 1
            if j == m - 1:
                print 'Pattern occurs with shift %d' % i
                print 'Compared %d times' % mcount

if __name__ == '__main__':
    import urllib
    urllib.urlretrieve('http://wuzhh.math.nankai.edu.cn/ds/E.coli.txt', 'E.coli.txt')
    s = open('E.coli.txt').readline()
    p = 'atcaggcctacgccagacagcgcaatagcctgatttagcgtgattttgtaggtcggat'
    print 'This is KMP matcher'
    kmp_matcher(s, p)
    print '\nThis is naive matcher'
    naive_matcher(s, p)
