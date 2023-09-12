from brownie import *
from brownie import ens, accounts

def main():
    acc = accounts[0]
    contract = ens.deploy({'from': acc})
    print(f'Deployer address {acc.address}')

    # testing registerDomain(newDomain)
    contract.registerDomain('google', {'from': acc})
    contract.registerDomain('facebook', {'from': acc})
    contract.registerDomain('twitter', {'from': acc})
    contract.registerDomain('instagram', {'from': acc})

    # testing setValue(domain, v)
    contract.setValue('google', 'docs', {'from': acc})
    contract.setValue('facebook', 'messenger', {'from': acc})
    contract.setValue('twitter', 'api', {'from': acc})
    contract.setValue('instagram', 'api', {'from': acc})

    # testing getValue(domain)
    g = contract.getValue('google')
    f = contract.getValue('facebook')
    t = contract.getValue('twitter')
    i = contract.getValue('instagram')

    print(g)
    print(f)
    print(t)
    print(i)

    # getValue(domain, v)
    gd = contract.getValue('google', 'docs')
    fm = contract.getValue('facebook', 'messenger')
    ta = contract.getValue('twitter', 'api')
    ia = contract.getValue('instagram', 'api')

    print(gd)
    print(fm)
    print(ta)
    print(ia)
