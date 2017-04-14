
class SubFinder:
    def __init__(self, s, t):
        self.s = s
        self. t = t
        
    def Solve(self):
        if len(s) > len(t):
            print("No")
            return
        
        last_index = -1
        for c in s:
            last_index = t.find(c, last_index+1)
            if last_index == -1:
                print("No")
                return
        print("Yes")
        
try:
    while True:
        s, t = input().split()
        sf = SubFinder(s, t)
        sf.Solve()
except(EOFError):
    pass
