import Estado from "../abstracts/Estado";
import Automato, { tokens } from "../concrete/Automato";
import NoTransition from "../Error/NoTransition";
import S2 from "./S2";

export default class S1 extends Estado {
  
  constructor(automato: Automato) {
    automato.aceita = false;
    super(automato)
  }

  ler(letra: tokens): void {
    if(letra === 'a') {
      this.automato.estado = new S2(this.automato);
    } else {
      throw new NoTransition(this.constructor.name, letra);
    }
  }
}