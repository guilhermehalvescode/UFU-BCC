// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

import "@openzeppelin/contracts/token/ERC20/IERC20.sol";
import "@openzeppelin/contracts/access/Ownable.sol";

contract DAO is Ownable {
    IERC20 public token;

    uint120 public votingLimit;
    uint120 public quorumMinimumPercentage;
    uint120 public numberOfProposals;

    enum ProposalStatus {
        Pending,
        Approved,
        Rejected,
        Executed
    }

    struct Proposal {
        uint256 id;
        address proposer;
        ProposalStatus status;
        uint256 votesFor;
        uint256 votesAgainst;
        address contractToExecute;
        uint256 rewardAmount;
        mapping(address => bool) hasVoted;
    }

    mapping(uint256 => Proposal) public proposals;

    // Modifiers
    modifier onlyTokenHolder() {
        require(
            token.balanceOf(msg.sender) > 0,
            "Must hold ERC20 tokens to submit"
        );
        _;
    }

    modifier proposalExists(uint256 _proposalId) {
        require(
            proposals[_proposalId].proposer != address(0),
            "Proposal doesn't exist"
        );
        _;
    }

    modifier proposalPending(uint256 _proposalId) {
        require(
            proposals[_proposalId].status == ProposalStatus.Pending,
            "Proposal must be pending to vote"
        );
        _;
    }

    modifier notVotedYet(uint256 _proposalId) {
        require(
            !proposals[_proposalId].hasVoted[msg.sender],
            "You already voted in this proposal"
        );
        _;
    }

    modifier votingFinished(uint256 _proposalId) {
        require(
            block.timestamp > proposals[_proposalId].statusTime + votingLimit,
            "Voting is still runing"
        );
        _;
    }

    constructor(
        address _token,
        uint256 _votingLimit,
        uint256 _quorumMinimumPercentage
    ) {
        token = IERC20(_token);
        votingLimit = _votingLimit;
        quorumMinimumPercentage = _quorumMinimumPercentage;
    }

    function registerProposal(
        address _contractToExecute,
        uint256 _rewardAmount
    ) external onlyTokenHolder returns (uint256) {
        Proposal storage proposal = proposals[numberOfProposals];
        proposal.id = numberOfProposals;
        numberOfProposals++;
        proposal.proposer = msg.sender;
        proposal.status = ProposalStatus.Pending;
        proposal.contractToExecute = _contractToExecute;
        proposal.rewardAmount = _rewardAmount;

        return proposal.id;
    }

    function vote(
        uint256 _proposalId,
        bool _support
    )
        external
        proposalExists(_proposalId)
        proposalPending(_proposalId)
        notVotedYet(_proposalId)
    {
        Proposal storage proposal = proposals[_proposalId];
        proposal.hasVoted[msg.sender] = true;

        if (_support) {
            proposal.votesFor += token.balanceOf(msg.sender);
        } else {
            proposal.votesAgainst += token.balanceOf(msg.sender);
        }

        if (block.timestamp > proposal.statusTime + votingLimit) {
            callProposal(_proposalId);
        }
    }

    function callProposal(
        uint256 _proposalId
    )
        internal
        proposalExists(_proposalId)
        proposalPending(_proposalId)
        votingFinished(_proposalId)
    {
        Proposal storage proposal = proposals[_proposalId];

        uint256 totalVotes = proposal.votesFor + proposal.votesAgainst;
        uint256 quorum = (totalVotes * quorumMinimumPercentage) / 100;

        if (proposal.votesFor > quorum) {
            proposal.status = ProposalStatus.Approved;
            require(
                proposal.contractToExecute.call(
                    abi.encodeWithSignature("execute(uint256)", _proposalId)
                ),
                "Execution failed"
            );

            proposal.status = ProposalStatus.Executed;
            if (proposal.rewardAmount > 0) {
                token.transfer(proposal.proposer, proposal.rewardAmount);
            }
        } else {
            proposal.status = ProposalStatus.Rejected;
        }
    }
}
