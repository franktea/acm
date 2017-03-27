"""uva 10161 - Ant on a Chessboard
frank"""

import math

def solve(number):
    round = int(math.sqrt(number))
    round = round + 1 if round**2 < number else round
    if round == 1:
        print(1, 1)
        return
    mid_number = (round-1)**2 + round
    if not (round % 2): # even
        if number < mid_number:
            print(round - (mid_number - number), round)
        else:
            print(round, round - (number - mid_number))
    else: #odd
        if number < mid_number:
            print(round, round - (mid_number - number))
        else:
            print(round - (number - mid_number), round)        
        
    
if __name__ == "__main__":
    while True:
        try:
            number = input()
            if int(number) == 0:
                break
            solve(int(number))
        except(EOFError):
            break

