<!DOCTYPE html>
<html lang="pt-BR">
    <head>
        <meta charset="UTF-8">
        <title>Cadastro de Alunos</title>
        <link rel="stylesheet" href="./styles/navbar.css">
    </head>
    <body>
        <header>
            <nav class="navbar">
                <ul>
                    <li><a href="./listagem.php">Listar Alunos</a></li>
                    <li><a href="./media.php">Consultar Média</a></li>
                </ul>
            </nav>
        </header>
        <form name="cadastro" method="POST" action="resource/formCadastroHandler.php">
            <table>
                <tr>
                    <td><label>Nome:</label></td>
                    <td><input type="text" name="nome" placeholder="João Silva" required></td>
                </tr>

                <tr>
                    <td><label>Nota:</label></td>
                    <td><input type="number" name="nota" min="0" max="10" placeholder="5" required></td>
                </tr>
                <tr>
                    <td colspan="2">
                        <input type="submit" name="enviar" value="Enviar">
                        <input type="reset" name="limpar" value="Limpar">
                    </td>
                </tr>
            </table>
        </form>
    </body>
</html>
