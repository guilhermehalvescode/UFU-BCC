import Estado from "../abstracts/Estado";
import Automato, { tokens } from "../concrete/Automato";
import NoTransition from "../Error/NoTransition";
import S1 from "./S1";
import S4 from "./S4";

export default class S3 extends Estado {
  constructor(automato: Automato) {
    automato.aceita = false;
    super(automato)
  }

  ler(letra: tokens): void {
    if(letra === 'a') {
      this.automato.estado = new S1(this.automato);
    } else if (letra === 'b') {
      this.automato.estado = new S4(this.automato);
    } else {
      throw new NoTransition(this.constructor.name, letra)
    }
  }
}