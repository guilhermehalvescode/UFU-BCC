import javax.swing.JOptionPane;

public class Principal {

  public static void main(String[] args) {
    int tam = 0, escolha;
    String temp, nome;
    float x, y, z, d1, d2;
    Formas[] objs = new Formas[10];
    while(true) {
      temp = JOptionPane.showInputDialog(null,
              getTitle(),
              "Trabalho 2 - Polimorfismo",
              JOptionPane.QUESTION_MESSAGE);
      try {
        escolha = Integer.valueOf(temp);
        if (escolha == 10) return;
        switch (escolha) {
          case 1:
            nome = JOptionPane.showInputDialog(null, "Digite o nome da forma", "Criando circulo", JOptionPane.QUESTION_MESSAGE);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de x", "Criando circulo", JOptionPane.QUESTION_MESSAGE);
            x = Float.valueOf(temp);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de y", "Criando circulo", JOptionPane.QUESTION_MESSAGE);
            y = Float.valueOf(temp);
            objs[tam] = new Circulo(nome, x, y);
            tam++;
            break;
          case 2:
            nome = JOptionPane.showInputDialog(null, "Digite o nome da forma", "Criando cubo", JOptionPane.QUESTION_MESSAGE);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de x", "Criando cubo", JOptionPane.QUESTION_MESSAGE);
            x = Float.valueOf(temp);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de y", "Criando cubo", JOptionPane.QUESTION_MESSAGE);
            y = Float.valueOf(temp);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de z", "Criando cubo", JOptionPane.QUESTION_MESSAGE);
            z = Float.valueOf(temp);
            objs[tam] = new Cubo(nome, x, y, z);
            tam++;
            break;
          case 3:
            nome = JOptionPane.showInputDialog(null, "Digite o nome da forma", "Criando esfera", JOptionPane.QUESTION_MESSAGE);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de x", "Criando esfera", JOptionPane.QUESTION_MESSAGE);
            x = Float.valueOf(temp);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de y", "Criando esfera", JOptionPane.QUESTION_MESSAGE);
            y = Float.valueOf(temp);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de z", "Criando esfera", JOptionPane.QUESTION_MESSAGE);
            z = Float.valueOf(temp);
            objs[tam] = new Esfera(nome, x, y, z);
            tam++;
            break;
          case 4:
            nome = JOptionPane.showInputDialog(null, "Digite o nome da forma", "Criando losango", JOptionPane.QUESTION_MESSAGE);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de x", "Criando losango", JOptionPane.QUESTION_MESSAGE);
            x = Float.valueOf(temp);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de y", "Criando losango", JOptionPane.QUESTION_MESSAGE);
            y = Float.valueOf(temp);
            temp = JOptionPane.showInputDialog(null, "Digite o valor da primeira diagonal", "Criando losango", JOptionPane.QUESTION_MESSAGE);
            d1 = Float.valueOf(temp);
            temp = JOptionPane.showInputDialog(null, "Digite o valor da segunda diagonal", "Criando losango", JOptionPane.QUESTION_MESSAGE);
            d2 = Float.valueOf(temp);
            objs[tam] = new Losango(nome, x, y, d1, d2);
            tam++;
            break;
          case 5:
            nome = JOptionPane.showInputDialog(null, "Digite o nome da forma", "Criando piramide", JOptionPane.QUESTION_MESSAGE);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de x", "Criando piramide", JOptionPane.QUESTION_MESSAGE);
            x = Float.valueOf(temp);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de y", "Criando piramide", JOptionPane.QUESTION_MESSAGE);
            y = Float.valueOf(temp);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de z", "Criando piramide", JOptionPane.QUESTION_MESSAGE);
            z = Float.valueOf(temp);
            objs[tam] = new PiramideQuadrangular(nome, x, y, z);
            tam++;
            break;
          case 6:
            nome = JOptionPane.showInputDialog(null, "Digite o nome da forma", "Criando quadrado", JOptionPane.QUESTION_MESSAGE);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de x", "Criando quadrado", JOptionPane.QUESTION_MESSAGE);
            x = Float.valueOf(temp);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de y", "Criando quadrado", JOptionPane.QUESTION_MESSAGE);
            y = Float.valueOf(temp);
            objs[tam] = new Quadrado(nome, x, y);
            tam++;
            break;
          case 7:
            nome = JOptionPane.showInputDialog(null, "Digite o nome da forma", "Criando retangulo", JOptionPane.QUESTION_MESSAGE);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de x", "Criando retangulo", JOptionPane.QUESTION_MESSAGE);
            x = Float.valueOf(temp);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de y", "Criando retangulo", JOptionPane.QUESTION_MESSAGE);
            y = Float.valueOf(temp);
            objs[tam] = new Retangulo(nome, x, y);
            tam++;
            break;
          case 8:
            nome = JOptionPane.showInputDialog(null, "Digite o nome da forma", "Criando triangulo", JOptionPane.QUESTION_MESSAGE);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de x", "Criando triangulo", JOptionPane.QUESTION_MESSAGE);
            x = Float.valueOf(temp);
            temp = JOptionPane.showInputDialog(null, "Digite o valor de y", "Criando triangulo", JOptionPane.QUESTION_MESSAGE);
            y = Float.valueOf(temp);
            objs[tam] = new Triangulo(nome, x, y);
            tam++;
            break;
          case 9:
            for (int i = 0; i < tam; i++) {
              if (objs[i] instanceof Tridimensional) {
                Tridimensional tri = (Tridimensional) objs[i];
                JOptionPane.showMessageDialog(null, tri + "\nArea: " + String.valueOf(tri.obterArea()) + "\nVolume: " + String.valueOf(tri.obterVolume()), "Forma " + (i + 1) + " Tridimensional", JOptionPane.INFORMATION_MESSAGE);
              } else {
                JOptionPane.showMessageDialog(null, objs[i] + "\nArea: " + String.valueOf(objs[i].obterArea()), "Forma " + (i + 1) + " Bidimensional", JOptionPane.INFORMATION_MESSAGE);
              }
            }
            break;
          default:
            throw new IllegalStateException("Escolha " + escolha + " inválido!");
        }
      } catch (ArrayIndexOutOfBoundsException e) {
        JOptionPane.showMessageDialog(null, "Tamanho limite de formas atingido!", "Aviso!!", JOptionPane.INFORMATION_MESSAGE);
      } catch (MedidaInvalidaException e) {
        JOptionPane.showMessageDialog(null, "Erro na medida informada: " + e.getMessage(), "Erro!!", JOptionPane.ERROR_MESSAGE);
      } catch (Exception e) {
        int esc;
        if(e.getMessage().equals("null")) {
          esc = JOptionPane.showConfirmDialog(null, "Deseja encerrar o programa?", "Trabalho 2 - Polimorfismo", JOptionPane.OK_CANCEL_OPTION);
          if(esc == JOptionPane.OK_OPTION) return;
        } else {
          JOptionPane.showMessageDialog(null, "Informações sobre o erro: " + e.getMessage(), "Erro!!", JOptionPane.ERROR_MESSAGE);
        }
      }
    }
  }

  private static String getTitle() {
    return "[1] Criar um círculo\n" +
            "[2] Criar um cubo\n" +
            "[3] Criar um esfera\n" +
            "[4] Criar um losango\n" +
            "[5] Criar um piramide\n" +
            "[6] Criar um quadrado\n" +
            "[7] Criar um retangulo\n" +
            "[8] Criar um triangulo\n" +
            "[9] Listar formas\n" +
            "[10] Sair do sistema\n";
  }
}
