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
        ERC20 thisT;
        ERC20 otherT;
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
        require(msg.sender == pools[name].owner, "Only pool owner can call this function!")
        _;
    }

    modifier poolNotExists(string memory name) {
        require(pools[name].owner == address(0), "This pool already exists!");
        _;
    }

    modifier poolExists(string memory name) {
        require(pools[name].owner != address(0), "This pool doesn't exist!");
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
        token.transfer(msg.sender, token.balanceOf(address(this)));
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
        ERC20 thisT,
        ERC20 otherT
    ) public validTax(tax) {
        Pool memory p = getPool(name);
        p.owner = msg.sender;
        p.tax = tax;
        p.thisT = thisT;
        p.otherT = otherT;
    }

    function createPool(
        string memory name,
        uint tax,
        ERC20 thisT,
        ERC20 otherT
    )
        public
        poolNotExists(name)
        tokenHasAllowance(thisT)
        tokenHasAllowance(otherT)
    {
        receiveToken(thisT);

        receiveToken(otherT);

        setPool(name, tax, thisT, otherT);
    }

    function retrievePool(string memory name) public onlyPoolOwner(name) {
        Pool storage p = getPool(name);

        sendToken(p.thisT);

        sendToken(p.otherT);

        delete pools[name];
    }

    // function getTransactionAmmount(ERC20 thisT, ERC20 otherT) {
    //     uint256 thisTAmmount = thisT.allowance(msg.sender, address(this));
    //     uint256 thisTBalance = thisT.balanceOf(address(this));
    //     uint256 otherTBalance = otherT.balanceOf(address(this));

    //     uint256 otherTAmmount = (otherTBalance * thisTAmmount) /
    //         (thisTBalance + thisTAmmount);

    //     return otherTAmmount;

    // }

    // buy Other token using This token
    function buy(
        string memory name
    ) public poolExists(name) tokenHasAllowance(pools[name].thisT) {
        Pool storage p = getPool(name);

        uint256 thisTAmmount = p.thisT.allowance(msg.sender, address(this));
        uint256 thisTBalance = p.thisT.balanceOf(address(this));
        uint256 otherTBalance = p.otherT.balanceOf(address(this));

        uint256 otherTAmmount = (otherTBalance * thisTAmmount) /
            (thisTBalance + thisTAmmount);

        p.thisT.transferFrom(msg.sender, address(this), thisTAmmount);
        p.otherT.transfer(msg.sender, otherTAmmount);
    }

    function sell(
        string memory name
    ) public poolExists(name) tokenHasAllowance(pools[name].otherT) {
        Pool storage p = getPool(name);

        uint256 otherTAmmount = p.otherT.allowance(msg.sender, address(this));
        uint256 otherTBalance = p.otherT.balanceOf(address(this));
        uint256 thisTBalance = p.thisT.balanceOf(address(this));

        uint256 thisTAmmount = (thisTBalance * otherTAmmount) /
            (otherTBalance + otherTAmmount);

        p.otherT.transferFrom(msg.sender, address(this), otherTAmmount);
        p.thisT.transfer(msg.sender, thisTAmmount);
    }
}
