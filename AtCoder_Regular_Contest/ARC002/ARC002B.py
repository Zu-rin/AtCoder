import datetime

def Judge(date):
    if(date.year % (date.month * date.day) == 0):
        return True
    else:
        return False

s = input()
date = datetime.datetime.strptime(s, "%Y/%m/%d")
while(Judge(date) == False):
    date += datetime.timedelta(days=1)
print(date.strftime("%Y/%m/%d"))