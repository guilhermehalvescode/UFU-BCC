<?php

require "./db.php";

$db = db();

class Endereco
{
  public $rua;
  public $bairro;
  public $cidade;

  function __construct($rua, $bairro, $cidade)
  {
    $this->rua = $rua;
    $this->bairro = $bairro;
    $this->cidade = $cidade;
  }
}

$cep = $_GET['cep'] ?? '';


try {

  $sql = <<<SQL
  SELECT cep, rua, bairro, cidade
  FROM endereco
  WHERE cep = :cep
  SQL;

  $stmt = $db->prepare($sql);
  $stmt->execute([':cep' => $cep]);

  $endereco = $stmt->fetch();

  if (!$endereco) {
    $endereco = new Endereco('', '', '');
  } else {
    $endereco = new Endereco($endereco['rua'], $endereco['bairro'], $endereco['cidade']);
  }
  
  header('Content-type: application/json');
  echo json_encode($endereco);

} 
catch (Exception $e) {
  exit('Ocorreu uma falha: ' . $e->getMessage());
}

