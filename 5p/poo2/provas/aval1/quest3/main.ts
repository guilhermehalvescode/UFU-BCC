import Circulo from "./concretes/component/Circulo";
import Quadrado from "./concretes/component/Quadrado";
import Luz from "./concretes/decorator/Luz";
import Relevo from "./concretes/decorator/Relevo";


const circulo = new Relevo(new Luz(new Circulo()))
const quadrado = new Luz(new Relevo(new Quadrado()));


console.log("Circulo: ", circulo.desenhar());
console.log("Quadrado: ", quadrado.desenhar());

