const { error } = require('node:console')
const fs = require('node:fs/promises')

fs.readFile("./captivePortal.txt", "utf-8")
    .then(data => console.log(data))
    .catch(error => console.log(error))


async function readFile(file){
    try{
        const data = await fs.readFile(file, "utf-8")
        console.log(data)
    }catch(err){
        console.log(err)
    }
}

readFile("./greet.txt")