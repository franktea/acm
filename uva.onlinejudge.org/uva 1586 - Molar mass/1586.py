
"""这个python提交上去一直runtime error"""

weight_map = {'C':12.01, 'H':1.008, 'O':16.00, 'N':14.01}

def Solve(line):
    total = 0
    last = 0
    number = 0
    for c in line:
        if c.isdigit():
            number = number*10 + int(c)
        else:
            if number == 0:
                total += last
            else:
                total += last*number
            last = weight_map[c]
            number = 0
    
    if number == 0:
        number = 1
    total += last*number
    print("{:.3f}".format(total))

lines = int(input())
for _ in range(lines):
    line = input()
    Solve(line)
    
