/*
Exercício 1: Criar um servidor básico com Node.js Crie um servidor simples usando Node.js que responda "Bem-vindo!" quando acessado pela URL "/".

    -- CODIGO - ATV 1 --

const http = require('http');

const requestListener = function (req, res) {
    res.writeHead(200);
    res.end("Bem-vindo!");
}

const server = http.createServer(requestListener);

server.listen(8000, 'localhost', () => {
    console.log(`O servidor está rodando http://localhost:8000`);
})
*/

/*
Exercício 2: Implementar múltiplas rotas básicas

Expandindo o exercício anterior, crie um servidor com três rotas:
    ● "/" - Responder com "Bem-vindo!"
    ● "/sobre" - Responder com informações sobre você
    ● "/contato" - Responder com suas informações de contato

    -- CODIGO - ATV 2 --

const http = require('http');

const requestListener = function(req, res) {
    if (req.url === '/') {
        res.writeHead(200);
        res.end("Bem-vindo!");
    } else if (req.url === '/sobre') {
        res.writeHead(200);
        res.end("Somos a João Enterprises. Gostamos de trabalhar e atender a você com o maior amor e paixão!");
    } else if (req.url === 'contato') {
        res.writeHead(200);
        res.end("Converse com a gente pelo e-mail: engs-joaonakano@camporeal.edu.br");
    } else {
        res.writeHead(404);
        res.end("Não foi possível encontrar a página!");
    }
}

const server = http.createServer(requestListener);

server.listen(8000, 'localhost', () => {
    console.log("O servidor está rodando em http://localhost:8000");
})
*/

/*
Exercício 3: Utilizar módulos personalizados

Crie um módulo separado chamado utils.js que contenha uma função para gerar um número aleatório entre 1 e 10. Em seguida, crie um servidor que use esse módulo para responder com um número aleatório quando acessado pela rota "/numero".

Pontos-chave:
    ● Criar um módulo personalizado
    ● Importar e usar o módulo em outro arquivo
    ● Responder com dados dinâmicos

    -- CODIGO - ATV 3 --

const http = require('http');
const util = require('./util.js');

const requestListener = function(req, res) {
    if (req.url === '/') {
        res.writeHead(200);
        res.end("Bem-vindo!");
    } else if (req.url === '/sobre') {
        res.writeHead(200);
        res.end("Somos a João Enterprises. Gostamos de trabalhar e atender a você com o maior amor e paixão!");
    } else if (req.url === 'contato') {
        res.writeHead(200);
        res.end("Converse com a gente pelo e-mail: engs-joaonakano@camporeal.edu.br");
    } else if (req.url === '/numero') { 
        res.end(`${util.randomico()}`);
    } else {
        res.writeHead(404);
        res.end("Não foi possível encontrar a página!");
    }
}

const server = http.createServer(requestListener);

server.listen(8000, 'localhost', () => {
    console.log("O servidor está rodando em http://localhost:8000");
})
*/

/*
Exercício 4: Implementar rotas parametrizadas

Crie um servidor que responda com uma saudação personalizada quando acessado por
uma URL como "/saudacao/seu_nome". Por exemplo, "/saudacao/joao" deve responder
com "Olá, João!".

Pontos-chave:
    ● Usar parâmetros na rota
    ● Extrair informações da URL para personalizar a resposta

    -- CODIGO - ATV 4 --

const http = require('http');
const util = require('./util.js');

const requestListener = function(req, res) {
    if (req.url === '/') {
        res.writeHead(200);
        res.end("Bem-vindo!");
    } else if (req.url === '/sobre') {
        res.writeHead(200);
        res.end("Somos a João Enterprises. Gostamos de trabalhar e atender a você com o maior amor e paixão!");
    } else if (req.url === '/contato') {
        res.writeHead(200);
        res.end("Converse com a gente pelo e-mail: engs-joaonakano@camporeal.edu.br");
    } else if (req.url === '/numero') { 
        res.writeHead(200);
        res.end(`${util.randomico()}, ${nome}`);
    } else if (req.url.slice(0, 9) === '/saudacao') {
        res.writeHead(200);
        urlArraySplit = req.url.split('/');
        nome = urlArraySplit[2];
        res.end(nome);
    } else {
        res.writeHead(404);
        res.end("Não foi possível encontrar a página!");
    }
}

const server = http.createServer(requestListener);

server.listen(8000, 'localhost', () => {
    console.log("O servidor está rodando em http://localhost:8000");
})

*/

/*
Exercício 5: Criar um servidor Express básico

Usando o framework Express, crie um servidor que tenha duas rotas:
    ● "/" - Responder com uma página HTML simples
    ● "/api/data" - Responder com um objeto JSON contendo informações básicas sobre
    você

Pontos-chave:
    ● Instalar e configurar o Express
    ● Usar o Express para gerenciar rotas
    ● Responder com diferentes tipos de conteúdo (HTML e JSON)

    -- CODIGO - ATV 5 --

const express = require('express');
const fs = require('fs');

const app = express();
const port = 8000;

var apiData;
const lerAPi = fs.readFile('./data.json', 'utf8', (err, data) => {
    if (err) {
        console.error(err);
        return;
    }
    apiData = data;
});

app.get('/', (req, res) => {
    res.send("Olá, meu amigo! \nBem-vindo à minha página feita com Node.js!");
})

app.get('/api/data', (req, res) => {
    res.send(apiData);
})

app.listen(port, () => {
    console.log(`Escutando na porta http://localhost:${port}`);
})
*/