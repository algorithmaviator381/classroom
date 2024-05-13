//  Allows us to work with chunks of data rather than larger amount ot data at the same time

//  Streams are the streams of data that is being moved from one point to another
//  Ex. Data that is being transferred from one computer to another in same computer
//  Works with data in chunks insteed of entire data to be avaliable at once

// while moving A to B we dont wait for the entire A file content to be saved in temp memory before moving it into B

//  Stream is a built in module that inherits from the eventEmitter class
//  Other modules internally uses streams for their functioning


//  Ther are four types of streams
//      - Readable streans: From which data can be read                         
//      - Writable streans: To which we can write data
//      - Duplex streans: that are both readable and writable
//      - Transform streans: that can modify the data as it is written and read
//  -----------------------------------------------------------------------------
//  Examples:
//      - Reading from a file as a readable stream
//      - Writing  from a file as a writable stream
//      - Sockets as a duplec stream
//      - Fiel compression where we write compressed data and read decompressed data to and from a file as a transform stream


const fs = require("node:fs")

// fs.writeFileSync("./greet.txt", "Hello")

// fs.writeFile("./copyfile.txt","", (err) =>{
//     if(err){
//         console.log(err)
//     }else{
//         console.log("File created successfully, content below:")
//         console.log(fs.readFileSync("./copyfile.txt", "utf-8"))
//     }
// })

const readablestream = fs.createReadStream("./captivePortal.txt",{
    encoding: "utf-8",
    highWaterMark:100    //  We define the size of chunk that are being transferred via stream
})

const writablestream = fs.createWriteStream("./copyfile.txt",)
    
readablestream.on("data", (chunk)=>{
        console.log(chunk);             //  We log the chunks on the console
        writablestream.write(chunk)     //  File content from captivePortal.txt has been copied to copyfile.txt
})
