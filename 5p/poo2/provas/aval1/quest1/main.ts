import Produto from "./concrete/Produto";

const produto = new Produto();

console.log("Estado: ", produto.estado.constructor.name)
console.log("Venda de 30");
produto.venda(30);

console.log("Estado: ", produto.estado.constructor.name)
console.log("Compra de 2");
produto.compra(2);

console.log("Estado: ", produto.estado.constructor.name)
console.log("Compra de 10");
produto.compra(10);

console.log("Estado: ", produto.estado.constructor.name)
console.log("Venda de 12");
produto.venda(12);

console.log("Estado: ", produto.estado.constructor.name)
