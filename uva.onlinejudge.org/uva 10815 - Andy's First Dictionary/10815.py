
def find_first_of_char(index, line):
    for i in range(index, len(line)):
        if line[i].isalpha():
            return i
    return len(line)

def find_first_notof_char(index, line):
    for i in range(index, len(line)):
        if not line[i].isalpha():
            return i
    return len(line)

def get_words(line, words):
    start = 0
    while start < len(line):
        start = find_first_of_char(start, line)
        end = find_first_notof_char(start, line)
        if start < len(line):
            word = line[start:end]
            words.add(word.lower())
            start = end


if __name__ == '__main__':
    words = set()
    try:
        while True:
            line = input().strip()
            if not line:
                continue
            get_words(line, words)
    except(EOFError):
        pass
    
    l = list(words)
    l.sort()
    for w in l:
        print(w)

