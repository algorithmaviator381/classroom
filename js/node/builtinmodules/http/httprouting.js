const http = require("node:http")
const fs = require("node:fs")

const server = http.createServer((req,res) => {
    res.end(req.url)
})

server.listen(3000,() => {
    console.log("Server running on port 3000")
})