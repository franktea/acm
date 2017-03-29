'''好没意思的一道题'''

if __name__ == '__main__':
    positive = ['1', '4', '78']    
    count = int(input().strip())
    for i in range(count):
        line = input().strip()
        if line in positive:
            print('+')
        elif line[-2:] == '35':
            print('-')
        elif line[0] == '9' and line[-1] == '4':
            print('*')
        else:
            print('?')