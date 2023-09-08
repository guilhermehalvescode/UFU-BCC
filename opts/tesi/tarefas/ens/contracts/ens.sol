// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.19;

contract ens {
    address owner;
    mapping(string => mapping(string => address)) public enses;
		mapping(string => mapping(address => string)) public addressesSubdomains;

    constructor() {
        owner = msg.sender;
    }

    modifier onlyOwner() {
        require(msg.sender == owner, "You must be the owner");
        _;
    }


    // registra um "dominio" para msg.sender
    // registerDomain(string newDomain) onlyOwner;
    function registerDomain(string memory newDomain) public onlyOwner {
				string memory addr = string(abi.encodePacked(msg.sender));
        enses[newDomain][addr] = msg.sender;
    }


    // O msg.sender define um par chave-valor em domain
    // setValue("TOPICOS","ivan") faz ENS["TOPICOS"]["ivan"] = msg.sender
    // setValue(string domain, string v) 
		// OBS: should domain owner register the subdomains? this way anyone can register a subdomain
    function setValue(string memory domain, string memory v) public {
        enses[domain][v] = msg.sender;
				addressesSubdomains[domain][msg.sender] = v;
    }


		// getValue("TOPICOS","ivan") retorna  o endereço ADDRESS  quando ENS["TOPICOS"]["ivan"] = ADDRESS
		// getValue(string domain, string v) returns (address)
    function getValue(string memory domain, string memory v) public view returns (address) {
        return enses[domain][v];
    }

		// getValue("TOPICOS") retorna  a string RET quando ENS["TOPICOS"][RET] = msg.sender
		// getValue(string domain) returns (string)
    function getValue(string memory domain) public view returns (string memory) {
        return addressesSubdomains[domain][msg.sender];
    }
}

// deployment: 0x9A4ec17378F5128F62849edF460145667CFb551c