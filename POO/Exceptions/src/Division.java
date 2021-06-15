import javax.swing.JOptionPane;

public class Division {
  private float a;
  private float b;


  public Division() {
    try {
      this.a = this.obterNumeroValido("Digite o valor de a: ");
      this.b = this.obterNumeroValido("Digite o valor de b: ");
    } catch (Exception e) {
      JOptionPane.showMessageDialog(null, "Mensagem: " + e.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
      System.exit(0);
    }
  }

  public float obterNumeroValido(String text) throws Exception {
    while(true) {
      try {
        String num = JOptionPane.showInputDialog(null, text, "Ler número", JOptionPane.QUESTION_MESSAGE);
        return Float.parseFloat(num);
      } catch (NumberFormatException e) {
        JOptionPane.showMessageDialog(null, "Mensagem: Digite um numero!", "Erro", JOptionPane.ERROR_MESSAGE);
      } catch (NullPointerException e) {
        int r = JOptionPane.showConfirmDialog(null,
                "Deseja mesmo encerrar o programa?",
                "Finalizar programa",
                JOptionPane.OK_CANCEL_OPTION);
        if(r == JOptionPane.OK_OPTION)
          throw new Exception("Programa cancelado pelo usuário!");
      }
    }
  }

  public void div() throws ArithmeticException {
    try {
      if(this.b == 0) throw new ArithmeticException("Divisão por zero");
      JOptionPane.showMessageDialog(null, "Resultado da divisão: " + (this.a/this.b), "Divisão",JOptionPane.INFORMATION_MESSAGE);
    } catch (ArithmeticException e) {
      JOptionPane.showMessageDialog(null, "Mensagem: " + e.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
      throw e;
    }
  }

  public static void main(String[] args) {
    Division nums = new Division();
    try {
      nums.div();
    } catch (Exception err) {
      JOptionPane.showMessageDialog(null, "Mensagem: " + err.getMessage(), "Programa finalizado!", JOptionPane.INFORMATION_MESSAGE);
    }
  }
}
