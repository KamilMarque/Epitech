#!/usr/bin/python3

import sys
import base64

def read_file(path):
    try:
        file = open(path, "r")
    except:
        exit(84)
    content = file.read().splitlines()
    if not content:
        exit(84)
    if(len(content) != 2):
        exit(84)
    if(len(content[0]) != len(content[1])):
        exit(84)
    return(content)

if __name__ == '__main__':
    if (len(sys.argv) != 2):
        exit(84)
    content = read_file(sys.argv[1])
    res = ('%x' % (int(content[0], 16) ^ int(content[1], 16)))
    print(res.upper())
