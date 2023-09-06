// SPDX-License-Identifier: UNLICENSED 
pragma solidity ^0.8.19;
/*
// registra um "dominio"
registerDomain(string newDomain) onlyOwner;

// O msg.sender define um par chave-valor em domain
//  setValue("TOPICOS","ivan") faz    ENS["TOPICOS"]["ivan"] = msg.sender
setValue(string domain,string v) 


// getValue("TOPICOS") retorna  a string RET quando ENS["TOPICOS"][RET] = msg.sender
getValue(string domain, address a) returns (string)


// getValue("TOPICOS","ivan" ) retorna  o endereço ADDRESS  quando ENS["TOPICOS"]["ivan"] = ADDRESS
getValue(string domain, string v) returns (address)
*/

contract ens {
  mapping ( string => mapping( string => address ) ) public enses;

  function registerDomain(string newDomain) public onlyOwner {
    
  }

  function setValue(string domain, string v) public {
    enses[domain][v] = msg.sender;
  }


  function getValue(string domain) public returns (string) {
    return enses[domain][msg.sender];
  }
    
  function getValue(string domain, string v) public returns (address) {
    return enses[domain][v];
  }

}