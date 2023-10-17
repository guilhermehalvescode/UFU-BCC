// SPDX-License-Identifier: MIT
pragma solidity ^0.6.0;

/**
  @title sillyERC20

  This is a naive ERC20 implementation of

  https://raw.githubusercontent.com/OpenZeppelin/openzeppelin-contracts/v3.0.0/contracts/token/ERC20/IERC20.sol.

  You can finde the bugs by yourself or you can use tools like Echdna .
*/

import "./IERC20.sol";

contract ERC20 is IERC20 {
    uint256 public tokenSupply;
    mapping(address => uint256) public balance;

    mapping(address => uint256) public totalAllowance;
    mapping(address => mapping(address => uint256)) public allowances;

    string public name;
    string public symbol;
    uint8 public decimals = 3;

    constructor (string memory tokenName, string memory tokenSymbol, uint256 initialSupply) public  {
      name=tokenName;
      symbol=tokenSymbol;
      tokenSupply = initialSupply;
      balance[msg.sender] = initialSupply;
    }


    function transfer(address recipient, uint256 amount) external  override returns (bool) {
        if (balance[msg.sender]<amount) {
          return false;
        }
        balance[msg.sender] -= amount;
        balance[recipient] += amount;
        emit Transfer(msg.sender, recipient, amount);
        return true;
    }

    function approve(address spender, uint amount) external  override returns (bool) {
        if (balance[msg.sender] - totalAllowance[msg.sender]<amount) {
          return false;
        }
        allowances[msg.sender][spender] = amount;
        totalAllowance[msg.sender] +=amount;
        emit Approval(msg.sender, spender, amount);
        return true;
    }

    function transferFrom(address sender,address recipient,uint amount) external  override returns (bool) {
        totalAllowance[msg.sender] -= amount;
        allowances[sender][msg.sender] -= amount;
        balance[sender] -= amount;
        balance[recipient] += amount;
        emit Transfer(sender, recipient, amount);
        return true;
    }

    function totalSupply() external view  override  returns (uint256) {
      return tokenSupply;
    }

    function balanceOf(address account) external view  override  returns (uint256) {
      return balance[account];
    }

    function allowance(address owner, address spender) external view override returns (uint256) {
      return allowances[owner][spender];
    }

}
