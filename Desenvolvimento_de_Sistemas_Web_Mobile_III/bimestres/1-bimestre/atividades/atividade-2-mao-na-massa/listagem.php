<!DOCTYPE html>
<html lang="pt-BR">
    <head>
        <meta charset="UTF-8">
        <title>Listagem dos Alunos</title>
        <link rel="stylesheet" href="./styles/navbar.css">
    </head>
    <body>
        <header>
            <nav class="navbar">
                <ul>
                    <li><a href="./cadastro.php">Cadastrar</a></li>
                    <li><a href="./media.php">Consultar Média</a></li>
                </ul>
            </nav>
        </header>
        <?php
            include 'resource/dataFetchHandler.php';

            if ($data) {
                foreach ($data as $aluno) {
                    echo $aluno['nome'] . ": " . $aluno['nota'] . "<br>";
                }
                echo "<form name='remover-dados' method='post' action='resource/formApagarHandler.php'><label>Deseja apagar os registros?</label><br/><input type='submit' name='confirmar' value='Confirmar'></form>";
            } else {
                echo "Não foram encontrados alunos registrados!";
            }
        ?>
    </body>
</html>
