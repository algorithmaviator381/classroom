//  JS is a synchrnous, blocking, single threaded language

//  Synchrnous
//      - Code executes top down
//      - line by line

//  Blocking
//      - the subsequent process wont start until former is completed
//      - no matter how long the former process takes
//      - Sometimes a browser is blocked

//  Single-threded
//      - thread is a process that our js program uses to do a taks
//      - JS have a single thread (main thread) to for executing the code

//  This model craates a problem
//  This nature is not benificial for building and writing apps
//  we want non-blocking asynchrnous behaviour which is made possible by browser for frontend and Node.js for backend
//  We need asynchronous js

//  For frontend browsers come into play
//  For backend nodeJS comes into play

//  they defines APIs that allow us to register process that allows to register functions 
//  that should not be executed synchronously, and should be invoked asychrnously
//  when some kind of event occurs

//  For Example:
//      - passage of time (setTime or setIntervla)
//      - users interaction with mouse (addEventListiner)
//      - data being read from a file system or arrival of the data over the internet (callbacks, Promises, async-await) 

//  We can let our code do multiple things at the same time without stopping or blocking our main thread

// This type of programming where we dont block the main js thread is fundamental to node.js and is at the heart of 
//  how some of the built-in-module code is written