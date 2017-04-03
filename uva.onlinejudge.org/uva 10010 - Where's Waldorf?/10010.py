
class WordMatrix:
    def __init__(self, height, width):
        self.height = height
        self.width = width
        self.matrix = []
        self.delta = [[0, 1],
                      [1, 1],
                      [1, 0],
                      [1, -1],
                      [0, -1],
                      [-1, -1],
                      [-1, 0],
                      [-1, 1]]
    
    def FoundInDirection(self, x, y, dx, dy, word):
        #print(x, y, dx, dy, word)
        for index, w in enumerate(word):
            if self.matrix[x][y] != w:
                return False
            
            if index == (len(word) - 1):
                return True
            
            x += dx
            if (x >= self.height) or (x < 0):
                return False
            
            y += dy            
            if (y >= self.width) or (y < 0):
                return False
        
        return False
    
    def Found(self, x, y, word):
        for dx, dy in self.delta:
            if self.FoundInDirection(x, y, dx, dy, word):
                return True
            
        return False
    
    def Find(self, word):
        for x in range(self.height):
            for y in range(len(self.matrix[x])):
                if self.Found(x, y, word):
                    print(x+1, y+1)
                    return
        

case_count = int(input())
for i in range(case_count):
    if i:
        print()
        
    input()
    h, w = [int(x) for x in input().split()]
    wm = WordMatrix(h, w)
    for _ in range(h):
        wm.matrix.append(input().lower())
    
    wc = int(input())
    for _ in range(wc):
        wm.Find(input().lower())
        
    