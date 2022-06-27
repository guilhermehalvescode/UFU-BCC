import Estado from "../abstracts/Estado";
import Produto from "../concrete/Produto";
import Critico from "./Critico";

export default class Indisponivel extends Estado {
  
  constructor(produto: Produto) {
    produto.quantidade = 0;
    super(produto)
    this.limiteInferior = 0;
    this.limiteSuperior = 0;
  }

  venda(_quantidade: number): void {
    console.log("Reponha estoque");
  }

  verificaAlteracaoEstado(): void {
    const produto = this.produto;
    if(produto.quantidade > this.limiteSuperior) {
      this.produto.estado = new Critico(produto);
      this.produto.estado.verificaAlteracaoEstado();
    } 
  }
}