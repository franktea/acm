"""python get TLE for this one"""

from math import sqrt, floor

class Point:
    def __init__(self, x, y, z):
        self.x, self.y, self.z = x, y, z
        
    def Distance(self, other):
        return sqrt( (self.x - other.x) ** 2 + (self.y - other.y) ** 2 + (self.z - other.z) ** 2)

    def __repr__(self):
        return '({}, {}, {})'.format(self.x, self.y, self.z)

points = []
x, y, z = [int(x) for x in input().split()]
while not ((x == 0) and (y == 0) and (z == 0)):
    points.append(Point(x, y, z))
    x, y, z = [int(x) for x in input().split()]
    
result = [0 for _ in range(10)]
for i in range(len(points)):
    min_distance = None
    for j in range(len(points)):
        if i == j:
            continue
        d = points[i].Distance(points[j])
        if (min_distance is None) or (d < min_distance):
            min_distance = d
            
    if min_distance is not None:
        min_distance = int(floor(min_distance))
        if min_distance < 10:
            result[min_distance] += 1

for i in result:
    print("{:>4d}".format(i), end="")
print()
        