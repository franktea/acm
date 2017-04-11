from collections import defaultdict

def GetValue(v):
    d = {'T':10, 'J':11, 'Q':12, 'K':13, 'A':14}
    if v in d:
        return d[v]
    
    return int(v)

class TexasFactory:
    def __init__(self, five_list):
        """arg five list:five poker list, such as 2H, 3D, 5S, 9C, KD"""
        self.values = defaultdict(int)
        self.suits = defaultdict(int)
        self.nums = []
        for ss in five_list:
            num, suit = GetValue(ss[0]), ss[1]
            self.nums.append(num)
            self.values[num] += 1
            self.suits[suit] += 1
            
    def CheckStraight(self):
        vl = self.nums
        vl.sort(reverse=True)
        for i in range(1, len(vl)):
            if vl[i] != (vl[i-1] - 1):
                return False
        
        return True
        
    def CreateTexas(self):
        if len(self.suits) == 1: #only one suit
            if self.CheckStraight():
                return StraightFlush(self.nums)
            else:
                return Flush(self.nums)

        if 4 in self.values.values():
            return FourOfAKind(self.nums)
        
        if 3 in self.values.values() and 2 in self.values.values():
            return FullHouse(self.nums)
        
        if self.CheckStraight():
            return Straight(self.nums)
        
        if 3 in self.values.values():
            return ThreeOfAKind(self.nums)
        
        pair_count = [i for i in self.values.values()].count(2)
        if pair_count == 2:
            return TwoPairs(self.nums)
        elif pair_count == 1:
            return Pair(self.nums)
        
        return HighCard(self.nums)
        

def ToString(texas):
    return '{}, cards:{}'.format(texas.__class__.__name__, texas.values)
        
class StraightFlush:
    def __init__(self, vl):
        self.priority = 9
        self.values = vl
        self.Sort()
    
    def Sort(self):
        self.values.sort(reverse=True)
        
class FourOfAKind:
    def __init__(self, vl):
        self.priority = 8
        self.values = vl
        self.Sort()
    
    def Sort(self):
        d = defaultdict(int)
        for v in self.values:
            d[v] += 1
        
        for k, v in d.items():
            if v == 1:
                self.values[-1] = k
            else:
                self.values[:4] = [k, k, k, k]
                

class FullHouse:
    def __init__(self, vl):
        self.priority = 7
        self.values = vl
        self.Sort()
        
    def Sort(self):
        d = defaultdict(int)
        for v in self.values:
            d[v] += 1
        
        for k, v in d.items():
            if v == 3:
                self.values[:3] = [k, k, k]
            else:
                self.values[-2:] = [k, k]
                
class Flush:
    def __init__(self, vl):
        self.priority = 6
        self.values = vl
        self.values.sort(reverse=True)
        
class Straight:
    def __init__(self, vl):
        self.priority = 5
        self.values = vl
        self.values.sort(reverse=True)
        
class ThreeOfAKind:
    def __init__(self, vl):
        self.priority = 4
        self.values = vl
        self.Sort()
        
    def Sort(self):
        d = defaultdict(int)
        for v in self.values:
            d[v] += 1
        
        singles = []
        for k, v in d.items():
            if v == 3:
                self.values[:3] = [k, k, k]
            else:
                singles.append(k)
        singles.sort(reverse=True)
        self.values[-2:] = singles        

class TwoPairs:
    def __init__(self, vl):
        self.priority = 3
        self.values = vl
        self.Sort()
        
    def Sort(self):
        d = defaultdict(int)
        for v in self.values:
            d[v] += 1
        
        ps = [k for k, v in d.items() if v == 2]
        single = [k for k, v in d.items() if v == 1][0]
        ps.sort(reverse=True)
        self.values[0:2] = ps[0], ps[0]
        self.values[2:2] = ps[1], ps[1]
        self.values[-1] = single
        
class Pair:
    def __init__(self, vl):
        self.priority = 2
        self.values = vl
        self.Sort()
        
    def Sort(self):
        d = defaultdict(int)
        for v in self.values:
            d[v] += 1
        
        singles = []
        for k, v in d.items():
            if v == 2:
                self.values[:2] = k, k
            else:
                singles.append(k)
        singles.sort(reverse=True)
        self.values[-3:] = singles

class HighCard:
    def __init__(self, vl):
        self.priority = 1
        self.values = vl
        self.values.sort(reverse=True)


def CompareTexas(tx1, tx2):
    if tx1.priority != tx2.priority:
        return tx1.priority - tx2.priority
    
    for i in range(len(tx1.values)):
        if tx1.values[i] != tx2.values[i]:
            return tx1.values[i] - tx2.values[i]
    
    return 0
        
try:
    while True:
        line = input().split()
        if len(line) != 10:
            break
        
        tx1 = TexasFactory(line[:5]).CreateTexas()
        tx2 = TexasFactory(line[-5:]).CreateTexas()
        #print(line[:5], "   |||   ", line[-5:])
        #print(ToString(tx1))
        #print(ToString(tx2))
        #print("------------------")
        v = CompareTexas(tx1, tx2)
        if v < 0:
            print('White wins.')
        elif v > 0:
            print('Black wins.')
        else:
            print('Tie.')
except(EOFError):
    pass
