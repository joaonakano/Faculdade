const http = require('http');

const requestListener = function(req, res) {
    if (req.url === "/") {
        res.writeHead(200);
        res.end("Está na Página Home");
    } else if (req.url === "/sobre") {
        res.end("Está na Página Sobre")
    } else {
        res.end("404 - Não Encontramos a Página Especificada!")
    }
};

const server = http.createServer(requestListener);

server.listen(8000, 'localhost', () => {
    console.log("Servidor está rodando em http://localhost:8000")
});