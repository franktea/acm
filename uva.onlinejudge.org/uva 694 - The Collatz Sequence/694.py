
def solve(a, limit):
    terms = 1
    while a > 1:
        if not (a & 1): #odd
            a = int(a / 2)
        else: # even
            a = a * 3 + 1
            if a > limit:
                return terms
        terms += 1
    return terms

if __name__ == '__main__':
    case_count = 0
    while True:
        case_count += 1
        line = input().strip()
        if not line:
            exit(0)
        a, b = [int(x) for x in line.split()][:2]
        if a == -1:
            exit(0)
        print('Case %d: A = %d, limit = %d, number of terms = %d' % (case_count, a, b, solve(a, b)))
