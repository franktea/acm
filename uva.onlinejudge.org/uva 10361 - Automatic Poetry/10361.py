
import re

r = re.compile(r"^(?P<s1>[\w ]*)\<(?P<s2>[\w ]*)\>(?P<s3>[\w ]*)\<(?P<s4>[\w ]*)\>(?P<s5>\w*)$")

def solve(string1, string2):
    result = r.match(string1)
    print(''.join([c for c in string1 if c not in ['<', '>']]))
    subs2 = ''.join([result.group('s4'), result.group('s3'), result.group('s2'), result.group('s5')])
    print(string2.replace("...", subs2))

cases = int(input())
for i in range(cases):
    solve(input(), input())