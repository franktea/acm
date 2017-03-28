"""uva 615 - Is It A Tree?
frank"""

def get_pair():
    try:
        while True:
            line = input().strip()
            if not line:
                continue
            nums = [int(num) for num in line.split()]
            while nums:
                yield nums.pop(0), nums.pop(0)
    except(EOFError):
        pass

def check(nodes, parent_of):
    """采用删除叶子节点的方法，最终可以全部删除完，说明无环"""
    def find_leaf():
        for k, v in nodes.items():
            if not len(v):
                return k
        return None
    
    root_count = 0 # 根节点只能有一个，否则是森林不是树
    
    leaf = find_leaf()
    while leaf:
        del nodes[leaf]
        if leaf in parent_of:
            nodes[parent_of[leaf]].remove(leaf)
        else: # 无父节点，说明是根节点
            if root_count: # 不止一个根节点
                return False
            root_count = 1
        leaf = find_leaf()
    
    if len(nodes):
        return False
    return True
    
def solve(count, pairs):
    nodes = {}
    parent_of = {}
    for a, b in pairs:
        if a not in nodes:
            nodes[a] = set()
        if b not in nodes:
            nodes[b] = set()
        nodes[a].add(b)
        if b in parent_of:
            print('Case %d is not a tree.' % count)
            return
        parent_of[b] = a
    
    if check(nodes, parent_of):
        print('Case %d is a tree.' % count)
    else:
        print('Case %d is not a tree.' % count)

if __name__ == '__main__':
    count = 0
    while True:
        count += 1
        pairs = []
        for a, b in get_pair():
            #print("---->", a, b)
            if a == 0:
                solve(count, pairs)
                break
            elif a == -1:
                exit(0)
            else:
                pairs.append((a, b))
                