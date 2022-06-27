import Estado from "../abstracts/Estado";
import Produto from "../concrete/Produto";
import Critico from "./Critico";

export default class Disponivel extends Estado {
  
  constructor(produto: Produto) {
    super(produto)
    this.limiteInferior = 11;
    this.limiteSuperior = Infinity;
  }

  verificaAlteracaoEstado(): void {
    const produto = this.produto;
    if(produto.quantidade < this.limiteInferior) {
      this.produto.estado = new Critico(produto);
      this.produto.estado.verificaAlteracaoEstado();
    }
  }
}