const path = require("node:path")

console.log("Hiya stranger")
console.log(__filename)
console.log(__dirname)

console.log(path.basename(__filename))
console.log(path.basename(__dirname))
