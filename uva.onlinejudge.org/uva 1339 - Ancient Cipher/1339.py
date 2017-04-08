
def Solve(a, b):
    m1, m2 = {}, {}
    for x in a:
        if x in m1:
            m1[x] += 1
        else:
            m1[x] = 1
    
    for x in b:
        if x in m2:
            m2[x] += 1
        else:
            m2[x] = 1
    
    if len(m1.keys()) != len(m2.keys()):
        return False
    
    v1 = sorted(m1.values())
    v2 = sorted(m2.values())
    return v1 == v2

while True:
    try:
        a, b = input(), input()
        result = Solve(a, b)
        if result:
            print("YES")
        else:
            print("NO")
    except(EOFError):
        exit(0)
    
