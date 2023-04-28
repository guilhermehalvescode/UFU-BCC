<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Mostra contato</title>
</head>
<body>
    <table>
        <tbody>
            <tr>
                <td>Nome:</td>
                <td><?php echo htmlspecialchars($_GET['nome'] ?? '')?></td>
            </tr>
            <tr>
                <td>Email:</td>
                <td><?php echo htmlspecialchars($_GET['email'] ?? '')?></td>
            </tr>
            <tr>
                <td>Mensagem:</td>
                <td><?php echo htmlspecialchars($_GET['mensagem'] ?? '')?></td>
            </tr>
        </tbody>
    </table>
    
</body>
</html>