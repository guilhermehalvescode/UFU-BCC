import Estado from "../abstracts/Estado";
import S1 from "../state/S1";

export type tokens = 'a' | 'b' | 'c' | 'd'

export default class Automato {
  #aceita: boolean
  #estado: Estado

  constructor() {
    this.#aceita = false;
    this.#estado = new S1(this);
  }

  get aceita(): boolean {
    return this.#aceita;
  }

  set aceita(valor: boolean) {
    this.#aceita = valor
  }

  get estado(): Estado {
    return this.#estado;
  }
  
  set estado(estado: Estado) {
    this.#estado = estado;
  }

  processa(cadeia: string): boolean {
    this.#aceita = false;
    this.#estado = new S1(this);
    
    while(cadeia.length !== 0) {
      try {
        this.#estado.ler(cadeia[0] as tokens)
      } catch(e) {
        return false;
      }
      cadeia = cadeia.substring(1)
    }

    return this.#aceita;
  }
}