#!/usr/bin/env python
import datetime
s1 = raw_input()
s2 = raw_input()
d1, m1, y1 = s1.split()
d2, m2, y2 = s2.split()
print abs((datetime.datetime.strptime(y2+''+m2+''+d2, "%Y%m%d").date() - datetime.datetime.strptime(y1+''+m1+''+d1, "%Y%m%d").date()).days)
