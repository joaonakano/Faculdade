<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Média da Turma</title>
    <link rel="stylesheet" href="./styles/navbar.css">
</head>
<body>
    <header>
        <nav class="navbar">
            <ul>
                <li><a href="./cadastro.php">Cadastrar</a></li>
                <li><a href="./listagem.php">Listar Alunos</a></li>
            </ul>
    </nav>
    </header>
    <?php
        include "./resource/dataFetchHandler.php";
        if ($media) {
            echo "A média é: $media";
        } else {
            echo "Não foi possível calcular a média, não existem alunos registrados!";
        }
    ?>
</body>
</html>