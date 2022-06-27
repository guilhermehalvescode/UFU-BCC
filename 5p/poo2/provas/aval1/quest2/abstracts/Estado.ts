import Automato, { tokens } from "../concrete/Automato";


export default abstract class Estado {
  #automato: Automato

  constructor(automato: Automato) {
    this.#automato = automato
  }

  get automato() {
    return this.#automato;
  }

  set automato(automato: Automato) {
    this.#automato = automato
  }

  abstract ler(letra: tokens): void;
}