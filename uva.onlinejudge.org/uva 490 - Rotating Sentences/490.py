
lines = []
while True:
    try:
        lines.append(input())
    except(EOFError):
        break

lines = lines[::-1]
max_len = max([len(line) for line in lines])
for i in range(max_len):
    for l in lines:
        if i < len(l):
            print(l[i], end="")
        else:
            print(" ", end="")
    print("")