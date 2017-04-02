
words = []
line = input()
while line != "#":
    words.extend(line.split())
    line = input()
    
class WordItem:
    def __init__(self, word):
        self.original = word
        changed = [c for c in word.lower()]
        changed.sort()
        self.key = ''.join(changed)
        self.times = 1
        

all_dict = {}
for word in words:
    wi = WordItem(word)
    if not wi.key in all_dict:
        all_dict[wi.key] = wi
    else:
        all_dict[wi.key].times += 1

result = [x.original for x in all_dict.values() if x.times == 1]
result.sort()
for r in result:
    print(r)