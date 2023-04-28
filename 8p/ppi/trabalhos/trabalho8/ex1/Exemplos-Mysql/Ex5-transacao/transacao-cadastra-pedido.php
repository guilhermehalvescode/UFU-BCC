<?php

require "../conexaoMysql.php";
$pdo = mysqlConnect();

// Resgata os dados do cliente
$nome = $_POST["nome"] ?? "";
$cpf  = $_POST["cpf"] ?? "";
$email = $_POST["email"] ?? "";
$senha = $_POST["senha"] ?? "";
$altura = $_POST["altura"] ?? "";
$estadocivil = $_POST["estadocivil"] ?? "";
$datanascimento = $_POST["datanascimento"] ?? "";

// Resgata os dados do endereço de entrega
$cep = $_POST["cep"] ?? "";
$endereco = $_POST["endereco"] ?? "";
$bairro = $_POST["bairro"] ?? "";
$cidade = $_POST["cidade"] ?? "";

// calcula um hash de senha seguro para armazenar no BD
$hashsenha = password_hash($senha, PASSWORD_DEFAULT);

$sql1 = <<<SQL
  INSERT INTO cliente (nome, cpf, email, hash_senha, 
                       data_nascimento, estado_civil, altura)
  VALUES (?, ?, ?, ?, ?, ?, ?)
  SQL;

$sql2 = <<<SQL
  INSERT INTO endereco_entrega 
    (cep, endereco, bairro, cidade, id_cliente)
  VALUES (?, ?, ?, ?, ?)
  SQL;

try {
  $pdo->beginTransaction();

  // Inserção na tabela cliente
  // Neste caso utilize prepared statements para prevenir
  // ataques do tipo SQL Injection, pois estamos
  // inseririndo dados fornecidos pelo usuário
  $stmt1 = $pdo->prepare($sql1);
  if (!$stmt1->execute([
    $nome, $cpf, $email, $hashsenha,
    $datanascimento, $estadocivil, $altura
  ])) throw new Exception('Falha na primeira inserção');

  // Inserção na tabela endereco_cliente
  // Precisamos do id do cliente cadastrado, que
  // foi gerado automaticamente pelo MySQL
  // na operação acima (campo auto_increment), para
  // prover valor para o campo do tipo chave estrangeira
  $idNovoCliente = $pdo->lastInsertId();
  $stmt2 = $pdo->prepare($sql2);
  if (!$stmt2->execute([
    $cep, $endereco, $bairro, $cidade, $idNovoCliente
  ])) throw new Exception('Falha na segunda inserção');

  // Efetiva as operações
  $pdo->commit();

  header("location: ../index.html");
  exit();
} 
catch (Exception $e) {
  $pdo->rollBack();
  if ($e->errorInfo[1] === 1062)
    exit('Dados duplicados: ' . $e->getMessage());
  else
    exit('Falha ao cadastrar os dados: ' . $e->getMessage());
}
