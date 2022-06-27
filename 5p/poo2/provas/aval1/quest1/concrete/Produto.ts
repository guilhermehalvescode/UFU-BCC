import Estado from "../abstracts/Estado";
import Indisponivel from "../state/Indisponivel";

export default class Produto {
  #quantidade: number
  #estado: Estado

  constructor() {
    this.#quantidade = 0;
    this.#estado = new Indisponivel(this);
  }

  get quantidade(): number {
    return this.#quantidade;
  }

  set quantidade(valor: number) {
    if(valor < 0)
      this.#quantidade = 0;
    else
      this.#quantidade = valor;
  }

  get estado(): Estado {
    return this.#estado;
  }
  
  set estado(estado: Estado) {
    this.#estado = estado;
  }

  compra(quantidade: number): void {
    this.#estado.compra(quantidade);
  }

  venda(quantidade: number): void {
    this.#estado.venda(quantidade);
  }
}