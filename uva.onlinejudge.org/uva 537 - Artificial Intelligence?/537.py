
import re

r = re.compile(r'(?P<name>([UPI]))=(?P<value>[\-]?[0-9\.]+)(?P<suffix>[mkM]?)')

suffix_values = {None: 1, 'm': 0.001, 'k': 1000, 'M': 1000000}

class Solver:
    def __init__(self):
        self.P, self.U, self.I = None, None, None
    
    def Calc(self):
        if self.P is None:
            print('P={:.2f}W'.format(self.U * self.I))
        elif self.U is None:
            print('U={:.2f}V'.format(self.P / self.I))
        else:
            print('I={:.2f}A'.format(self.P / self.U))
        print()

case_count = int(input())
for i in range(case_count):
    print("Problem #{}".format(i+1))
    line = input()
    s = Solver()
    for it in r.finditer(line):
        name = it.group('name')
        value = float(it.group('value'))
        if it.group('suffix'):
            value = value * suffix_values[it.group('suffix')]
        setattr(s, name, value)
    s.Calc()
