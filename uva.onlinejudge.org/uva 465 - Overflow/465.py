
max_int = 2147483647

def Solve(line):
    print(line)
    
    a, b = 0, 0
    f = None
    
    if '*' in line:
        a, b = [int(x.strip()) for x in line.split('*')]
        f = lambda x, y: x * y
    elif '+' in line:
        a, b = [int(x.strip()) for x in line.split('+')]
        f = lambda x, y: x + y
    
    if a > max_int:
        print('first number too big')
    
    if b > max_int:
        print('second number too big')
    
    # 在乘法的时候，即使a、b中一个越界，但是另一个如果为0，结果仍然不是越界的
    result = f(a, b)
    if result > max_int:
        print('result too big')
        

while True:
    try:
        line = input()
        if not line:
            break
        
        Solve(line)
    except(EOFError):
        exit(0)