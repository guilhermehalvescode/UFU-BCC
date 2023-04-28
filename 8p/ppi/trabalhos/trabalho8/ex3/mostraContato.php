<?php

require "./db.php";
$pdo = db();

try {
  $sql = <<<SQL
  SELECT nome, email, mensagem
  FROM contato;
  SQL;

  $stmt = $pdo->query($sql);
} 
catch (Exception $e) {
  exit('Ocorreu uma falha: ' . $e->getMessage());
}
?>
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
            <thead>
                <tr>
                    <td>Nome:</td>
                    <td>Email:</td>
                    <td>Mensagem:</td>
                </tr>
            </thead>
            <tbody>
            <?php
                while ($row = $stmt->fetch()) {

                    $nome = $row['nome'];
                    $email = $row['email'];
                    $mensagem = $row['mensagem'];


                    echo <<<HTML
                    <tr>
                        <td>$nome</td> 
                        <td>$email</td>
                        <td>$mensagem</td>
                    </tr>      
                    HTML;
                }
                ?>
            </tbody>
        </tbody>
    </table>
    
</body>
</html>