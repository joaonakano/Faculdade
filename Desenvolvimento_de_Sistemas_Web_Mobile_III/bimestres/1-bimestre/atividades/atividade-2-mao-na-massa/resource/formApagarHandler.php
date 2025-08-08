<?php 

function apagarDadosDoArquivo($filename) {
    $handle = fopen($filename,"w");
    fclose($handle);
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $path = "./database/notas.txt";
    apagarDadosDoArquivo($path);
    header("Location: ../index.php");
}