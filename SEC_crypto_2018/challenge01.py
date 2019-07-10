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
    content = ''.join(map(str, content))
    return(content)

if __name__ == '__main__':
    if (len(sys.argv) != 2):
        exit(84)
    content = read_file(sys.argv[1])
    if len(content) % 2 == 1:
        exit(84)
    hex = bytes.fromhex(content)
    base = base64.b64encode(hex)
    print(base.decode())
