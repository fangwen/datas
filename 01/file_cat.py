#!/usr/bin/env python
"""Concatenate files into a single file named 'generated'."""

import os, sys

if len(sys.argv) < 2:
    print "Usage: file_cat.py file1 file2 ..."
else:
    gen = open('generated', 'a')
    for file in sys.argv[1:]:
        content = open(file)
        gen.write('###### ')
        gen.write(os.path.basename(file))
        gen.write(' ######\n')
        gen.writelines(content.readlines())
        content.close()
    gen.close()
