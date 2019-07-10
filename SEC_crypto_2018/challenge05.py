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
    if len(content) != 2:
        exit(84)
    return(content)

def rkx(msg, key):
    output_bytes = b''
    index = 0
    for byte in encoded:
        output_bytes += bytes([byte ^ key[index]])
        if (index + 1) == len(key):
            index = 0
        else:
            index += 1
    return(output_bytes)
    
if __name__ == '__main__':
    if (len(sys.argv) != 2):
        exit(84)
    content = read_file(sys.argv[1])

    key = binascii.unhexlify(content[0])
    msg = content[1]
    encoded = binascii.unhexlify(msg)
    ciphertext = rkx(encoded, key)
    print(ciphertext.hex())
