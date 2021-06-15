package banco.exceptions;

public class NotFoundException extends Exception {
  private String message;
  public NotFoundException(String message) {
    this.message = message;
  }

  @Override
  public String getMessage() {
    return this.message;
  }
}
