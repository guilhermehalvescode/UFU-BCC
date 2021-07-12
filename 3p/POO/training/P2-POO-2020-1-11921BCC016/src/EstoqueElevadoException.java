/*
 * Aluno: Guilherme Alves Carvalho
 * Matrícula: 11921BCC016
 * */
public class EstoqueElevadoException extends Throwable {
  public EstoqueElevadoException() {
    super();
  }

  @Override
  public String getMessage() {
    return "Estoque máximo atingido";
  }
}
