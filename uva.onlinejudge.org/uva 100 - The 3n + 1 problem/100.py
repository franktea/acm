
def output(n):
    result = [n]
    while n > 1:
        if n % 2:
            n = 3*n + 1
        else:
            n = n/2
        result.append(n)
    return len(result)

result = []
for i in range(1, 8001):
    result.append(output(i))
    
print result
