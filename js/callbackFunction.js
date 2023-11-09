//  Synchrnous callback functions
function greet(name){
    console.log(`hello ${name}`);
}

function greetSakshi(greetfn){
    const name = "Sakshi Mane";
    greetfn(name);
}

// greet("Aditya")
// greetSakshi(greet)

//  Asynchronious callback functions

let numbers = [4,5,2,1,3,0]
// numbers.sort()
// numbers = numbers.filter(n=>n%2 === 0)
numbers = numbers.map(n=>n/10*10)

console.log(numbers)