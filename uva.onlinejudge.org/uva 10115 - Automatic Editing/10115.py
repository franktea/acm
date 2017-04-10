
class Replacer:
    def __init__(self, times):
        self.times = times
        self.sentence = None
        self.from_to = []
        
    def Input(self):
        for _ in range(self.times):
            self.from_to.append([input(), input()])
        self.sentence = input()
        
    def Solve(self):
        for from_, to_ in self.from_to:
            while self.sentence.find(from_) >= 0:
                self.sentence = self.sentence.replace(from_, to_, 1)
        
        print(self.sentence)
        
        
try:
    while True:
        lines = int(input())
        if 0 == lines:
            break
        
        r = Replacer(lines)
        r.Input()
        r.Solve()
except(EOFError):
    pass