
def solve(a, b):
    '''计算前把小数点去掉当成整数，最后再把小数点加上去'''
    a1, a2 = a.split('.')
    dots = len(a2)
    while (len(a2) > 0) and (a2[-1] == '0'): # remove 0 of tail
        a2 = a2[:-1]
        dots -= 1
    inta = int(''.join([a1, a2]))
    intb = int(b)
    dots = dots * intb
    result = str(inta ** intb) # pow(x, y) not precise here
    if len(result) > dots:
        print(''.join([result[:-dots], '.', result[-dots:]]))
    else:
        print(''.join(['.', '0'*(dots-len(result)), result]))
        
        
if __name__ == '__main__':
    try:
        while True:
            line = input().strip()
            if not line:
                exit(0)
            a, b = line.split()
            solve(a, b)
    except(EOFError):
        exit(0)