"""uva 10494 - If We Were a Child Again, by python3,
frank 2017-03-30"""

if __name__ == '__main__':
    while True:
        try:
            line = input().strip()
            if line == "":
                exit(0)
            words = line.split('/')
            if len(words) == 2:
                a, b = int(words[0].strip()), int(words[-1].strip())
                print(a // b) # 用int(a/b)结果不对，且提交有异常
            else:
                words = line.split('%')
                a, b = int(words[0].strip()), int(words[-1].strip())
                print(a % b)
        except(EOFError):
            exit(0)