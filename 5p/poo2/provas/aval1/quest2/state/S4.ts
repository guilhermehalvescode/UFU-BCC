import Estado from "../abstracts/Estado";
import Automato, { tokens } from "../concrete/Automato";
import NoTransition from "../Error/NoTransition";
import S3 from "./S3";

export default class S4 extends Estado {
  constructor(automato: Automato) {
    automato.aceita = true;
    super(automato)
  }

  ler(letra: tokens): void {
    if(letra === 'd') {
      this.automato.estado = new S3(this.automato);
    } else {
      throw new NoTransition(this.constructor.name, letra);
    }
  }
}