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
    uint tax;

    struct Pool {
        address owner;
        uint tax;
        ERC20 theToken;
        ERC20 otherToken;
    }

    mapping(string => Pool) pools;

    modifier validTax(uint tax) {
        require(tax >= 0 && tax <= 100, "Tax must be between 0 and 100!");
        _;
    }

    constructor(uint tax) public validTax(tax) {
        owner = msg.sender;
        tax = tax;
    }

    modifier onlyOwner() {
        require(msg.sender == owner, "Only owner can call this function!");
        _;
    }
    
    modifier onlyPoolOwner(string memory name) {
        require(msg.sender == getPool(name).owner, "Only pool owner can call this function!")
        _;
    }

    modifier poolNotExists(string memory name) {
        require(getPool(name).owner == address(0), "This pool already exists!");
        _;
    }

    modifier poolExists(string memory name) {
        require(getPool(name).owner != address(0), "This pool doesn't exist!");
        _;
    }

    modifier tokenHasAllowance(ERC20 token) {
        require(
            token.allowance(msg.sender, address(this)) > 0,
            "Show me the token!"
        );
        _;
    }

    function receiveToken(ERC20 token) private {
        token.transferFrom(
            msg.sender,
            address(this),
            token.allowance(msg.sender, address(this))
        );
    }

    function sendToken(ERC20 token) private {
        token.transferFrom(
            address(this),
            msg.sender,
            token.allowance(address(this), msg.sender)
        );
    }

    function getPool(string memory name) public view returns (Pool memory) {
        return pools[name];
    }

    function setPool(
        string memory name,
        uint memory tax,
        ERC20 theToken,
        ERC20 otherToken
    ) private validTax(tax) {
        Pool memory p = getPool(name);
        p.owner = msg.sender;
        p.tax = tax;
        p.theToken = theToken;
        p.otherToken = otherToken;
    }

    function payAddress(address addr, ERC20 token, uint tax) private {
        taxValue = token.allowance(msg.sender, addr) * (tax / 100);

        token.transferFrom(
            msg.sender,
            addr,
            taxValue
        );
    }

    function createPool(
        string memory name,
        uint tax,
        ERC20 theToken,
        ERC20 otherToken
    )
        public
        poolNotExists(name)
        tokenHasAllowance(theToken)
        tokenHasAllowance(otherToken)
    {
        receiveToken(theToken);

        receiveToken(otherToken);

        setPool(name, tax, theToken, otherToken);
    }

    function retrievePool(string memory name) public onlyPoolOwner(name) {
        Pool storage p = getPool(name);

        sendToken(p.theToken);

        sendToken(p.otherToken);

        delete getPool(name);
    }

    function getBalanceOf(ECR20 token ,address addr) private {
        return token.balanceOf(addr);
    }

    function getAllowanceFrom(ERC20 token, address from, address to) private {
        return token.allowance(from, to);
    }

    function transaction(ECR20 buyerToken, ERC20 sellerToken, address buyer, address seller) private {

        uint256 buyerTokenAmmount = getAllowanceFrom(buyerToken, buyer, seller);

        payAddress(seller, buyerToken, tax);
        payAddress(poolOwner, buyerToken, poolTax);

        taxesValue = (buyerTokenAmmount * tax) / 100 + (buyerTokenAmmount * poolTax) / 100;

        buyerTokenAmmount = buyerTokenAmmount - taxesValue;

        uint256 buyerTokenBalance = getBalanceOf(buyerToken, buyer);
        uint256 sellerTokenBalance = getBalanceOf(sellerToken, buyer);

        uint256 sellerTokenAmmount = (sellerTokenBalance * buyerTokenAmmount) /
            (buyerTokenBalance + buyerTokenAmmount);

        buyerToken.transferFrom(buyer, seller, buyerTokenAmmount);
        sellerToken.transferFrom(seller, buyer, sellerTokenAmmount);
    }

    // buy Other token using This token
    function buy(
        string memory name
    ) public poolExists(name) tokenHasAllowance(pools[name].theToken) {
        Pool storage p = getPool(name);

        address contractAddress = address(this);

        ERC20 fromToken = p.theToken;
        ERC20 toToken = p.otherToken;

        transaction(fromToken, toToken, msg.sender, contractAddress);
    }

    function sell(
        string memory name
    ) public poolExists(name) tokenHasAllowance(pools[name].otherToken) {
        Pool storage p = getPool(name);

        address contractAddress = address(this);

        ERC20 fromToken = p.otherToken;
        ERC20 toToken = p.theToken;

        transaction(fromToken, toToken, contractAddress, msg.sender);
    }
}
