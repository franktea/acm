
def solve(lines):
    lines.sort()
    for i in range(len(lines)-1):
        for j in range(i+1, len(lines)):
            if lines[j].startswith(lines[i]):
                return False
    return True

if __name__ == '__main__':
    try:
        case_count = 0
        while True:
            lines = []
            case_count += 1
            while True:
                line = input().strip()
                if not line:
                    exit(0)
                elif line == "9":
                    if lines:
                        if solve(lines):
                            print('Set %d is immediately decodable' % case_count)
                        else:
                            print('Set %d is not immediately decodable' % case_count)
                    break
                else:
                    lines.append(line)
            pass
    except(EOFError):
        exit(0)