// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.19;

contract VotaEns {
    address owner;

    bool public isVoting = false;
    mapping(address => uint) public addressesVotingCounter;
    mapping(address => bool) public isDefinedAddress;
    address[] public addresses;

    constructor() {
        owner = msg.sender;
    }

    modifier onlyOwner() {
        require(msg.sender == owner, "Only owner can call this function");
        _;
    }

    modifier isVotingOpen() {
        require(isVoting, "Voting is closed");
        _;
    }

    modifier isValidAddress(address addr) {
        require(isDefinedAddress[addr], "Address not defined");
        _;
    }

    function addEnsAddress(address addr) public onlyOwner {
        addressesVotingCounter[addr] = 0;
        isDefinedAddress[addr] = true;
        addresses.push(addr);
    }

    function startVoting() public onlyOwner {
        isVoting = true;
    }

    function getWinner() public view onlyOwner returns (address) {
        uint max = 0;
        address winner;

        for (uint i = 0; i < addresses.length; i++) {
            address addr = addresses[i];

            if (addressesVotingCounter[addr] > max) {
                max = addressesVotingCounter[addr];
                winner = addr;
            }
        }

        return winner;
    }

    function stopVoting() public onlyOwner returns (address) {
        isVoting = false;

        return getWinner();
    }

    function vote(address addr) public isVotingOpen isValidAddress(addr) {
        addressesVotingCounter[addr] += 1;
    }

    function getVotes(address addr) public view returns (uint) {
        return addressesVotingCounter[addr];
    }
}
