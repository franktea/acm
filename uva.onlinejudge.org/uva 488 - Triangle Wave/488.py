from _curses import pair_content

def get_pair():
    pair = []
    while True:
        try:
            line = input()
            if not line:
                continue
            
            pair.append(int(line))
            if len(pair) == 2:
                a, b = pair
                pair = []
                yield a, b
        except(EOFError):
            break
        

def solve(amplitude, frequency):
    l = [i for i in range(1, amplitude+1)]
    l2 = l[-2::-1]
    l.extend(l2)
    for i in range(frequency):
        if i != 0:
            print()
        for index, x in enumerate(l):
            print(str(x)*x)

cases = int(input())
index = 0
for a, b in get_pair():
    if index > 0:
        print()
    index += 1
    solve(a, b)
    
