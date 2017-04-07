
"""这个python提交结果runtime error, cpp文件ok"""

def NextIndex(last_index, line):
    c = line[0]
    for i in range(last_index+1, len(line)):
        if line[i] == c:
            return i

    return len(line)

def Check(index, line):
    length = index
    repeat = 1
    while (repeat * length) < len(line):
        for i in range(length):
            if length + i >= len(line):
                return False
            
            if line[i] != line[repeat*length + i]:
                return False
        repeat += 1
        
    return True

def Solve(line):
    last_index = 0
    found = False
    while (not found) and (last_index < len(line)-1):
        last_index = NextIndex(last_index, line)
        found = Check(last_index, line)
        if found:
            print(last_index)
            return
    
    print(len(line))
    
def main():
    lines = int(input())
    
    for i in range(lines):
        if i:
            print()
            
        line = input()
        while not line:
            line = input()
        
        Solve(line)
        

if __name__ == '__main__':
    main()