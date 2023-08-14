import hashlib

mined = False

pre = "7;GUILHERMEALVESCARVALHO;0001972f0b558a30b076e6e72139c8509223d171ea0685b2ccd5b7d1cde0d80a;"
nonce = 0
h = ''
temp = ''

while not mined:
  temp = pre + str(nonce)
  h = hashlib.sha256(temp.encode()).hexdigest()
  if h[:3] == '000':
    mined = True
  nonce += 1


print(temp)
print(h)
