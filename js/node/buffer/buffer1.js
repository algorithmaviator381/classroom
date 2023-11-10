const buffer = new Buffer.from("adimail")

//  Buffers have limited memory
//  .write overwrite the first 3 characters from the 
//  buffer with the new values
buffer.write("kul")

console.log(buffer.toString())
console.log(buffer)
console.log(buffer.toJSON())