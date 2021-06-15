package banco.exceptions;

public class OverflowException extends Exception {
  private String message;
  public OverflowException(String message) {
    this.message = message;
  }

  @Override
  public String getMessage() {
    return this.message;
  }
}
