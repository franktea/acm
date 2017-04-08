
def Solve(l, k, m):
    if not l:
        return
    
    def NextK(last_k):
        steps = 0
        if l[last_k]:
            steps += 1
        while steps < k:
            last_k += 1
            if last_k >= len(l):
                last_k = 0
            
            if l[last_k]:
                steps += 1
                
        return last_k
    
    def NextM(last_m):
        steps = 0
        if l[last_m]:
            steps += 1
                  
        while steps < m:
            last_m -= 1
            if last_m < 0:
                last_m = len(l) - 1
                            
            if l[last_m]:
                steps += 1
            
        return last_m
    
    result = []
    left = len(l) # how many left in the array
    last_k = 0
    last_m = len(l) - 1
    while left > 0:
        last_k = NextK(last_k)
        last_m = NextM(last_m)
        if last_k == last_m:
            result.append('{0: >3}'.format(l[last_k]))
            l[last_k] = 0
            left -= 1
        else:
            result.append(''.join(['{0: >3}'.format(l[last_k]), '{0: >3}'.format(l[last_m])]))
            l[last_k] = 0
            l[last_m] = 0
            left -= 2
        
    print(','.join(result))
    

try:
    while True:
        line = [int(x) for x in input().split()]
        if not line[0]:
            break
        
        l = [i+1 for i in range(line[0])]
        k, m = line[1], line[2]
        #print('k=', k, 'm=', m, 'l=', l)
        Solve(l, k, m)
except(EOFError):
    exit(0)
    
    