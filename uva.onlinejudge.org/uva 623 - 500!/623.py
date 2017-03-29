'''uva 623 - 500!
frank'''

def make_result():
    result = 1
    all = [1] # attention: 0! = 1
    for i in range(1, 1001):
        result = result * i
        all.append(result)
    
    return all

if __name__ == '__main__':
    all= make_result()
    try:
        while True:
            line = input().strip()
            if not line:
                continue
            num = int(line)
            print("%d!" % num)
            print(all[num])
    except(EOFError):
        exit(0)

