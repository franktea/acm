
letters = """`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./"""
charmap = {}
for index, c in enumerate(letters[1:]):
    charmap[c] = letters[index]
    
while True:
    try:
        line = input()
        for c in line:
            if c == ' ':
                print(c, end="")
            else:
                print(charmap[c], end="")
        print()
    except(EOFError):
        exit(0)