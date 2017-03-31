
from sys import stdin

def solve(line):
    for c in line:
        if c == '_':
            return
      
    ascii = []
    for c in line:
        if (c == '|') or (c == '.'):
            continue
        if c == ' ':
            ascii.append('0')
        else:
            ascii.append('1')
 
    number = int(''.join(ascii), 2)
    print(chr(number), end='')

for line in stdin.readlines():
    line = line.strip()
    if not line:
        exit(0)

    solve(line)
