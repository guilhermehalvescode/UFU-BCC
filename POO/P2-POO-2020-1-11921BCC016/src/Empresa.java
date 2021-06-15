/*
 * Aluno: Guilherme Alves Carvalho
 * Matrícula: 11921BCC016
 * */

import javax.swing.JOptionPane;
import java.util.ArrayList;

public class Empresa {
  public static void main(String[] args) {
    ArrayList<ItemDeEstoque> items = new ArrayList<>();
    try {
      items.add(new Livro("Peter Pan", 70.33f, 3, 5, "Andy Mangels"));
      items.add(new Livro("O menino do pijama listrado", 60.45f, 2, 4, "John Boyne"));
      items.add(new CD("Guns n Roses", 100.50f, 50, 60, 7));
      items.add(new CD("Trio Parada Dura", 30.60f, 200, 300, 10));
      items.add(new DVDs("Jogada de Mestre", 45.60f, 30, 50, 120.6f));
      items.add(new DVDs("Jogada de Mestre 2", 50.60f, 10, 50, 150.6f));
    } catch (IllegalArgumentException e) {
      JOptionPane.showMessageDialog(null, "Dado informado inválido: " + e.getMessage(), "Erro na entrada!", JOptionPane.ERROR_MESSAGE);
    } catch (Exception e) {
      JOptionPane.showMessageDialog(null, "Informação do erro: " + e.getMessage(), "Erro!", JOptionPane.ERROR_MESSAGE);
    }

    //Abaixando estoque
    for (int i = 0; i < items.size(); i++) {
      try {
        JOptionPane.showMessageDialog(null, "Abaixando em " + (i + 1) + " o produto '" + items.get(i).getNome() + "'", "Abaixando Estoque!!", JOptionPane.INFORMATION_MESSAGE);
        items.get(i).baixarEstoque(i + 1);
      } catch (EstoqueBaixoException e) {
        JOptionPane.showMessageDialog(null, e.getMessage(), "Erro no produto -> '" + items.get(i).getNome() + "'", JOptionPane.ERROR_MESSAGE);
      } catch (Exception e) {
        JOptionPane.showMessageDialog(null, "Ocorreu um erro: " + e.getMessage(), "Erro!", JOptionPane.ERROR_MESSAGE);
      } finally {
        JOptionPane.showMessageDialog(null, items.get(i), "Informações sobre o produto -> '" + items.get(i).getNome() + "'", JOptionPane.INFORMATION_MESSAGE);
      }
    }

    //Elevando estoque
    for (int i = 0; i < items.size(); i++) {
      try {
        JOptionPane.showMessageDialog(null, "Elevando em " + (items.size() - i) + " o produto '" + items.get(i).getNome() + "'", "Elevando Estoque!!", JOptionPane.INFORMATION_MESSAGE);
        items.get(i).elevarEstoque(items.size() - i);
      } catch (EstoqueElevadoException e) {
        JOptionPane.showMessageDialog(null, e.getMessage(), "Erro no produto -> '" + items.get(i).getNome() + "'", JOptionPane.ERROR_MESSAGE);
      } catch (Exception e) {
        JOptionPane.showMessageDialog(null, "Ocorreu um erro: " + e.getMessage(), "Erro!", JOptionPane.ERROR_MESSAGE);
      } finally {
        JOptionPane.showMessageDialog(null, items.get(i), "Informações sobre o produto -> '" + items.get(i).getNome() + "'", JOptionPane.INFORMATION_MESSAGE);
      }
    }

    //Calculando total e valor investido
    int totalEstoque = 0;
    float valorInvest = 0;
    for (int i = 0; i < items.size(); i++) {
      JOptionPane.showMessageDialog(null, items.get(i), "Observando produto -> '" + items.get(i).getNome() + "'", JOptionPane.INFORMATION_MESSAGE);
      totalEstoque += items.get(i).getQtdEstoque();
      valorInvest += (items.get(i).getQtdEstoque() * items.get(i).getPreco());
      JOptionPane.showMessageDialog(null, "Quantidade parcial em estoque: " + totalEstoque + "\nQuantidade parcial investido: " + valorInvest, "Valores após avaliação do produto -> '" + items.get(i).getNome() + "'", JOptionPane.INFORMATION_MESSAGE);
    }
    JOptionPane.showMessageDialog(null, "Quantidade total em estoque: " + totalEstoque + "\nQuantidade total investido: " + valorInvest, "Estoque e Valor investido!", JOptionPane.INFORMATION_MESSAGE);
  }
}
