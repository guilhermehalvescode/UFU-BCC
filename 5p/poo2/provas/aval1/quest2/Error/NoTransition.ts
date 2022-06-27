import { tokens } from "../concrete/Automato";

export default class NoTransition extends Error {
  constructor(from: string, transition: tokens) {
    super(`${from}: No transition with '${transition}'`)
  }
}