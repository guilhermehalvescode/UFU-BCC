<?php

require "./db.php";

$pdo = db();

$nome = $_POST['nome'] ?? '';
$email = $_POST['email'] ?? '';
$cpf = $_POST['cpf'] ?? '';
$pass = $_POST['pass'] ?? '';
$pass = password_hash($pass, PASSWORD_DEFAULT);

$cep = $_POST['cep'] ?? '';
$end = $_POST['end'] ?? '';
$district = $_POST['district'] ?? '';
$city = $_POST['city'] ?? '';
$state = $_POST['state'] ?? '';

$sql1 = <<<SQL
INSERT INTO cliente (nome, cpf, email, hash)
VALUES (?, ?, ?, ?);
SQL;


$sql2 = <<<SQL
INSERT INTO clienteEndereco 
(idCliente, cep, endereco, bairro, cidade, estado)
VALUES (?, ?, ?, ?, ?, ?)
SQL;


try {
  $pdo->beginTransaction();

  $stmt1 = $pdo->prepare($sql1);
  if (!$stmt1->execute([
    $nome, $cpf, $email, $pass,
  ])) throw new Exception('Falha na primeira inserção');

  $idNovoCliente = $pdo->lastInsertId();

  $stmt2 = $pdo->prepare($sql2);
  if (!$stmt2->execute([
    $idNovoCliente, $cep, $end, $district, $city, $state
  ])) throw new Exception('Falha na segunda inserção');

  $pdo->commit();
  header('Location: clientes.php');
} catch (Exception $e) {
  $pdo->rollBack();
  if ($e->errorInfo[1] === 1062)
    exit('Dados duplicados: ' . $e->getMessage());
  else
    exit('Falha ao cadastrar os dados: ' . $e->getMessage());
}

?>