
try:
    case_count = int(input())
    for _ in range(case_count):
        num_count = int(input())
        numbers = [int(x) for x in input().split()]
        numbers.sort()
        print( (numbers[-1] - numbers[0]) * 2 )
except(EOFError):
    pass