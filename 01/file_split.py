#!/usr/bin/env python

f = open('generated')
for line in f:
    if line.startswith('#####'):
        try:
            file_individual.close()
        except NameError:
            pass
        filename = line.rstrip('\n').strip('#').strip(' ')
        file_individual = open(filename, 'w')
    else:
        file_individual.write(line)
f.close()
