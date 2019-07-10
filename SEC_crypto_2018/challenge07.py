#!/usr/bin/python3

import sys
import base64
import binascii
from Crypto.Cipher import AES

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


def decrypt_ecb_cipher(ciphertext, key):
    cipher = AES.new(key, AES.MODE_ECB)
    plaintext = cipher.decrypt(ciphertext).rstrip(b"\03x")
    return(plaintext)

if __name__ == '__main__':
    if (len(sys.argv) != 2):
        exit(84)
    content = read_file(sys.argv[1])
    key = binascii.unhexlify(content[0])
    ciphertext = base64.b64decode(content[1])
    msg = decrypt_ecb_cipher(ciphertext, key)
    print(base64.b64encode(msg).decode())
