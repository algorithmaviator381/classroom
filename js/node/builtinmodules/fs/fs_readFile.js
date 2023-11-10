const fs = require("node:fs")

//  fs module internally uses buffer

const FileContent = fs.readFileSync("./captivePortal.txt", "utf-8")

// console.log(FileContent)

//  fs.readFile will continue reading the file until the file is being read, the further code is 
//  executed
fs.readFile("./captivePortal.txt", "utf-8", (error, data) => {
    if(error){
        console.log(error);
    }else{
        console.log(data);
    }
})

console.log("This line is written after fs.readFile function, but this line executes before the fs.readFile function because fs module internally uses buffer")