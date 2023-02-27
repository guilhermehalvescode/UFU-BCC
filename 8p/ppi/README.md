# Programação para Internet

## HTML

- Inicialmente havia HTML e XHTML desenvolvidos pela W3C e a WHATWG, respectivamente.

### Elementos HTML

-`<nomedoElemento>conteúdo</nomeDoElemento>`: elemento com tag de abertura e fechamento

- Há elementos que não possuem tag de fechamento (fechamento implícito)
  - tag `<img>`

## Estrutura básica

- Inicia com a tag `<!DOCTYPE html>`, que especifica o tipo de documento e sua versão (HTML5)
- `<html>`: elemento raiz
- `<head>`: cabeçalho do documento
- `<title>`: título do documento
- `<meta>`: metadados do documento
- `<link>`: link para outros documentos
- `<style></style>`: especificação de estilo
- `<body></body>`: corpo do documento
- `<h1></h1>`: título de nível 1
- `<h2>`: subtítulos de nível 2
- `<h3>`, `<h4>`, `<h5>` e `<h6>`: subtítulos menores
- `<p>`: parágrafo
  - começam em uma nova linha
  - espaçamento antes e depois (padrão)
- `<abbr>`: abreviação ou acrônimos
- `<address>`: endereço e contato em geral
- `<pre>`: texto pré-formatado
  - preserva espaços e quebras de linha
- `<br>`: quebra de linha
- `<q>`: citações curtas
  - apresentada com aspas
- `<blockquote></blockquote>`: citações longas
  - apresentada com recuo
- `<cite>`: citações de títulos de trabalhos criativos
  - apresentada com itálico
- `<b></b>`: adicionar importância sem destacar
- `<strong></strong>`: conteúdo tem forte importância ou urgência
  - lido com entonação forte
- `<i>`: historicamente usado para itálico
  - termos ténicos ou estrangeiros
- `<em>`: enfatizar um termo
  - lido com entonação
- `<ul>`: lista não ordenada
- `<ol>`: lista ordenada
- `<li>`: item de lista
- `<dl>`: lista de definições
- `<dt>`: termo a ser definido
- `<dd>`: definição do termo
- `<img>`: inserir imagem
  - atributo `src`: caminho da imagem
  - atributo `alt`: texto alternativo
  - atributo `title`: título da imagem
  - atributo `width`: largura da imagem (evita mudanças de layout durante carregamento da página)
  - atributo `height`: altura da imagem (evita mudanças de layout durante carregamento da página)
- `<figure>`: figura (conjunto de imagens, gráficos, diagramas, códigos, etc.)
  - imagem exibida com recuo
  - pode ser figuras geradas por programas (js)
  - `<figcaption>`: legenda da figura

### Árvore DOM

- Árvore que é construída quando um documento é carregado em um navegador, permitindo que o navegador acesse e manipule os elementos do documento de forma dinâmica.

### Hyperlinks

- `<a href="http://www.ufu.br> UFU </a>`: link para o site da UFU
  - atributo `href`: endereço do link
  - atributo `target`: onde o link será aberto
    - `_blank`: abre em uma nova janela
    - `_self`: abre na mesma janela
    - `_parent`: abre no frame pai
    - `_top`: abre na janela principal

### Tabelas

- `<table>`: tabela
  - `<thead>`: cabeçalho
    - `<th>`: célula de cabeçalho
  - `<tbody>`: corpo
    - `<td>`: célula de dados
  - `<tfoot>`: rodapé
  - `<tr>`: linha da tabela