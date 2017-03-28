
import math

def solve(num):
    print('-'*60)
    lines = []
    max_length = 0
    for i in range(num):
        lines.append(input())
        length = len(lines[-1])
        if length > max_length:
            max_length = length
    
    cols = math.floor(62 / (max_length+2))
    rows = math.ceil(len(lines) / cols)
    lines.sort()
    
    format1 = "{0:<%d}" % (max_length + 2)
    format2 = "{0:<%d}" % max_length
    for r in range(rows):
        for c in range(cols):
            index = c*rows + r
            if index < num:
                if c == cols - 1:
                    print(format2.format(lines[(cols-1)*rows + r]), end="")
                else:
                    print(format1.format(lines[c*rows + r]), end="")
        print("")
        
        
if __name__ == "__main__":
    while True:
        try:
            lines = input()
            if not lines:
                break
            num = int(lines)
            solve(num)
        except(EOFError):
            break