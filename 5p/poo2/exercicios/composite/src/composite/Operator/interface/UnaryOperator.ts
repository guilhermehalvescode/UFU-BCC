import { LogicExpression } from "../../interface/LogicExpression";

export abstract class UnaryOperator implements LogicExpression {
  #op1: LogicExpression;

  constructor(op1: LogicExpression) {
    this.#op1 = op1;
  }

  get op1(): LogicExpression {
    return this.#op1;
  }


  abstract evaluate(): boolean;
}