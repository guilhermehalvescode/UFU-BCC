<?php

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

// carrega a string JSON da requisição
// php://input retorna todos os dados que vem depois
// das linhas de cabeçalho HTTP da requisição, 
// independentemente do tipo do conteúdo
$stringJSON = file_get_contents('php://input');

// converte a string JSON em objeto PHP
$dados = json_decode($stringJSON);
$cep = $dados->cep;

if ($cep == '38400-100')
  $endereco = new Endereco('Av Floriano', 'Centro', 'Uberlândia');
else if ($cep == '38400-200')
  $endereco = new Endereco('Rua Tiradentes', 'Fundinho', 'Uberlândia');
else
  $endereco = new Endereco('', '', '');
  
header('Content-type: application/json');
echo json_encode($endereco);