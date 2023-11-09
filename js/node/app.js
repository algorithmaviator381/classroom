// require("./modules/batman.js")
// require("./modules/superman.js")

const superhero = require("./super-hero")
const sum = require('./modules/arithmatic');
const math = require("./modules/math")

const {add, subtract, prod} = math

// console.log('Hello from app.js')
// console.log(sum(5,4))

// hero1 = new superhero("Spiderman")
// console.log(hero1.getName())
// hero1.setName("Peter Parker")
// console.log(hero1.getName())

// hero2 = new superhero("Batman")
// console.log(hero2.getName())
// hero2.setName("Bruce Wayne")
// console.log(hero2.getName())


console.log(math.add(5,7), add(5,7))
console.log(math.subtract(5,7), subtract(5,7))
console.log(math.prod(5,7), prod(5,7))

console.log("Beta feature")
