// SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.4.25 <0.6.0;

/**
  @title Coin Flipping

  This is a simple and full of bugs Smart Contract to handle a coin flipping bet.
  The players are expected to choose 0 or 1. If both choose the same value, player 1 get the pot,
   otherwise player 2 wins.

  In this implementation very few checks are made: the exercise is to deliver a functional and secure smart contract.

  When verifying the honest behavior of participants you should consider:
            - If both are dishonest: the money is locked: the money gets stuck in the contract...forever!
            - If only one is honest: winner!
            - If both are honest: use the games rules do determine the winner

  There are easy fixes...but some are trick.
*/

import "./SimpleCommit.sol";

contract CoinFlipping {

   using SimpleCommit for SimpleCommit.CommitType;

		SimpleCommit.CommitType firstPlayer;
    SimpleCommit.CommitType secondPlayer;
		address payable firstPlayerAddress;
		address payable secondPlayerAddress;
		uint value;
		address winner;

   constructor(bytes32 c) public payable {
     firstPlayer.commit(c);
     value = msg.value;
     firstPlayerAddress = msg.sender;
   }


   function joinBet(bytes32 c) public payable {
      secondPlayer.commit(c);
      secondPlayerAddress = msg.sender;
   }

   function reveal(byte v,bytes32 nonce) public {
     if (msg.sender == firstPlayerAddress) {
       firstPlayer.reveal(nonce,v);
     }
     if (msg.sender == secondPlayerAddress) {
       secondPlayer.reveal(nonce,v);
     }
   }

   function pay() public {
     if (firstPlayer.isCorrect() && secondPlayer.isCorrect()) {
       byte v1 = firstPlayer.getValue();
       byte v2 = firstPlayer.getValue();
       if (v1 == v2) {
         firstPlayerAddress.transfer(2*value);
       } else {
         secondPlayerAddress.transfer(2*value);
       }

     }
   }
}
