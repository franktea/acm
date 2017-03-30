"""uva 414 - Machined Surfaces
frank 2017-03-30"""

cases = int(input())
while cases:
    lines = [input() for _ in range(cases)]
    b_count = [line.count(' ') for line in lines]
    print(sum(b_count) - len(lines)*min(b_count))
    cases = int(input())
