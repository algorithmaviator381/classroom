const http = require("node:http")


//  This method accepts a callback function as an argument
//  This function recieves 2 args, Request and response

//  req = request
//  res = response
const server = http.createServer((req,res) => {
    res.writeHead(200,{"Content-Type": "text/plain"})
    res.end(`${req},${res}`)
})

//Server is running in localhost:3000
server.listen(3000,() => {
    console.log("Server running on port 3000")
})

