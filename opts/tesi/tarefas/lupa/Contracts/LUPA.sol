// SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.4.25 <0.6.0;

/**
  @title LUPA: Lowest-Unmatched Price Auction

  This is a first try of an LUPA Smart Contract. More about this kind of auction can be found in:

  Lowest-Unmatched Price Auctions.  Jürgen Eichberger and Dmitri Vinogradov
  https://www.sciencedirect.com/science/article/abs/pii/S0167718715000752

  One limitation of this SC is that everyone can see the bids.
  Once the SC is delivered, one can view its transactions and data using services like https://etherscan.io/.
  We will solve this in the next week...

  By now, you can see that the BidValue struct was poorly designed: the array in bidders is not necessary, as much as the uint value.

  Try to remove these issues and measure the impact on the cost of gas...be carefull!


*/

contract LUPA {
  enum LUPAStates { Bid, Payment, Finished}

  struct BidValue {
    uint value;
    bool isUnmatched;
    address payable[] bidders;
}

  mapping (uint =>  BidValue) bids;
  uint blocklimit;
  LUPAStates myState;
  uint prizeValue;
  address payable owner;


  modifier onlyOwner {
    require (msg.sender == owner,
            "Sorry!");
    _;
  }


  constructor(uint time) payable public {
      blocklimit = block.number + time;
      myState = LUPAStates.Bid;
      prizeValue =msg.value;
      owner = msg.sender;
  }

  function bid() public payable {
    verifyFinished();
    require (myState == LUPAStates.Bid, "Too late!");
    require (msg.value>0,"Dont even try this dirt trick!!!");
    require (msg.value<10e18,"Nope...");
    BidValue storage oneBid = bids[msg.value];
    if (oneBid.value == 0 ) { // Unmatched
        oneBid.value = msg.value;
        oneBid.bidders.push(msg.sender);
        oneBid.isUnmatched=true;
    } else {
      oneBid.bidders.push(msg.sender);
      oneBid.isUnmatched=false;
    }

  }

  function bidWinner() public returns (int) {
    verifyFinished();
    require (myState == LUPAStates.Payment ,"Wait!");
    uint l=0;
    while (l<10e18) {
      BidValue storage oneBid = bids[l];
      if (oneBid.isUnmatched) {
        return int(oneBid.value);
      }
      l+=1;
    }
    return -1;
  }

  function winner(uint w) private returns (address payable) {
    BidValue storage oneBid = bids[w];
    return oneBid.bidders[0];
  }

  function makePayment() public {
    verifyFinished();
    require (myState == LUPAStates.Payment ,"Wait!");
    int widx = bidWinner();
    if (widx>-1) {
      address payable wa = winner(uint(widx));
      wa.transfer(prizeValue);
    }
    owner.transfer(address(this).balance);
    myState = LUPAStates.Finished;
  }


  function finishAuction() public onlyOwner {
    myState = LUPAStates.Payment;
  }

  function verifyFinished() private {
    if (block.number > blocklimit) {
       // myState = LUPAStates.Payment;
      }
    }
}