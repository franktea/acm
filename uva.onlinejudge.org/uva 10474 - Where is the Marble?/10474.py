
from bisect import bisect_left

class Data:
    def __init__(self, dc, cc):
        self.data_count = dc
        self.case_count = cc
        self.data = []
        
    def Solve(self):
        for _ in range(self.data_count):
            self.data.append(int(input()))
        
        self.data.sort()
        
        for _ in range(self.case_count):
            self.Search(int(input()))
    
    def Search(self, num):
        pos = bisect_left(self.data, num)
        if (0 <= pos < len(self.data)) and (self.data[pos] == num):
            print(num, 'found at', pos+1)
        else:
            print(num, 'not found')
            

try:
    case_count = 0
    while True:
        a, b = [int(x) for x in input().split()]
        if (0 == a) and (0 == b):
            break
        
        case_count += 1
        print("CASE# {}:".format(case_count))
        d = Data(a, b)
        d.Solve()
except(EOFError):
    pass