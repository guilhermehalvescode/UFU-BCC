<?php

require "./db.php"

$pdo = db();

$nome = $_POST['nome'] ?? '';
$email = $_POST['email'] ?? '';
$mensagem = $_POST['mensagem'] ?? '';


try {
    $sql = <<<SQL
    INSERT INTO contato 
    VALUES ('$nome', '$email', '$mensagem');
    SQL;
  
    $pdo->exec($sql);
  } 
  catch (Exception $e) {
    error_log($e->getMessage(), 3, 'log_registraContato.php');
    exit('Ocorreu uma falha: ' . $e->getMessage());
  }

?>