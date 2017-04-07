
from collections import deque

def Solve(line):
    chars = deque(line)
    s = line
    for i in range(len(line)):
        chars.rotate()
        s2 = ''.join(chars)
        if s2 < s:
            s = s2
    
    print(s)

lines = int(input())
for _ in range(lines):
    line = input()
    Solve(line)