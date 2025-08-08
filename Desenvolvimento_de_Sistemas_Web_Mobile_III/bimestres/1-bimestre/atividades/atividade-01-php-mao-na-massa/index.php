<?php
    // Atividade 1 - Substituir Vogal por Asterisco
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $fraseUser = $_POST['atividade-1-frase'];
        $fraseFormatada = str_replace(['a', 'e', 'i', 'o', 'u', 'á', 'é', 'í', 'ó', 'ú', 'â', 'ê', 'î', 'ô', 'û', 'ã', 'à', 'è', 'ì', 'ò', 'ù'], '*', mb_strtolower($fraseUser)); // Versão mais Fácil
    }
    
    // Atividade 2 - Verifique se um número é primo ou não
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $numeroUser = $_POST['atividade-2-numero'];
        $numeroEPrimo = 'sim';
        if ($numeroUser < 0) {
            $numeroEPrimo = 'nao';
        }
        for ($i = 2; $i <= $numeroUser / 2; $i++) {
            if ($numeroUser % $i == 0) {
                $numeroEPrimo = 'nao';
                break;
            }
        }
    }

    // Atividade 3 - Inverta uma string sem usar a função strrev()
    function inverterString($string) {
        $armazenador = [];
        for ($i = strlen($string) - 1; $i >= 0; $i--) {
            $armazenador[] = $string[$i];
        }
        $armazenador = implode('', $armazenador);
        return $armazenador;
    }

    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $fraseUser2 = $_POST['atividade-3-frase'];
        $fraseInvertida = inverterString($fraseUser2);
    }

    // Atividade 4 - Crie uma função que receba um número e retorne se é positivo, negativo ou zero
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $numeroUser2 = $_POST['atividade-4-numero'];
        function tipoDeNumero($numero) {
            if ($numero > 0) {
                return "positivo";
            } else if ($numero < 0) {
                return "negativo";
            } else {
                return "nulo";
            }
        }
        $tipoDeNumero = tipoDeNumero($numeroUser2);
    }

    // Atividade 5 - Conte o número de palavras em uma frase e imprima cada palavra em uma nova linha
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $fraseUser3 = $_POST['atividade-5-frase'];
        $arrayFraseUser = explode(' ', $fraseUser3);
        $quantidadePalavrasNaFrase = count($arrayFraseUser);
    }

    // Atividade 6 - Crie uma função que verifique se uma palavra é um palíndromo
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $fraseUser4 = $_POST['atividade-6-frase'];
        $fraseFormatada2 = str_replace(' ', "", $fraseUser4);
        $fraseInvertida2 = inverterString($fraseFormatada2);
        $eUmPalindromo = 'não';
        if ($fraseFormatada2 == $fraseInvertida2) {
            $eUmPalindromo = "sim";
        }
    }

    // Atividade 7 - Crie um programa que imprima os números de 1 a 20, substituindo múltiplos de 3
    $numeroMaximo = 20;
    $numeroMinimo = 1;
    $sequenciaSemMultiplosDeTres = [];
    for ($i = $numeroMinimo; $i <= $numeroMaximo; $i++) {
        if ($i % 3 === 0) {
            $sequenciaSemMultiplosDeTres[] = "X";
            continue;
        }
        $sequenciaSemMultiplosDeTres[] = $i;
    }
    $sequenciaSemMultiplosDeTres = implode(", ", $sequenciaSemMultiplosDeTres);

    // Atividade 8 - Crie uma função que remova os espaços em branco de uma string
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $fraseUser5 = $_POST['atividade-8-frase'];
        $fraseSemEspacos = str_replace(" ", "", $fraseUser5);
    }

    // Atividade 9 - Crie um programa que calcule e imprima os números Fibonacci até o décimo termo
    $numeroMaximoDeTermos = 10;
    $numeroMinimoDeTermos = $antepenultimoNumero = $penultimoNumero = 0;
    $numeroAtual = 1;
    $sequenciaFibo = [0];
    for ($i = 2; $i <= $numeroMaximoDeTermos; $i++) {
        $antepenultimoNumero = $penultimoNumero;
        $penultimoNumero = $numeroAtual;
        $numeroAtual = $antepenultimoNumero + $penultimoNumero;
        $sequenciaFibo[] = $numeroAtual;
    }
    $sequenciaFibo = implode(", ", $sequenciaFibo);

    // Atividade 10 - Crie uma função que receba um texto e retorne se é um pangrama (contém todas as letras do alfabeto pelo menos uma vez)
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $fraseUser6 = strtoupper($_POST["atividade-10-frase"]);
        $eUmPangrama = "não";
        $alfabeto = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'];
        $arrayArmazenador = [];
        for ($i = 0; $i <= strlen($fraseUser6) - 1; $i++) {
            if (!in_array($fraseUser6[$i], $arrayArmazenador) && in_array($fraseUser6[$i], $alfabeto)) {
                $arrayArmazenador[] = $fraseUser6[$i];
            }
        }
        sort($arrayArmazenador);
        if ($arrayArmazenador == $alfabeto) {
            $eUmPangrama = "sim";
        }
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Atividades - Aula 2</title>
</head>
<body>
    <h1>Atividades - Mão na Massa em PHP</h1>
    
    <form method="POST" action="">
        <h2>Atividade 1 - Substituição de Vogais por Asterisco</h2>
        <label>Insira uma frase:</label>
        <input type="text" name="atividade-1-frase" placeholder="abacaxi com leite" required />
        <span><?php
            if (!empty($fraseUser)) {
                echo "<h3>A frase original é: $fraseUser</h3>";
                echo "<h3>A frase sem vogais: $fraseFormatada</h3>";
            }
        ?></span>

        <h2>Atividade 2 - Validador de Primos</h2>
        <label>Insira um número:</label>
        <input type="number" name="atividade-2-numero" placeholder="2" required />
        <span><?php
            if (!empty($numeroUser)) {
                echo "<h3>O número $numeroUser é primo: $numeroEPrimo</h3";
            }
        ?></span>
        
        <h2>Atividade 3 - Inverter String sem Built-in Functions</h2>
        <label>Insira uma frase:</label>
        <input type="text" name="atividade-3-frase" placeholder="socorram me subi no onibus em marrocos" required />
        <span><?php
            if (!empty($fraseUser2)) {
                echo "<h3>A frase original é: $fraseUser2</h3>";
                echo "<h3>A frase invertida é: $fraseInvertida</h3";
            }
        ?></span>

        <h2>Atividade 4 - Positivo, Negativo ou Zero?</h2>
        <label>Insira um número:</label>
        <input type="number" name="atividade-4-numero" placeholder="-642" required />
        <span><?php 
            if (!empty($numeroUser2) || $numeroUser2 == 0) {
                echo "<h3>O número $numeroUser2 é $tipoDeNumero</h3>";
            }
        ?></span>

        <h2>Atividade 5 - Contar e Imprimir Palavras</h2>
        <label>Insira uma frase:</label>
        <input type="text" name="atividade-5-frase" placeholder="doces ou travessuras" required />
        <span><?php
            if (!empty($fraseUser3)) {
                echo "<h3>A frase original é: $fraseUser3</h3>";
                echo "<h3>A quantidade de palavras na frase é: $quantidadePalavrasNaFrase</h3>";
                echo "<h3>Imprimindo cada palavra na frase em uma linha separada: </h3>";
                foreach($arrayFraseUser as $indice => $palavra) {
                    echo "<p>" . ($indice + 1) . " - $palavra</p>";
                }
            }
        ?></span>

        <h2>Atividade 6 - É um Palíndromo?</h2>
        <label>Insira uma frase (sem acentos para melhores resultados):</label>
        <input type="text" name="atividade-6-frase" placeholder="luz azul" required />
        <span><?php
            if (!empty($fraseUser4)) {
                echo "<h3>A frase original é: $fraseFormatada2</h3>";
                echo "<h3>A frase invertida é: $fraseInvertida2</h3>";
                echo "<h3>É um palíndromo: $eUmPalindromo</h3>";
            }
        ?></span>

        <h2>Atividade 7 - Sequência sem Múltiplos de 3</h2>
        <h3>A sequência vai de 0 a 20: <?php echo $sequenciaSemMultiplosDeTres; ?></h3>
        
        <h2>Atividade 8 - Remover Espaços em Branco</h2>
        <label>Insira uma frase:</label>
        <input type="text" name="atividade-8-frase" placeholder="eu amo gatos, sao ótimos felinos" required />
        <span><?php
            if (!empty($fraseUser5)) {
                echo "<h3>A frase original é: $fraseUser5</h3>";
                echo "<h3>A frase sem espaços é: $fraseSemEspacos</h3>";
            }
        ?></span>
        
        <h2>Atividade 9 - Sequência de Fibonnaci até o 10° termo</h2>
        <h3>A sequência de Fibonnaci até o 10° termo é: <?php echo $sequenciaFibo; ?></h3>

        <h2>Atividade 10 - Essa Frase é um Pangrama?</h2>
        <label>Insira uma frase (sem acentos para melhores resultados):</label>
        <input type="text" name="atividade-10-frase" placeholder="o rato roeu a roupa do rei de roma" required />
        <span><?php
            if (!empty($fraseUser6)) {
                echo "<h3>A frase original é: $fraseUser6</h3>";
                echo "<h3>A frase é um pangrama: $eUmPangrama</h3>";
            }
        ?></span>
        <button type="submit">Enviar</button>
    </form>
    
</body>
</html>

