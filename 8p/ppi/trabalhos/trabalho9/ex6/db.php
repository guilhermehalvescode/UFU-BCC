<?php

function db()
{
  $db_host = "sql106.epizy.com";
  $db_username = "epiz_33702317";
  $db_password = "valterValter";
  $db_name = "epiz_33702317_anuncios";
  $db_port = "3306";

  $dsn = "mysql:host=$db_host;port=$db_port;dbname=$db_name;charset=utf8mb4";

  $options = [
    PDO::ATTR_EMULATE_PREPARES => false,
    PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,  
    PDO::ATTR_PERSISTENT    => true,
    PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
  ];

  try {
    $pdo = new PDO($dsn, $db_username, $db_password, $options);
    return $pdo;
  } 
  catch (Exception $e) {
    error_log($e->getMessage(), 3, 'log.php');
    exit('Ocorreu uma falha na conexão com o BD: ' . $e->getMessage());
  }
}

?>
