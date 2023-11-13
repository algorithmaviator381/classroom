//  Imagine a tank and a tap
//  Pipes takes water from tank and feeds it to the tap
//  Pipes take readable stream and adds it to writable stream 

const fs = require("node:fs")
const zlib = require("node:zlib")   //  Compression library, builtin transform stream

const gzlib = zlib.createGzip()

const readablestream = fs.createReadStream("./captivePortal.txt",{
    encoding: "utf-8",
    highWaterMark:100    //  We define the size of chunk that are being transferred via stream
})

readablestream.pipe(gzlib).pipe(fs.WriteStream("./copyfile.txt.gz"))

const  writablestream = fs.createWriteStream("./copyfile.txt")

readablestream.pipe(writablestream)