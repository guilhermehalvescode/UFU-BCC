pragma solidity ^0.6.0;

import "./BonusToken.sol";

contract allPayAuctionCumulativeBid {

  enum AuctionState {Pre, Bid,Pay,Finished}

  mapping (address => uint256) bids;
  address owner;
  address winner;
  uint256 winnerValue;

  AuctionState myState;

  uint256 auctionValue;

  uint256 timeLimit;

  BonusToken bt;
  bool pay;

  constructor(BonusToken _bt) public {
    bt = _bt;
    myState = AuctionState.Pre;
    timeLimit = 0;
    owner = msg.sender;
    pay = false;
    myState = AuctionState.Pre;
  }

  function init() public {
    require (myState == AuctionState.Pre , "Not in the Pre state!");
    require (msg.sender == owner ,"Only owner!");
    auctionValue = bt.balanceOf(address(this));
    myState = AuctionState.Bid;
  }


  function doBid() public {
    verifyFinished();
    require (myState == AuctionState.Bid , "Not in the Bid state!");
    require (bt.allowance(msg.sender,address(this))>0,"Show me the token!");
    uint256 bidValue = bt.allowance(msg.sender,address(this));
    bt.transferFrom(msg.sender,address(this),bidValue);

    if (timeLimit == 0) {
      timeLimit = block.timestamp + 5 days;
    }

    bids[msg.sender] = bids[msg.sender] + bidValue;

    if ( bids[msg.sender]>winnerValue) {
      winner = msg.sender;
      winnerValue = bids[msg.sender];
    }
  }


  function payWinner() public {
    verifyFinished();
    require (myState == AuctionState.Pay, "Not in the Pay state!");
    require (pay==false, "Already paid!");
    bt.transfer(winner,auctionValue);
    bt.transfer(owner, bt.balanceOf(address(this)));
    pay =  true;
    myState = AuctionState.Finished;
  }


  function getAuctionValue() public view returns (uint256) {
    return auctionValue;
  }

  function getCurrentBid() public view returns (uint256) {
    return winnerValue;
  }

  function remainingTime() public view returns (uint256) {
    return timeLimit - block.timestamp;
  }

  function verifyFinished() private  {
    if (timeLimit>0 && block.timestamp > timeLimit) {
      myState = AuctionState.Pay;
    }
  }
}
