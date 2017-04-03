
class MasterHints:
    def __init__(self, secret):
        self.secret = secret
    
    def Guess(self, guess):
        strong = 0
        weak = 0
        used_secret = [0 for _ in range(len(self.secret))]
        used_guess = [0 for _ in range(len(self.secret))]
        
        for i in range(len(self.secret)):
            if self.secret[i] == guess[i]:
                used_secret[i] = 1
                used_guess[i] = 1
                strong += 1
        
        for i in range(len(guess)):
            if not used_guess[i]:
                for j in range(len(self.secret)):
                    if (i != j) and (not used_secret[j]) and (guess[i] == self.secret[j]):
                        #print("i={}, j={}".format(i, j))
                        used_secret[j] = 1
                        weak += 1
                        break
                        
        print("    ({},{})".format(strong, weak))
        

case_index = 0
length = int(input())
while length:
    case_index += 1
    secret = [int(x) for x in input().split()]
    print("Game {}:".format(case_index))
    mh = MasterHints(secret)
    guess = [int(x) for x in input().split()]
    while sum(guess):
        mh.Guess(guess)
        guess = [int(x) for x in input().split()]
    
    length = int(input())
    
