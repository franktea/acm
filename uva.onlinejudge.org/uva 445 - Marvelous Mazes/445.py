
while True:
    try:
        line = input()
        if not line:
            print("")
            continue
        
        num = 0
        for i in line:
            if i.isnumeric():
                num += int(i)
            elif i == '!':
                print()
                num = 0
            else:
                if i == 'b':
                    i = ' '
                print(i*num, end="")
                num = 0
        print()
    except(EOFError):
        exit(0)