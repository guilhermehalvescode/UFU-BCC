<?php

class RequestResponse
{
  public $success;
  public $detail;

  function __construct($success, $detail)
  {
    $this->success = $success;
    $this->detail = $detail;
  }
}

$email = $_POST['email'] ?? '';
$senha = $_POST['senha'] ?? '';

// Validação simplificada para fins didáticos. Não faça isso!
if ($email == 'teste@mail.com' && $senha == '123456')
  $response = new RequestResponse(true, 'home.html');
else
  $response = new RequestResponse(false, '');

header('Content-type: application/json');
echo json_encode($response);