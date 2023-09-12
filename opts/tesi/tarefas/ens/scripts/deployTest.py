from brownie import *
from brownie import accounts, Contract


network.connect('sepolia')

contractAddress = "0x9A4ec17378F5128F62849edF460145667CFb551c"

ct = Contract.from_explorer(contractAddress)

print(ct)
