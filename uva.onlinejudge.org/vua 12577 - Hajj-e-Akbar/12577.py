
try:
    cnt = 0
    while 1:
        cnt += 1
        l = input()
        if l == "*":
            break
        
        if l[0] == 'H':
            print("Case {}: Hajj-e-Akbar".format(cnt))
        else:
            print("Case {}: Hajj-e-Asghar".format(cnt))
except(EOFError):
    pass