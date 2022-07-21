import { LogicExpression } from "../interface/LogicExpression";

export class Value implements LogicExpression {
  #value: boolean;

  constructor(value: boolean) {
    this.#value = value;
  }

  evaluate(): boolean {
    return this.#value;
  }
}