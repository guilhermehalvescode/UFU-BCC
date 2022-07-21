import { LogicExpression } from "../interface/LogicExpression";
import { BinaryOperator } from "./interface/BinaryOperator";

export class Xor extends BinaryOperator {

  constructor(op1: LogicExpression, op2: LogicExpression) {
    super(op1, op2);
  }


  evaluate(): boolean {
    return this.op1.evaluate() !== this.op2.evaluate();
  }
}