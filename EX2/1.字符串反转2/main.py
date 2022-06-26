s = ''
s = input()
while(s):
  res = s.split(' ')
  res.reverse()
  print(' '.join(res))
  try:
    s = input()
  except:
    exit()
