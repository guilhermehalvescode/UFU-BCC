export default abstract class FormaGeometrica {
  #atributo: string = '';

  get atributo() {
    return this.#atributo;
  }

  set atributo(atributo: string) {
    this.#atributo = atributo;
  }

  desenhar() {
    return this.#atributo
  }
}