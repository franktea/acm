
lines = int(input())
for i in range(lines):
    l = [int(x) for x in input().split()]
    l.sort()
    print("Case {}: {}".format(i+1, l[1]))
    
