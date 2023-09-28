# TESI - Tarefa CoinFlipping

> Guilherme Alves Carvalho - 11921BCC016

## Código

```solidity
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

    // CHANGE 5: Second player must send the same value as the first player
    uint secondPlayerValue;

    // CHANGE 6: unused variable
    // address winner;

    // CHANGE 3: prevent zero value bets
    modifier notZeroValueBet() {
        require(msg.value > 0);
        _;
    }

    // CHANGE 3: prevent zero value bets
    constructor(bytes32 c) public payable notZeroValueBet() {
        firstPlayer.commit(c);
        value = msg.value;
        firstPlayerAddress = msg.sender;
    }

    // CHANGE 1: add modifier to prevent firstPlayerAddress to join the bet again
    modifier onlyDifferentPlayer() {
        require(
            msg.sender != firstPlayerAddress,
            "First player can't bet with himself!"
        );
        _;
    }

    // CHANGE 5: Second player must send the same value as the first player
    modifier mustPayFirstPlayerBetValue() {
        require(
            msg.value == value,
            "You must send the same value as the first player!"
        );
        _;
    }

    // CHANGE 1: add modifier to prevent firstPlayerAddress to join the bet again
    // CHANGE 5: Second player must send the same value as the first player
    function joinBet(
        bytes32 c
    ) public payable onlyDifferentPlayer notZeroValueBet {
        secondPlayer.commit(c);
        secondPlayerValue = msg.value;
        secondPlayerAddress = msg.sender;
    }

    function reveal(bytes1 v, bytes32 nonce) public {
        // CHANGE 4: force both players to reveal their values at the same time (one reveals other's value),
        // prevents one player to wait for the other to reveal and then choose the value
        require(
            msg.sender == firstPlayerAddress ||
                msg.sender == secondPlayerAddress,
            "Betters only!"
        );

        // CHANGE 2: add require to check if both players are waiting before revealing
        require(
            firstPlayer.myState == SimpleCommit.CommitStatesType.Waiting,
            "First Player not ready!"
        );

        // CHANGE 2: add require to check if both players are waiting before revealing
        require(
            secondPlayer.myState == SimpleCommit.CommitStatesType.Waiting,
            "Second Player not ready!"
        );

        firstPlayer.reveal(nonce, v);
        secondPlayer.reveal(nonce, v);
    }

    function pay() public {
        if (firstPlayer.isCorrect() && secondPlayer.isCorrect()) {
            bytes1 v1 = firstPlayer.getValue();
            bytes1 v2 = firstPlayer.getValue();

            // CHANGE 2 side effect: final value is both bets summed
            if (v1 == v2) {
                firstPlayerAddress.transfer(value + secondPlayerValue);
            } else {
                secondPlayerAddress.transfer(value + secondPlayerValue);
            }
        }
    }
}

```
