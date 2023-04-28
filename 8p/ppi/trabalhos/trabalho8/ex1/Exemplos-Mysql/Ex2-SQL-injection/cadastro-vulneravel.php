<?php

require "../conexaoMysql.php";
$pdo = mysqlConnect();

$nome = $_POST["nome"] ?? "";
$telefone = $_POST["telefone"] ?? "";

try {

  // NÃO FAÇA ISSO! Exemplo de código vulnerável a injeção de SQL
  $sql = <<<SQL
  INSERT INTO aluno (nome, telefone)
  VALUES ('$nome', '$telefone');
  SQL;  

  // Experimente fazer o cadastro de um novo aluno preenchendo 
  // o campo telefone com o texto a seguir: tolo'); DELETE FROM aluno; -- comment
  // OBS: o problema permanece mesmo utilizando aspas duplas para envolver 
  // os nomes das variáveis no código SQL, pois bastaria alterar a 
  // string para tolo"); DELETE FROM aluno; -- comment
  $pdo->exec($sql);
  header("location: mostra-alunos.php");
  exit();
} 
catch (Exception $e) {  
  exit('Falha ao cadastrar os dados: ' . $e->getMessage());
}
