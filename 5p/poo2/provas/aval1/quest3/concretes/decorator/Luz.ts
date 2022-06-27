import FormaGeometrica from "../../abstracts/FormaGeometrica";
import FormaGeometricaDecorada from "../../abstracts/FormaGeometricaDecorada";

export default class Luz extends FormaGeometricaDecorada {
  constructor(forma: FormaGeometrica) {
    super(forma);
    this.atributo = "Luz";
  }
}