import javax.swing.JOptionPane;
import java.lang.Integer;

public class Vet {
  private int vet[];


  public Vet() {
    this.vet = new int[10];
  }

  public int[] getVet() {
    return vet;
  }

  public void setVet() {
    int index = 0, value;
    String read;
    while(true) {
      try {
        read = JOptionPane.showInputDialog(null,
                "Informe o número (" + (index + 1) + ") do array!",
                "Array de inteiros",
                JOptionPane.QUESTION_MESSAGE);
        value = Integer.parseInt(read);
        this.vet[index++] = value;
        if(value == 0) break;
      } catch (ArrayIndexOutOfBoundsException e) {
        JOptionPane.showMessageDialog(null,
                "Tentativa de inserção fora do Array!\nFinalizando...",
                "Erro!",
                JOptionPane.ERROR_MESSAGE);
        break;
      } catch (NumberFormatException e) {
        JOptionPane.showMessageDialog(null,
                "Informe um valor inteiro!",
                "Erro!",
                JOptionPane.ERROR_MESSAGE);
      }
    }
  }

  public static void main(String[] args) {
    Vet inteiros = new Vet();
    inteiros.setVet();
    int vetor[] = inteiros.getVet();
    StringBuffer message = new StringBuffer("Vetor:");
    for(int i = 0; i < 10; i++) {
     message.append(" [" + vetor[i] + "]");
    }
    JOptionPane.showMessageDialog(null, message, "Valor do vetor!", JOptionPane.INFORMATION_MESSAGE);
    return;
  }
}
