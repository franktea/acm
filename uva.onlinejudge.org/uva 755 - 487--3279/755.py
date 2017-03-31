
"""755.py get TLE error, use cpp file"""

c2n = {"A":2, "B":2, "C":2, "D":3, "E":3, "F":3, "G":4, "H":4, "I":4, "J":5, "K":5, "L":5, "M":6, "N":6, "O":6, "P":7, "R":7, "S":7, "T":8, "U":8, "V":8, "W":9, "X":9, "Y":9}

def solve(lines):
    numbers = {}
    for l in lines:
        num = []
        for c in l:
            if c.isnumeric():
                num.append(c)
            elif c.isalpha():
                num.append(str(c2n[c]))
                
            if len(num) == 3:
                num.append('-')

        num = ''.join(num)
        
        if not num in numbers:
            numbers[num] = 1
        else:
            numbers[num] += 1
    
    mt = [number for number in numbers.keys() if numbers[number] > 1]
    if len(mt) == 0:
        print('No duplicates.')
        return
    
    mt.sort()
    for l in mt:
        print(l, numbers[l])
        

cases = int(input())
for i in range(cases):
    if i != 0:
        print()
    
    input()
    rows = int(input())
    lines = [input() for r in range(rows)]
    solve(lines)