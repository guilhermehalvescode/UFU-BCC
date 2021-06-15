import javax.swing.JOptionPane;

public class TwoNumbers {
    private int a;
    private int b;

    public TwoNumbers () {
        this.a = 0;
        this.b = 0;
    }

    public void showAB(int a, int b) {
        JOptionPane.showMessageDialog(null, "Resultado: " + (a + b), "Soma de A com B!", JOptionPane.INFORMATION_MESSAGE);
    }

    public int obterIntValido(String text) throws Exception {
        while(true) {
            try {
                String num = JOptionPane.showInputDialog(null, text, "Ler inteiro", JOptionPane.QUESTION_MESSAGE);
                return Integer.parseInt(num);
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(null, "Mensagem: Digite um inteiro!", "Erro", JOptionPane.ERROR_MESSAGE);
            } catch (NullPointerException e) {
                JOptionPane.showConfirmDialog(null,
                        "Deseja mesmo encerrar o programa?",
                        "Finalizar programa",
                        JOptionPane.QUESTION_MESSAGE);
                throw new Exception("Programa cancelado pelo usuário!");
            }
        }
    }

    public static void main(String[] args) {
        TwoNumbers tn = new TwoNumbers();
        int n = tn.obterIntValido("Informe n: ");
        int n1 = tn.obterIntValido("Informe n1: ");
        tn.showAB(n, n1);
    }
}
