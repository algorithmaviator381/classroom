const http = require("http");
const fs = require("fs");
const socketIO = require("socket.io");

const serverPort = 3000;
const serverAddress = "0.0.0.0";

const server = http.createServer((req, res) => {
    const name = "client";

    res.writeHead(200, { "Content-Type": "text/html" });

    let html = fs.readFileSync("./index.html", "utf-8");
    html = html.replace("{{name}}", name);
    res.end(html);
});

const io = socketIO(server);

io.on("connection", (socket) => {
    console.log(`A new client connected: ${socket.id}, IP: ${socket.handshake.address}`);

    socket.emit("message", `Welcome to the server ${socket.handshake.address}!`);

    socket.on("clientMessage", (message) => {
        console.log(`Received message from ${socket.id} (${socket.handshake.address}): ${message}`);
    });

    socket.on("disconnect", () => {
        console.log(`Client disconnected: ${socket.id}`);
    });
});

server.listen(serverPort, serverAddress, () => {
    console.log(`Server running on http://${serverAddress}:${serverPort}/`);
});
