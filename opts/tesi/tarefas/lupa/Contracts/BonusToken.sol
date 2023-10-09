pragma solidity ^0.6.0;

/**
  @author Ivan da Silva Sendin
  @title BonusToken
  
  This contract aims to manage the extra credits of this course.
  
*/

import "OpenZeppelin/openzeppelin-contracts@3.0.0/contracts/token/ERC20/ERC20.sol";

contract BonusToken is ERC20 {

mapping (address => bool) trustedAddresses;
  address owner;

  modifier onlyOwner {
    require (msg.sender == owner,
            "Sorry!");
    _;
  }

  modifier onlyTrustedAddresses(address a) {
    require ( trustedAddresses[msg.sender] || trustedAddresses[a],
            "This transaction is not allowed!");
    _;
  }


constructor(uint256 initialSupply) public ERC20("BonusToken", "BTK") {
 owner =msg.sender;
        _mint(msg.sender, initialSupply);
}

function addAddress(address a) public onlyOwner {
  trustedAddresses[a] = true;
}

function transfer(address recipient, uint256 amount) public onlyTrustedAddresses(recipient) override returns (bool) {
  return super.transfer(recipient,amount);
}


function getExtraCredit(address student) public view returns (uint256) {
  uint256 b = balanceOf(student);
  if (b<10000) {
    return 0;
  }
  uint256 extra =  (b-10000)/1000;
  if (extra>20) {
    return 20;
  }
  return extra;
 }
}
  























