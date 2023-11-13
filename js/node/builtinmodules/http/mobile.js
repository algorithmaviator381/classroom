const http = require("http");
const fs = require("fs");

const serverPort = 3000;
const serverAddress = "0.0.0.0";

const server = http.createServer((req, res) => {
    const name = "Aditya";

    res.writeHead(200, { "Content-Type": "text/html" });

    let html = fs.readFileSync("./index.html", "utf-8");
    html = html.replace("{{name}}", name);
    res.end(html);
});

server.listen(serverPort, serverAddress, () => {
    console.log(`Server running on http://${serverAddress}:${serverPort}/`);
});
