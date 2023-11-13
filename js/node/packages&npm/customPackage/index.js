const upperCase = require("upper-case").upperCase

function greet(name){
    console.log(upperCase(`Hello ${name}`))
}

console.log(greet("aditya"))

module.exports = greet;