<?php

require "./db.php";
$pdo = db();

try {

  $sql = <<<SQL
  SELECT nome, cpf, email, hash, cep, endereco, bairro, cidade, estado
  FROM cliente INNER JOIN clienteEndereco ON cliente.cod = clienteEndereco.idCliente
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
    <title>Mostra clientes</title>
</head>
<body>
    <table>
        <tbody>
            <thead>
                <tr>
                    <td>Nome:</td>
                    <td>Cpf:</td>
                    <td>Email:</td>
                    <td>Hash:</td>
                    <td>CEP:</td>
                    <td>Endereço:</td>
                    <td>Bairro:</td>
                    <td>Cidade:</td>
                    <td>Estado:</td>
                </tr>
            </thead>
            <tbody>
            <?php
                while ($row = $stmt->fetch()) {
                    $nome = htmlspecialchars($row['nome']);
                    $cpf = htmlspecialchars($row['cpf']);
                    $email = htmlspecialchars($row['email']);
                    $hash = htmlspecialchars($row['hash']);
                    $cep = htmlspecialchars($row['cep']);
                    $endereco = htmlspecialchars($row['endereco']);
                    $bairro = htmlspecialchars($row['bairro']);
                    $cidade = htmlspecialchars($row['cidade']);
                    $estado = htmlspecialchars($row['estado']);
                    echo <<<HTML
                    <tr>
                        <td>$nome</td> 
                        <td>$cpf</td>
                        <td>$email</td>
                        <td>$hash</td>
                        <td>$cep</td>
                        <td>$endereco</td>
                        <td>$bairro</td>
                        <td>$cidade</td>
                        <td>$estado</td>
                    </tr>      
                    HTML;
                }
                ?>
            </tbody>
        </tbody>
    </table>
    
</body>
</html>