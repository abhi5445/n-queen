// SPDX-License-Identifier: MIT

pragma solidity ^0.8.0;

contract Bank{
    address public add;
    uint256 public balance;

    constructor(){
        add=msg.sender;
    }

    function deposit() public payable{
        require(msg.value>0,"Enter amount greater than 0");
        balance=balance+ msg.value;
    }
    function withdraw() public payable{
        require(msg.value<balance,"insuffiecent balance");
        balance=balance-msg.value;
    }

    function showBalance() public view returns (uint256) {
        return balance;
    }
}
