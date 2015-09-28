#!/usr/bin/env python
import datetime
s = raw_input()
d, m, y = s.split()
WD = ['L', 'M', 'M', 'J', 'V', 'S', 'D']
print WD[datetime.datetime.strptime(y+''+m+''+d, "%Y%m%d").date().weekday()]
