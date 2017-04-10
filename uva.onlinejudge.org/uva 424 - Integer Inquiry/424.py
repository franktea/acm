
result = 0
try:
    while True:
        a = int(input())
        if a == 0:
            break
        result += a
except(EOFError):
    pass

print(result)
        
        