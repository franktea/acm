
lines = int(input())
for _ in range(lines):
    a, b = [int(x) for x in input().split()]
    if a < b:
        print("<")
    elif a > b:
        print(">")
    else:
        print("=")
