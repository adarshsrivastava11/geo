string = []
while True:
  try:
    j = raw_input().split()[1]
    if not j[0].isdigit() and not(j>='A' and j<='Z') and not len(j)==1: 
      string.append(j)
      string.append("|")
  except EOFError:
    break
print "".join(string)
