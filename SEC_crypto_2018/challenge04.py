#!/usr/bin/python3

import sys
import base64
import binascii

def read_file(path):
    try:
        file = open(path, "r")
    except:
        exit(84)
    content = file.read().splitlines()
    if not content:
        exit(84)
    return(content)

def score(text):
	charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.'\n"
	p = 0
	for s in text:
		if s in charset or s == ' ' or s == '\'':
			p+=1
	return p

if __name__ == '__main__':
    if (len(sys.argv) != 2):
        exit(84)
    content = read_file(sys.argv[1])
    line = 0
    b = 0
    for i in content:
        encoded = binascii.unhexlify(i)
        line = line + 1
        for xor_key in range(256):
            decoded = ''.join(chr(b ^ xor_key) for b in encoded)
            if score(decoded) > b:
                b = score(decoded)
                best = xor_key
                bestline = line
    best = hex(best)
    best = best.replace("0x", "")
    print(bestline,best.upper())

