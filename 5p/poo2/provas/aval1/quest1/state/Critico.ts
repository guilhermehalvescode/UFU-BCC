import Estado from "../abstracts/Estado";
import Produto from "../concrete/Produto";
import Disponivel from "./Disponivel";
import Indisponivel from "./Indisponivel";

export default class Critico extends Estado {
  
  constructor(produto: Produto) {
    super(produto)
    this.limiteInferior = 1;
    this.limiteSuperior = 10;
  }

  verificaAlteracaoEstado(): void {
    const produto = this.produto;
    if(produto.quantidade < this.limiteInferior) {
      this.produto.estado = new Indisponivel(produto);
    } else if(produto.quantidade > this.limiteSuperior) {
      this.produto.estado = new Disponivel(produto);
    }
  }
}