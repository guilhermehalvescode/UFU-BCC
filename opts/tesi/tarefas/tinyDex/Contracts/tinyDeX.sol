pragma solidity ^0.6.0;

/**
  @title tinyDeX

  This is a minimal DeX contract.
  Your tasks:
  1) Collect a tax for contract and pool owner from each transaction
  2) Implement the pool withdraw (onlyOwner)
  3) A parameter setting a minimal amount of tokens received on transaction (use require)

WARNING: There is a hidden bug that you will only notice when there is more than one pool.
*/

import "OpenZeppelin/openzeppelin-contracts@3.0.0/contracts/token/ERC20/ERC20.sol";

contract tinyDeX {
    address owner;

    struct PoolType {
        address poolOwner;
        ERC20 x;
        ERC20 y;
    }

    mapping(string => PoolType) pools;

    constructor() public {
        owner = msg.sender;
    }

    function createPool(string memory name, ERC20 x, ERC20 y) public {
        require(
            pools[name].poolOwner == address(0),
            "This pool already exists!"
        );
        require(
            x.allowance(msg.sender, address(this)) > 0,
            "Show me the token!"
        );
        require(
            y.allowance(msg.sender, address(this)) > 0,
            "Show me the token!"
        );

        x.transferFrom(
            msg.sender,
            address(this),
            x.allowance(msg.sender, address(this))
        );
        y.transferFrom(
            msg.sender,
            address(this),
            y.allowance(msg.sender, address(this))
        );

        pools[name].poolOwner = msg.sender;
        pools[name].x = x;
        pools[name].y = y;
    }

    // buy y token using x token
    function buy(string memory name) public {
        require(pools[name].poolOwner != address(0), "This pool doesnt exist!");
        require(
            pools[name].x.allowance(msg.sender, address(this)) > 0,
            "Show me the token!"
        );
        uint256 xammount = pools[name].x.allowance(msg.sender, address(this));
        uint256 xbalance = pools[name].x.balanceOf(address(this));
        uint256 ybalance = pools[name].y.balanceOf(address(this));

        uint256 yammount = (ybalance * xammount) / (xbalance + xammount);

        pools[name].x.transferFrom(msg.sender, address(this), xammount);
        pools[name].y.transfer(msg.sender, yammount);
    }

    function sell(string memory name) public {
        require(pools[name].poolOwner != address(0), "This pool doesnt exist!");
        require(
            pools[name].y.allowance(msg.sender, address(this)) > 0,
            "Show me the token!"
        );
        uint256 yammount = pools[name].y.allowance(msg.sender, address(this));
        uint256 ybalance = pools[name].y.balanceOf(address(this));
        uint256 xbalance = pools[name].x.balanceOf(address(this));

        uint256 xammount = (xbalance * yammount) / (ybalance + yammount);

        pools[name].y.transferFrom(msg.sender, address(this), yammount);
        pools[name].x.transfer(msg.sender, xammount);
    }
}
