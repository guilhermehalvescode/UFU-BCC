<?php
require "../conexaoMysql.php";
$pdo = mysqlConnect();

$cpf = $_GET["cpf"] ?? "";

try {

  $sql = <<<SQL
  DELETE FROM cliente
  WHERE cpf = ?
  LIMIT 1
  SQL;

  // Neste caso utilize prepared statements para prevenir
  // ataques do tipo SQL Injection, pois a declaração
  // SQL contem um parâmetro (cpf) vindo da URL
  $stmt = $pdo->prepare($sql);
  $stmt->execute([$cpf]);

  header("location: mostra-clientes.php");
  exit();
} 
catch (Exception $e) {  
  exit('Falha inesperada: ' . $e->getMessage());
}
