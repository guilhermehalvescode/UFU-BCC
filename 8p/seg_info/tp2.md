# TP2

## Questão 1

Julgue cada um dos itens a seguir.

I) O processo de cifragem consiste em transformar o texto cifrado em texto claro.
II) Algoritmos criptográficos usam diferentes funções matemáticas para cifrar e decifrar informações.
III) Criptografia é a ciência responsável por manter as trocas de mensagens seguras.
IV) O processo de decifragem consiste em transformar o texto claro em texto cifrado.

Quais sentenças são FALSAS?

- Resposta: I e IV

## Questão 2

Selecione apenas a alternativa FALSA.
(5 Pontos)

A criptografia permite que as seguintes propriedades para a proteção da informação sejam alcançadas: sigilo, integridade, confidencialidade.

O princípio de autenticidade permitirá que Bob verifique se a mensagem recebida realmente veio de Alice.

De acordo com o Princípio de Kerckhoff, os algoritmos criptográficos podem ser públicos; apenas as chaves são secretas.

[X] A segurança de um modelo de criptografia está diretamente relacionada a divulgação do algoritmo usado para cifrar e decifrar. Um algoritmo público tende a ser mais inseguro do que um algoritmo privado.

## Questão 3

Julgue cada um dos itens a seguir sobre a caracterização dos sistemas criptográficos.

I) Textos claros são transformados em textos cifrados usando substituicão e transposição. A maioria dos sistemas criptográficos atuais envolve vários estágios de substituições e transposições. (V)
II) Sistemas criptográficos processam o texto de duas formas: em bloco e em fluxo. Em uma cifra de bloco de 128 bits, por exemplo, textos maiores do que 128 bits não podem ser processados. (F)
III) A cifra de César é um exemplo de cifra de fluxo pois as letras do texto são processadas continuamente, produzindo uma saída de cada vez. (V)
IV) A criptografia simétrica está relacionada ao sistema onde o emissor e o receptor usam chaves diferentes para cifrar e decifrar. (F)

- Resposta: 1 e 3 são verdadeiras

## Questão 4

Um algoritmo criptográfico robusto e com usabilidade prática deve ser, ao menos, computacionalmente seguro.

[X] Criptoanalistas não conseguem quebrar cifras computacionalmente seguras pois o texto cifrado gerado por ele não possui informação suficiente para determinar o texto claro correspondente, não importa quanto texto cifrado esteja à disposição do atacante.

O custo para quebrar a cifra ultrapassa o valor da informação cifrada.

O tempo exigido para quebrar a cifra supera o tempo de vida útil da informação.

## Questão 5

1s ---- 10⁹
x ----- 2⁵⁵
x = 2⁵⁵ / 10⁹ = 36028797 segundos = 417 dias

## Questão 6

Algoritmo de criptografia, texto cifrado, um ou mais pares de texto claro/texto cifrado.

Algoritmo de criptografia, texto cifrado, chave e um ou mais pares de texto claro/texto cifrado.

Algoritmo de criptografia, texto cifrado, chave, mensagem de texto claro conhecida e o respectivo texto cifrado.

[X] Algoritmo de criptografia, texto cifrado, mensagem de texto claro conhecida e o respectivo texto cifrado.

## Questão 7

Quanto mais "achatada" a curva de um algoritmo no gráfico, mais difícil será o trabalho do criptoanalista pois a informação de frequência da letra do texto cifrado não se aproximará a curva do texto claro.

O gráfico representa a distribuição de frequência de letras em algum alfabeto e o compara com diversos mecanismos de criptografia simétrica.

## Questão 8

O one time pad é considerado uma cifra incondicionalmente segura pois impede ataques de criptoanálise e força bruta devido a aleatoriedade da chave em cada envio de mensagem. Tal sistema não é utilizado na prática devido aos problemas de eficiência envolvidos: necessidade da chave ser do mesmo tamanho da mensagem (custo depende do tamanho da mensagem, que na maioria dos casos é grande); gerenciamento custoso das chaves (tanto para envio, quanto para geração).

## Questão 9

A mensagem original é: "acifradecesarnaoeseguraedeveserevitada".

Para chegar nela decodifiquei a mensagem "bW91cmRtcHFvcWVtZHptYXFlcXNnZG1xcHFocWVxZHFodWZtcG0=" em base64 e obtive o seguinte valor "mourdmpqoqemdzmaqeqsgdmqpqhqeqdqhufmpm".

No final testei diferentes deslocamentos da cifra de césar até achar um deslocamento de 12 caracteres: "mourdmpqoqemdzmaqeqsgdmqpqhqeqdqhufmpm" -> "acifradecesarnaoeseguraedeveserevitada"

## Questão 10

O Artigo apresenta os seguintes desafios:

- Criptografia padronizada: a padronização da criptografia é importante, porém para que ocorra, existem obstáculos tecnológicos, políticos e comerciais que tornam esse processo lento (demanda anos de desenvolvimento)
- Implementação: implementar um protocolo de criptografia é uma tarefa altamente complexa devido às dificuldades técnicas associadas à sua realização eficiente e segura.
- Gerenciamento de chaves: garantir o armazenamento, a distribuição e a realização de atualizações frequentes das chaves em sistemas e aplicações de grande.

## Questão 11

As "Crypto Wars" (Guerras Criptográficas) referem-se a debates, disputas e controvérsias em torno do uso e da regulamentação da criptografia, especialmente em relação à sua aplicação em comunicações digitais e na proteção da privacidade. Os principais atores e suas posições são:
