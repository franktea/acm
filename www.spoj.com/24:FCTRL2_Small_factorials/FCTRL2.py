import sys

result = { 1:1 };

def solve(a):
	if(result.has_key(a)):
		return result[a]
	r = a * solve(a-1)
	result[a] = r
	return r

count = int(sys.stdin.readline())
for i in range(count):
	a = int(sys.stdin.readline())
	print solve(a)