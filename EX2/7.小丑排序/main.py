index = 1
while(1):
  n = eval(input())
  
  if n == 0:exit()
  print(f'set-{index}')
  index+=1
  list = []
  list2 = []
  for i in range(n):
    list.append(input())
  list2 = list[1: :2]
  list2.reverse()
  list3 = list[0: :2]
  list = list3 + list2
  for i in list:
    print(i)

