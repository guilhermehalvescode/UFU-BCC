# TP5

## Exercício 1

I) A criptografia assimétrica é mais segura do que a criptografia simétrica pois os tamanhos de chaves de tal modelo são maiores.

II) Os algoritmos assimétricos contam com uma chave para cifrar e uma chave diferente, porém relacionada, para decifrar.

III) O primeiro algoritmo de chave pública apareceu no artigo inicial de Whitfield Diffie e Martin Hellman que definia a criptografia assimétrica.

IV) A criptografia assimétrica tornou a criptografia simétrica obsoleta e a substituiu como modelo padrão para estabelecimento de confidencialidade em um canal de comunicação.

- I e IV incorretas

## Exercício 2

Huguinho, Zezinho e Luizinho estão usando um sistema de criptografia assimétrica para se comunicar. Analise cada uma das sentenças abaixo e marque as alternativas verdadeiras.

I) Para enviar a mensagem cifrada "M" ao Luizinho, Zezinho fará o seguinte: E(PUz,M). Onde PUz representa a chave pública de Zezinho. (F)

II) É computacionalmente fácil para Zezinho, conhecendo a chave pública PUh de Huguinho e a mensagem M a ser cifrada, gerar o texto cifrado C = E(PUh,M). (V)

III) Mesmo que Huguinho conheça a chave pública PUz de Zezinho, deve ser computacionalmente inviável para ele determinar a chave privada PRz de Zezinho. (V)

IV) Caso Huguinho não possua a chave pública PUl de Luizinho, ele não será capaz de enviar mensagens cifradas para ele. (V)

V) Se o Pato Donald conhecer as chaves públicas do Huguinho, Zezinho e Luizinho e os textos cifrados com tais chaves, deve ser computacionalmente fácil recuperar as mensagens originais. (F)

- II, III, IV verdadeiras

## Exercício 3

C = M^e mod n deve ser fácil de calcular

M = C^d mod n deve ser fácil de calcular de posse de (n,d)

M = C^d mod n deve ser inviável caso não se conheça (n,d)

d ≡ e^-1 (𝑚𝑜𝑑 𝜙(𝑛)) deve ser fácil de calcular de posse de somente (e,n) (Incorreta)

d ≡ e^-1 (𝑚𝑜𝑑 𝜙(𝑛)) deve inviável caso não se conheça (p,q)

## Exercício 4

Sobre a segurança e usabilidade do RSA, é correto afirmar que:

O tamanho de n é a métrica comumente usada para estimar a segurança do algoritmo. No caso de n=2048 bits, tem-se que tal implementação do RSA é mais segura que qualquer algoritmo de criptografia simétrico.

Uma implementação do algoritmo RSA com n = 1024 bits permite a cifragem de blocos representados por inteiros entre 0 e n-1. O AES, por outro lado, permite tamanho de blocos de 128 bits. Isso implica que o RSA pode cifrar blocos maiores de dados o que implica em uma melhora de desempenho, quando comparado ao AES.

Por ser um algoritmo assimétrico robusto e amplamente conhecido pela comunidade de segurança, o RSA se tornou padrão em aplicações que exigem requisitos de confidencialidade, portanto, substituindo algoritmos simétricos como o AES.

O esforço computacional para encontrar o parâmetro d, de posse de (n,e), equivale a fatorar n em seus dois fatores primos (p,q). Para um n grande, com fatores primos grandes e escolhidos de forma cuidadosa, a fatoração de n é um problema de difícil solução. (X)

## Exercício 5

Em um modelo híbrido de criptografia, os seguintes passos foram executados:

1. Alice gerou a chave secreta "K" da sessão - tal chave é um número aleatório de 128 bits;
2. Alice cifrou "K" usando o algoritmo RSA e a sua chave pública - E(PUa,K) = C;
3. Bob decifrou o conteúdo de K usando a sua chave privada - D(PRb,C) = K;
4. Alice gerou uma mensagem "M1" e a cifrou usando o AES-128 bits - E(K,M1) = C1;
5. Bob recebe C1 e a decifra usando a sua chave privada - D(PRb,C1) = M1.

Assinale a alternativa correta sobre os passos acima.

A chave secreta "K" deve ter, no mínimo, 2048 bits.

Alice deveria ter cifrado a mensagem "M1" com a chave pública do Bob. Além disso, no passo 5, Bob não pode usar PRb para decifrar C1 e sim "K".

A justificativa do passo 4), o uso de algoritmos simétricos para cifrar "M1", está relacionada ao desempenho dos algoritmos de criptografia. Algoritmos assimétricos tendem a ter um desempenho melhor do que os algoritmos simétricos.

Alice deveria ter cifrado a chave "K" com a chave pública do Bob. Além disso, no passo 5, Bob não pode usar PRb para decifrar C1 e sim "K". (X)

## Exercício 6

Assinale a alternativa VERDADEIRA sobre requisitos de funções de hash criptográficas.

Uma função de hash criptográfica forte deve ser resistente a colisões, ou seja, deve ser computacionalmente inviável encontrar quaisquer x1 e x2 tais que h(x1) = h(x2). (X)

Uma função de hash criptográfica fraca não satisfaz a propriedade de que H(x) deve ser relativamente fácil de calcular para qualquer valor de x informado.

Uma função de hash criptográfica forte deve ser resistente a segunda pré-imagem, ou seja, é computacionalmente inviável, dado y, encontrar x tal que h(x) = y.

A resistência a colisões não é uma propriedade desejável para funções de hash usadas na geração de assinaturas digitais.

## Exercício 7

Uma aplicação das funções de hash criptográficas é o armazenamento de senhas em banco de dados. Sobre esse assunto, analise as sentenças abaixo.

I) Utilizando a requisito de eficiência das funções de hash, atacantes disponibilizam na Internet tabelas com duas colunas: dado de entrada (senha em potencial) e valor de hash de tal entrada. Isso é feito para diferentes funções de hash e permite que a propriedade de resistência à pré-imagem seja enfraquecida. Tais tabelas são chamadas de Rainbow Tables. (V)

II) Ao escolher uma função de hash para armazenamento de senhas, um importante requisito é a resistência à pré-imagem. Ou seja, se s é a senha e h(s) é o valor de hash da senha, deve ser computacionalmente inviável encontrar s dado h(s). (V)

III) O armazenamento de senhas usando funções de hash impede que senhas em claro sejam visualizadas em eventuais vazamentos de dados. (F)

IV) Salt é um recurso usado para mitigar o impacto das Rainbow Tables. Ao submeter a senha p, o sistema irá calcular H(p||s) e o valor de tal hash será armazenado no banco de dados. s representa um valor pré-definido pelo sistema, como exemplo, as iniciais do usuário ou o seu endereço de email. (V)

## Exercício 8

Alice gerencia o repositório de documentos digitais de uma prefeitura. Após uma série de reclamações sobre documentos maliciosos ligados ao repositório, Alice precisa elaborar uma solução que permita os usuários verificarem se o documento baixado é o mesmo documento disponibilizado no repositório. Alice então sugere calcular o hash de cada arquivo usando um algoritmo de hash adequado e disponibilizar o hash como um arquivo texto para posterior verificação. Em uma reunião com os supervisores e a equipe de TI, as seguintes colocações foram feitas:

I) "Um atacante pode invadir o nosso servidor, subir um arquivo malicioso, calcular o hash de tal arquivo e disponibilizar o hash de tal arquivo. Ou seja, a sua solução não funciona."
II) "O seu modelo não leva em consideração que dois arquivos podem ter o mesmo valor hash."
III) "Temos mais de 1000 arquivos disponíveis no repositório e, em média, 10 novos arquivos são alterados por mês. Essa sua proposta vai prejudicar o desempenho do sistema."
IV) "O sistema poderá ficar sobrecarregado pois além dos arquivos teremos que disponibilizar os hashes.

Assinale a alternativa correta:

A sentença II só faz sentido se Alice utilizar algum algoritmo que não cumpra os requisitos de hash criptográfico forte. Em contrapartida, independentemente da função de hash utilizada a colocação III faz sentido pois o cálculo da função de hash de um arquivo demanda um alto custo computacional. (F)

A sentença IV faz sentido pois o arquivo texto que contém o valor do hash depende do tamanho do arquivo de entrada. Sobre a sentença II, Alice poderia argumentar que o uso de funções de hash robustas, como SHA2 ou SHA3, torna computacionalmente inviável a criação de colisões. (F)

A sentença I está fora do escopo da solução da Alice. A invasão do servidor poderia comprometer não somente os documentos do repositório mas a integridade de todo o sistema. Funções de hash possuem saídas de tamanho fixo razoavelmente pequenas, como por exemplo, 128, 168 e 256 bits. Esse argumento poderia ser usado para contestar o colocação IV. (V)

A sentença III pode ser facilmente contestada se Alice usar uma função de hash criptográfica forte. Um dos requisitos de tais funções é justamente ligada ao excelente desempenho computacional dessas funções. O exemplo fornecido pela sentença I impossibilita a implementação de qualquer protocolo de verificação de integridade de arquivos. (F)

## Exercício 9

Uma função de hash criptográfica forte realiza um série de compressões através da separação da mensagens em blocos que passam por cálculos matemáticos complexos unidirecionais (não é possível a partir da saída, retornar a entrada), resultando em uma saída de tamanho fixo que é resistente a colisões.

## Exercício 10

Emissor e receptor precisam compartilhar um segredo S. Feito isso, o emissor concatena M e S, calcula o hash de M concatenado com S e envia ambos para o destino. O destino seleciona a mensagem M a concatena com o seu segredo S e calcula o hash. Feito isso, ele compara o hash que acabou de calcular com o bloco de hash que chegou junto da mensagem. Se ambos forem iguais, o destino garante a autenticidade da mensagem. (X)

Emissor e receptor precisam compartilhar um segredo S. Feito isso, o emissor calcula o hash de S, concatena com a mensagem M e envia para o destino. O destino calcula o hash do seu segredo S. Feito isso, ele compara o hash que acabou de calcular com o bloco de hash que chegou junto da mensagem. Se ambos forem iguais, o destino garante a autenticidade da mensagem.

Emissor e receptor precisam compartilhar um segredo S. Feito isso, o emissor concatena M e S, calcula o hash de M concatenado com S e envia ambos para o destino. O destino seleciona a mensagem M a concatena com o seu segredo S e calcula o hash. Feito isso, ele compara o hash que acabou de calcular com o bloco de hash que chegou junto da mensagem. Se ambos forem iguais, o destino garante que o emissor criou e assinou a mensagem, garantindo o não-repúdio.

Emissor e receptor precisam compartilhar um segredo S. Feito isso, o emissor concatena M e S e calcula o hash de M concatenado com S. O emissor então concatena M e o hash que acabou de calcular, cifra ambos usando S e envia o resultado da cifragem para o destino. O destino decifra o bloco com a chave S, seleciona a mensagem M a concatena com o seu segredo S e calcula o hash. Feito isso, ele compara o hash que acabou de calcular com o bloco de hash que chegou junto da mensagem. Se ambos forem iguais, o destino garante a autenticidade da mensagem.

## Exercício 11

Decifrar todo o bloco usando a chave K, separar M e o bloco de autenticação, calcular o hash de (M || S), comparar o hash que acabou de ser calculado com o bloco de autenticação que veio do emissor. (X)

## Exercício 12

Integridade, autenticidade, não-repúdio e sigilo

## Exercício 13

Um certificado digital é calculado a partir do hash da chave pública da entidade junto de outras informações da entidade solicitante e da autoridade certificadora (AC). Feito isso, o hash é cifrado com a chave privada da AC.

## Exercício 14

Instalar certificados revogados ou expirados no navegador não representam problemas de segurança pois uma autoridade certificadora os assinou.

## Exercício 15

i) calcular o hash do certificado não assinado, ii) decifrar o certificado assinado usando a chave pública da AC, iii) comparar o resultado de i) e ii)

## Exercício 16

1 e 3 são verdadeiras.

## Exercício 17