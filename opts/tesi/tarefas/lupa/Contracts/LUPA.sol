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

import "./SimpleCommit.sol";

contract LUPA {
    using SimpleCommit for SimpleCommit.CommitType;

    enum LUPAStates {
        Bid,
        Payment,
        Finished
    }

    struct BidValue {
        uint value;
        bool isUnmatched;
        uint newCommitIndex;
        address payable[] bidders;
        // for commit strategy
        SimpleCommit.CommitType[] commits;
    }

    mapping(uint => BidValue) bids;
    uint blocklimit;
    LUPAStates myState;
    uint prizeValue;
    address payable owner;

    modifier requireOnlyOwner() {
        require(msg.sender == owner, "Sorry!");
        _;
    }

    function finishAuction() public requireOnlyOwner {
        myState = LUPAStates.Payment;
    }

    // turn function requireFinished to modifier: it was being called at the start of all callers
    modifier finishBidIfLimit() {
        if (block.number > blocklimit) {
            finishAuction();
        }
        _;
    }

    modifier requireInitiated() {
        require(myState == LUPAStates.Bid, "Too late!");
        _;
    }

    modifier requireForPayment() {
        require(myState == LUPAStates.Payment, "Wait!");
        _;
    }

    modifier requireValueValid(uint value) {
        require(value > 0 && value < 10e18, "Dont even try this dirt trick!!!");
        _;
    }

    constructor(uint time) public payable {
        blocklimit = block.number + time;
        myState = LUPAStates.Bid;
        prizeValue = msg.value;
        owner = msg.sender;
    }

    function bid(
        bytes32 c
    ) public payable requireInitiated requireValueValid(msg.value) {
        BidValue storage oneBid = bids[msg.value];

        if (oneBid.value == 0) {
            // Unmatched
            oneBid.value = msg.value;
            oneBid.isUnmatched = true;
        } else {
            oneBid.isUnmatched = false;
        }

        oneBid.commits[oneBid.newCommitIndex].commit(c);
        oneBid.bidders.push(msg.sender);
        oneBid.newCommitIndex += 1;
    }

    function findBidWinnerIndex() private view requireForPayment returns (int) {
        uint l = 0;
        while (l < 10e18) {
            BidValue storage oneBid = bids[l];
            if (oneBid.isUnmatched) {
                return int(l);
            }
            l += 1;
        }
        return -1;
    }

    function getBidsFirstBid(uint w) private returns (address payable) {
        BidValue storage oneBid = bids[w];

        bytes32 nonce = oneBid.commits[0].commited;
        oneBid.commits[0].reveal(nonce, 0);

        require(oneBid.commits[0].isCorrect(), "Wrong bid!");
        return oneBid.bidders[0];
    }

    function makePayment() public finishBidIfLimit {
        int widx = findBidWinnerIndex();
        if (widx > -1) {
            address payable wa = getBidsFirstBid(uint(widx));
            wa.transfer(prizeValue);
        }
        owner.transfer(address(this).balance);
        myState = LUPAStates.Finished;
    }
}
