# Bug Bounty (TokenAuction)

## Descrição

O contrato TokenAuction (aula da semana 2)  apresenta 3 bugs...identificados nos comentarios.

Descreva os bugs e corrija-os (codigo ou descrição detalhada!)

Vc deverá entregar um PDF com as correções.

No meu "gabarito" as correções são feitas dentro das funções indicadas​

## Correções

### Bug 1

No bug abaixo, a função createAuction não verifica se o nome do leilão já existe e se não está em leilão (AuctionState.Bid). Assim, se o nome já existir, o leilão será sobrescrito.

```solidity
function createAuction(string memory name, uint time, VerySimpleToken t) public {
  require (t.isOwner(msg.sender),"You must own the token to create one auction!");

  OneAuction memory l;
  l.blocklimit= block.number + time;
  l.myState = AuctionStates.Prep;
  l.winnerBid = 0;
  l.tokenOwner = msg.sender;
  l.payment = false;
  l.token = t;

  //Bug1 - Não verifica se o nome do leilão já existe no mapping myAuctions
  myAuctions[name]=l;
}
```

#### Correção do bug 1

```solidity
function createAuction(string memory name, uint time, VerySimpleToken t) public {
  require (t.isOwner(msg.sender),"You must own the token to create one auction!");

  // Correção do Bug1 - Verifica se o nome do leilão já existe no mapping myAuctions e se ele não está em leilão
  require(myAuctions[name].myState != AuctionSates.Bid, "Auction name already exists and is running!");

  OneAuction memory l;
  l.blocklimit= block.number + time;
  l.myState = AuctionStates.Prep;
  l.winnerBid = 0;
  l.tokenOwner = msg.sender;
  l.payment = false;
  l.token = t;

  myAuctions[name]=l;
}
```

### Bug 2

Nessa função claimToken, um usuário que não ganhou o leilão (address winner com maior winnerBid) pode receber o token, pois não há verificação se o usuário é o vencedor do leilão.

```solidity
function claimToken(string memory name) public payable {
  //Bug2
  OneAuction storage a = myAuctions[name];
  verifyFinished(a);

  require (a.myState == AuctionStates.Finished, "Wait a minute, boys, this one is not dead yet!");

  require (msg.value == a.winnerBid-collateralValue, "Pay First....");

  // Não verifica se o usuário é o vencedor do leilão
  a.token.transfer(msg.sender);
  a.collateral[msg.sender] = false; //just to flag claimToken
}
```

#### Correção do bug 2

```solidity
function claimToken(string memory name) public payable {
  //Bug2
  OneAuction storage a = myAuctions[name];
  verifyFinished(a);

  require (a.myState == AuctionStates.Finished, "Wait a minute, boys, this one is not dead yet!");

  // Correção
  require (a.winner == msg.sender, "You are not the winner of this auction!")

  require (msg.value == a.winnerBid-collateralValue, "Pay First....");

  a.token.transfer(msg.sender);
  a.collateral[msg.sender] = false; //just to flag claimToken
}
```

### Bug 3

Nessa função getFee, o contrato não verifica se há leilões abertos no momento do resgate das taxas, dessa forma é necessário que o dono do contrato chame a função informando o leilão que deseja resgatar as taxas.

```solidity
function getFee() public {
  //Bug3
  owner.transfer(address(this).balance);
}
```

#### Correção do bug 3

```solidity
function getFee(string memory name) public {
  //Bug3
  OneAuction storage a = myAuctions[name];
  verifyFinished(a);

  require (a.myState == AuctionStates.Finished, "Wait a minute, boys, this one is not dead yet!");

  require(a.payment == true, "Payment not yet made!");

  // como um getProfit foi realizado corretamente (a.payment == true), um contractFee foi descontado e dessa forma pode ser resgatado o valor de taxa certo
  owner.transfer(contractFee);
}