import FormaGeometrica from "../../abstracts/FormaGeometrica";
import FormaGeometricaDecorada from "../../abstracts/FormaGeometricaDecorada";

export default class Relevo extends FormaGeometricaDecorada {
  constructor(forma: FormaGeometrica) {
    super(forma);
    this.atributo = "Relevo";
  }
}