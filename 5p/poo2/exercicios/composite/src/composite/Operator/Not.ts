import { LogicExpression } from "../interface/LogicExpression";
import { UnaryOperator } from "./interface/UnaryOperator";

export class Not extends UnaryOperator {

  constructor(op1: LogicExpression) {
    super(op1);
  }


  evaluate(): boolean {
    return !this.op1.evaluate();
  }
}