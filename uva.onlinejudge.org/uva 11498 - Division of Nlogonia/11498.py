
lines = int(input())
while lines:
    x, y = [int(a) for a in input().split()]
    for _ in range(lines):
        a, b = [int(a) for a in input().split()]
        if (a == x) or (b == y):
            print("divisa")
        elif (a > x) and (b < y):
            print("SE")
        elif (a < x) and (b < y):
            print("SO")
        elif (a < x) and (b > y):
            print("NO")
        elif (a > x) and (b > y):
            print("NE")
            
    lines = int(input())