xxx = """2
7
5
30
169
441
1872
7632
1740
93313
459901
1358657
2504881"""

xxx = [x.strip() for x in xxx.splitlines() if x.strip() != ""]
print ", ".join(xxx)