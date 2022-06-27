import Automato from "./concrete/Automato";


const automato = new Automato();

console.log("1.aaacdb: ", automato.processa("aaacdb"))
console.log("2.ababacdaaac: ", automato.processa("ababacdaaac"))
console.log("3.abcdb: ", automato.processa("abcdb"))
console.log("4.acda: ", automato.processa("acda"))
console.log("5.acdbdb: ", automato.processa("acdbdb"))
