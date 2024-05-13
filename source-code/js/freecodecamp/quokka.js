//Dont mind the mess here

var num = 9
num = "6"

let name = "Aditya"
const time = 5
// time = "Five 30"

const code = {
    isAwesome: true
}

var undef;
var s=5/5

a=10

str = "This is a \"Quote\" inside a string"

// code

// console.log(typeof(num))

// console.log(num === 6)

// num
// undef

// s

str = "Hiya"

myArr = [["Sakshi mane", "sonchafa"], ["Aditya godse", "Eugine"]]
myArr.push(["Jaydeep", "Dr J"])
myArr.shift()                //Removes first element
myArr.unshift(["Prajyot","Friend"])
// console.log(myArr.slice(-1)[0] )
// console.log(myArr[0])




function printhello(name){
    console.log("Hello " + name)
}

// printhello("Sakshi")




expression = "hen"
// switch(expression){
//     case "dog":
//         console.log("Bark")
//         break
//     case "cat":
//         console.log("Meow")
//         break

//     default:
//         console.log("Undefined animal")
//         break
// }


try {
    throw new error()
    console.log("Works")
}catch{
    console.log("Broke")
}finally{
    console.log("Always work")
}


function outer(){
    val = 7
    function inner(){
        console.log(val)
    }
}