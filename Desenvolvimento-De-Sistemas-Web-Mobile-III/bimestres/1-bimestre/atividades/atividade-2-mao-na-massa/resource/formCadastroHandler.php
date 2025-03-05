<?php

function escreverArquivo($filename, $data) {
    $handle = fopen($filename, "a+");
    fwrite($handle, $data);
    fclose($handle);
    return true;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $nome = htmlspecialchars($_POST["nome"]);
    $nota = htmlspecialchars($_POST["nota"]);

    if (empty($nome) || empty($nota)) {
        header("Location: ../index.php");
        exit();
    }

    $path = "./database/notas.txt";
    $data = "$nome, $nota\n";
    $status = escreverArquivo($path, $data);
    
    if ($status) {
        header("Location: ../index.php");
        exit();
    }

    echo "Não foi possível escrever no banco de dados!";
} else {
    header("Location: ../index.php");
}