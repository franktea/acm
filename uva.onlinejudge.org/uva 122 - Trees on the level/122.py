
"""c++和这个一样思路的正确，但是python的就是不对！"""

class Node:
    def __init__(self, level=0, value = None):
        self.value = value
        self.level = level # level, 0 is root
        self.left = self.right = None

    def OutPut(self):
        print("    "*self.level, self.value)
        if self.left:
            self.left.OutPut()
        if self.right:
            self.right.OutPut()
    
    def GetOutPutByLevel(self, result):
        """return false is some node is not inited"""
        if self.value is None:
            return False
        result[self.level].append(self.value)
        if self.left:
            if not self.left.GetOutPutByLevel(result):
                return False
        if self.right:
            if not self.right.GetOutPutByLevel(result):
                return False
        return True
        
class Tree:
    def __init__(self):
        self.root = Node()
        self.multi_times = False # some value give more than one time
        self.inited = False
        self.max_level = 0
    
    def FindNode(self, node, direction):
        """direction = L or R"""
        if direction == 'L':
            if not node.left:
                node.left = Node(node.level + 1)
            if node.left.level > self.max_level:
                self.max_level = node.left.level
            return node.left
        else:
            if not node.right:
                node.right = Node(node.level + 1)
            if node.right.level > self.max_level:
                self.max_level = node.right.level
            return node.right

    def AddNode(self, value, dir_string):
        self.inited = True
        
        """dir_string is a string like : LLL, RRR, LLLR etc"""
        if not dir_string:
            if self.root.value is not None: # 根节点也可能被赋值多次！
                self.multi_times = True
            self.root.value = value
            return
        
        node = self.root
        for direction in dir_string:
            node = self.FindNode(node, direction)
        
        if node.value is not None:
            self.multi_times = True
        node.value = value
            
    def OutPut(self):
        self.root.OutPut()
        
    def BFSOutPut(self):
        if not self.inited:
            print("not complete")
            return
        
        result = [[] for _ in range(self.max_level+1)]
        b = self.root.GetOutPutByLevel(result)
        if not b:
            print("not complete")
        else:
            strs = []
            for x in result:
                for y in x:
                    strs.append(str(y))
            print(' '.join(strs))

def Test():
    tree = Tree()
    tree.AddNode(11, "LL")
    tree.AddNode(7, "LLL")
    tree.AddNode(8, "R")
    tree.AddNode(5, "")
    tree.AddNode(4, "L")
    tree.AddNode(13, "RL")
    tree.AddNode(2, "LLR")
    tree.AddNode(1, "RRR")
    tree.AddNode(4, "RR")
    tree.OutPut()

try:
    tree = Tree()
    while True:
        line = [x for x in input().split()]
        for x in line:
            if x == '()':
                tree.BFSOutPut()
                tree = Tree()
            else:
                a = x.replace("(", "").replace(")", "").split(",")
                value, dir_string = int(a[0]), a[1]
                tree.AddNode(value, dir_string)
        
except(EOFError):
    pass

