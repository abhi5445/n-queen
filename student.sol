
// SPDX-License-Identifier: MIT

pragma solidity ^0.8.0;

contract StudentData {
    struct Student {
        uint id;
        string name;
        uint age;
        address studentAddress;
    }

    address public owner;
    Student[] public students;

    event StudentAdded(uint id, string name, uint age, address studentAddress);

    constructor() {
        owner = msg.sender;
    }

    function addStudent(uint _id, string memory _name, uint _age, address _address) public {
        students.push(Student(_id, _name, _age, _address));
        emit StudentAdded(_id, _name, _age, _address);
    }

    function getStudent(uint _index) public view returns (uint, string memory, uint, address) {
        Student storage student = students[_index];
        return (student.id, student.name, student.age, student.studentAddress);
    }

    fallback() external payable {
        payable(owner).transfer(address(this).balance);
    }

    receive() external payable {}
}
