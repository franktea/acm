
from sys import stdin

mirror_map = {x[0]:x[1] for x in """AA
MM
YY
Z5
OO
11
2S
E3
3E
S2
5Z
HH
TT
II
UU
JL
VV
88
WW
LJ
XX
""".splitlines() if x.strip() != ""}

def check_palindrome(line):
    """return 1 if is palidrome, else 0"""
    for i in range(len(line)//2+1):
        if line[i] != line[-(i+1)]:
            return 0
    return 1

def check_mirror(line):
    mirror = ''.join([mirror_map.get(c, ' ') for c in line])[::-1]
    if mirror == line:
        return 1
    else:
        return 0

descs = [' -- is not a palindrome.',
         ' -- is a regular palindrome.',
         ' -- is a mirrored string.',
         ' -- is a mirrored palindrome.']


for line in stdin.readlines():
    line = line.strip()
    if not line:
        break
    
    print(line, end="")
    print(descs[(check_mirror(line) << 1) | check_palindrome(line)])
    print()
    