import Produto from "../concrete/Produto";

export default abstract class Estado {
  #produto: Produto

  #limiteInferior: number = 0
  #limiteSuperior: number = 0

  constructor(produto: Produto) {
    this.#produto = produto
  }

  get produto() {
    return this.#produto;
  }

  set produto(produto: Produto) {
    this.#produto = produto
  }

  get limiteInferior(): number {
    return this.#limiteInferior;
  }

  set limiteInferior(valor: number) {
    this.#limiteInferior = valor;
  }
  
  get limiteSuperior(): number {
    return this.#limiteSuperior;
  }

  set limiteSuperior(valor: number) {
    this.#limiteSuperior = valor;
  }

  compra(quantidade: number): void {
    this.produto.quantidade += quantidade;
    this.verificaAlteracaoEstado();
  }

  venda(quantidade: number): void {
    this.#produto.quantidade -= quantidade;
    this.verificaAlteracaoEstado();
  }

  abstract verificaAlteracaoEstado(): void;
}