
def solve(case_number, word, guess):
    print("Round %d" % case_number)
    char_count = {}
    for w in word:
        if not w in char_count:
            char_count[w] = 0
    error_times = 0
    err_chars = set()
    left_char_count = len(char_count)
    for w in guess:
        if w in char_count:
            if not char_count[w]:
                left_char_count -= 1
                if not left_char_count:
                    print("You win.")
                    return
            char_count[w] += 1
        else:
            if w in err_chars:
                continue
            
            error_times += 1
            err_chars.add(w)
            
            if error_times >= 7:
                print("You lose.")
                return
    
    zero_count = 0
    for v in char_count.values():
        if not v:
            zero_count += 1
    
    if zero_count:
        print("You chickened out.")
    else:
        print("You win.")
        

if __name__ == "__main__":
    while True:
        case_count = int(input())
        if case_count == -1:
            exit(0)
        
        solve(case_count, input(), input())
