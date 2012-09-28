#!/usr/bin/env python

def naive_matcher2(s, p, err):
    mcount = 0
    m = len(p)
    for i in range(len(s) - m):
        errno = 0
        for j in range(m):
            if s[i+j] != p[j]:
                mcount = mcount + 1
                errno = errno + 1
                if errno > err:
                    break
            if s[i+j] == p[j]:
                mcount = mcount + 1
            if j == m - 1:
                print 'Pattern occurs with shift %d' % (i,)
                print 'Compared %d times' % (mcount,)
                return i

if __name__ == '__main__':
    err = raw_input('How precise do you want the matcher to be (input the mismatching number you can stand):')
    err = int(err)
    import urllib
    urllib.urlretrieve('http://wuzhh.math.nankai.edu.cn/ds/E.coli.txt', 'E.coli.txt')
    print 'download completed'
    s = open('E.coli.txt').readline()
    p = 'atcaggcctacgccagacagcgcaatagcctgatttagcgtgattttgtaggtcggat'
    naive_matcher2(s, p, err)
