import FormaGeometrica from "./FormaGeometrica";

export default abstract class FormaGeometricaDecorada extends FormaGeometrica {
  #forma: FormaGeometrica

  constructor(forma: FormaGeometrica) {
    super();
    this.#forma = forma;
  }


  desenhar(): string {
    return this.#forma.desenhar() + ", " + super.desenhar()
  }
}