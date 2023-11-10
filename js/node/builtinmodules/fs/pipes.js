//  Imagine a tank and a tap
//  Pipes takes water from tank and feeds it to the tap
//  Pipes take readable stream and adds it to writable stream 

const fs = require("node:fs")
const zlib = require("node:zlib")   //  Compression library
                                    //  Zlib has a buitin transform stream