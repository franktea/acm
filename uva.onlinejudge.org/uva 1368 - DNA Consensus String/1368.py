from collections import defaultdict

class DNAGroup:
    def __init__(self, height, width):
        self.height = height
        self.width = width
        self.groups = []
    
    def AddGroup(self, group):
        self.groups.append(group)
        
    def Solve(self):
        value = 0
        result = []
        for i in range(self.width):
            col = [g[i] for g in self.groups]
            char_map = defaultdict(int) # 统计每个字符出现的次数
            for c in col:
                char_map[c] += 1
            
            max_char = 'A'
            max_times = char_map['A']
            for c in ['C', 'G', 'T']:
                if char_map[c] > max_times:
                    max_char = c
                    max_times = char_map[c]
            
            result.append(max_char)
            value += (self.height - max_times)
        
        print(''.join(result))
        print(value)
        
case_count = int(input())
for _ in range(case_count):
    h, w = [int(x) for x in input().split()]
    dg = DNAGroup(h, w)
    for _ in range(h):
        dg.AddGroup(input())
    dg.Solve()
    
