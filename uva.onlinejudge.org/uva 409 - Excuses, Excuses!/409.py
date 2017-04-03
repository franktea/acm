
import re

r = re.compile(r"[a-zA-Z]+")

class Excuses:
    def __init__(self, kw_count, exe_count):
        self.keywords = set()
        self.keyword_count = kw_count
        self.exe_count = exe_count
        self.max_times = 0
        self.longest = []
        for i in range(self.keyword_count):
            self.keywords.add(input().lower())
        
    def Input(self):
        execuse = input()
        times = 0
        for i in r.finditer(execuse):
            word = i.group(0).lower()
            if word in self.keywords:
                times += 1
        
        if times > self.max_times:
            self.max_times = times
            self.longest = [execuse]
        elif times == self.max_times:
            self.longest.append(execuse)
    
    def OutPut(self):
        for i in self.longest:
            print(i)
        print()

case_index = 0
while True:
    try:
        line = input().split()
        kw, ec = int(line[0]), int(line[1])
        case_index += 1
        print("Excuse Set #{}".format(case_index))
        exc = Excuses(kw, ec)
        for i in range(ec):
            exc.Input()
        exc.OutPut()
    except:
        break
            