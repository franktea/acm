
try:
    while True:
        num = int(input())
        if num < 0:
            break
        
        if num == 1:
            print("0%")
        else:
            print("{}%".format(25*num))
except(EOFError):
    pass