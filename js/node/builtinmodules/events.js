//  We call the constant EventEmitter because events module returns a class called EventEmitter which encapsulates the properties and members
// we can call it events but EventEmitter is more appropriate


//  This is called event driven programming
//  Used quite a lot in node js
const eventEmitter = require("node:events")

//  Emitter Object
const emitter = new eventEmitter()

//  Listiner to respond to events
//  Callback function
emitter.on("Order-Pizza", (size, topping = "no") => {
    console.log(`Order recieved, Baking a ${size} pizza with ${topping} toppings`)
})

//  We can have multiple listiners for an event
//  emit accepts the event name as argument
//  followed by the arguments that can be passed as arguments to the listiners
//  When the listiners are called, the node automatically passes the arguments 
emitter.emit("Order-Pizza", "Large", "mushrooms")
emitter.emit("Order-Pizza", "Medium")