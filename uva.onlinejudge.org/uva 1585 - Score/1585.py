
def Solve(line):
    ocount = 0
    result = 0
    for c in line:
        if c == 'O':
            ocount += 1
            result += ocount
        else:
            ocount = 0
    
    print(result)

lines = int(input())
for _ in range(lines):
    line = input()
    Solve(line)