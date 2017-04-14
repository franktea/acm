
def GuessOne(s):
    r = "one"
    same_count = 0
    for i, a in enumerate(r):
        if a == s[i]:
            same_count += 1
    
    return same_count >= 2

def Guess(s):
    if len(s) == 5:
        print(3)
    elif GuessOne(s):
        print(1)
    else:
        print(2)

try:
    c = int(input())
    for _ in range(c):
        Guess(input())
except(EOFError):
    pass