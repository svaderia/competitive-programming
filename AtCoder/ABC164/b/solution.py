[a, b, c, d] = [int(x) for x in input().split()]

who = 1
while(a > 0 and c > 0):
  if(who == 0):
    a -= d
  else:
    c -= b
  who = 1 - who

if(who == 0):
  print("Yes")
else:
  print("No")
