//  In node we rely on fs module to read file sytsem
const fs = require("node:fs")

//  write file has both synchrnous and asynchrnous features

// Synchrnous
fs.writeFileSync("./greet.txt", "Hello")

// fs.writeFileSync("./greet.txt", " Sakshi Mane", {flag:'a'})

//  Asynchrnous function
//  flag: {'a'}
//      - Appends the content to the file
fs.writeFile("./greet.txt", " Sakshi Mane", {flag : 'a'}, (err) => {
    if(err){
        console.log(err)
    }else{
        console.log("File has been written, file content below:")
        console.log(fs.readFileSync("./greet.txt", "utf-8"))
    }
})

const FileContent = fs.readFileSync("./greet.txt", "utf-8")
console.log(FileContent)