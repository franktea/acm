
lines = int(input())

def Solve(number):
    count_arr = [0 for _ in range(10)]
    for i in range(1, number+1):
        line = str(i)
        for c in line:
            count_arr[int(c)] += 1
    print(' '.join([str(x) for x in count_arr]))
    
for _ in range(lines):
    number = int(input())
    Solve(number)