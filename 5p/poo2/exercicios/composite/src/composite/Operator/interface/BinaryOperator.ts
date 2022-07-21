import { LogicExpression } from "../../interface/LogicExpression";

export abstract class BinaryOperator implements LogicExpression {
  #op1: LogicExpression;
  #op2: LogicExpression;

  constructor(op1: LogicExpression, op2: LogicExpression) {
    this.#op1 = op1;
    this.#op2 = op2;
  }

  get op1(): LogicExpression {
    return this.#op1;
  }

  get op2(): LogicExpression {
    return this.#op2;
  }

  abstract evaluate(): boolean;
}