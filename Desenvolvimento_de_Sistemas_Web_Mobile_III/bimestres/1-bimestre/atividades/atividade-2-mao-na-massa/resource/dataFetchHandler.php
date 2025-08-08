<?php

function lerArquivo ($filename) {
    $alunos = [];
    if (($arquivoHandle = fopen($filename, 'r')) !== false) {
        while (($data = fgetcsv($arquivoHandle)) !== false) {
            if (!empty($data[0]) && !empty($data[1])) {
                $alunos[] = [
                    "nome" => $data[0],
                    "nota" => $data[1]
                ];
            }
        }
        fclose($arquivoHandle);
    }

    return existeDadoNoArray($alunos);
}

function existeDadoNoArray ($dataArray) {
    if (!empty($dataArray)) {
        return $dataArray;
    } else {
        return false;
    }
}

function consultarMedia ($dataArray) {
    if (!existeDadoNoArray($dataArray)) {
        return false;
    };

    $quantidadeAlunos = count($dataArray);
    $somaDasNotas = 0;

    foreach ($dataArray as $subSet) {
        $somaDasNotas += $subSet["nota"];    // Pega o segundo elemento de cada subconjunto e calcula a soma, exemplo: [[joao, 1], [carlos, 3], [vinicius, 6]]
    }

    $media = $somaDasNotas / $quantidadeAlunos;
    return $media;
}

$data = lerArquivo("./resource/database/notas.txt");
$media = consultarMedia($data);