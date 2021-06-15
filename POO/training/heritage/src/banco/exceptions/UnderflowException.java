package banco.exceptions;

public class UnderflowException extends Exception {
  private String message;
  public UnderflowException(String message) {
    this.message = message;
  }

  @Override
  public String getMessage() {
    return this.message;
  }
}
