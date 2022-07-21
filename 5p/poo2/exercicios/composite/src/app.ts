import { Or } from "./composite/Operator/Or";
import { Not } from "./composite/Operator/Not";
import { Value } from "./composite/Operand/Value";
import { And } from "./composite/Operator/And";
import { LogicExpression } from "./composite/interface/LogicExpression";

const expression: LogicExpression = new Or(new Not(new And(new Value(true), new Value(true))), new Value(false));

console.log(expression.evaluate());