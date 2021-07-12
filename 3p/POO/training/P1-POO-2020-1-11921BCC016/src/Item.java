/*
Aluno: Guilherme Alves Carvalho
Matrícula: 11921BCC016
 */

import javax.swing.JOptionPane;
import java.util.Date;

public class Item {
  private Date data;
  private char tipo;
  private String historico;
  private float valor;

  public Item(char tipo, String historico, float valor) throws Exception {
    this.setData(new Date());
    this.setTipo(tipo);
    this.setHistorico(historico);
    this.setValor(valor);
  }

  public String getData() {
    return this.data.toString();
  }

  private void setData(Date data) throws Exception {
    if(data == null) throw new Exception("Data do Item invalida");
    this.data = data;
  }

  public char getTipo() {
    return this.tipo;
  }


  private void setTipo(char tipo) throws Exception {
    if(tipo != 'C' && tipo != 'D') throw new Exception("Tipo do Item não invalido/não informado");
    this.tipo = tipo;
  }

  public String getHistorico() {
    return this.historico;
  }

  private void setHistorico(String historico) throws Exception {
    if(historico == null || historico.isEmpty()) throw new Exception("Histórico do Item invalido");
    this.historico = historico;
  }

  public float getValor() {
    return this.valor;
  }

  private void setValor(float valor) throws Exception {
    if(valor <= 0) throw new Exception("Valor do Item inválido");
    this.valor = valor;
  }

  @Override
  public String toString() {
    return "Item{" +
            "data=" + this.getData() +
            ", tipo=" + this.getTipo() +
            ", historico='" + this.getHistorico() + '\'' +
            ", valor=" + this.getValor() +
            '}';
  }

  public static void main(String[] args) {
    try {
      Item item1 = new Item('C', "Item 1", 500.43f);
      System.out.println(item1);
    } catch (Exception e) {
      JOptionPane.showMessageDialog(null, e.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
    }
    try {
      Item item2 = new Item('D', "", 200.4f);
      System.out.println(item2);
    } catch (Exception e) {
      JOptionPane.showMessageDialog(null, e.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
    }
    try {
      Item item3 = new Item('C', "Item 3", -100.9f);
      System.out.println(item3);
    } catch (Exception e) {
      JOptionPane.showMessageDialog(null, e.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
    }
    try {
      Item item4 = new Item('A', "Item 4", 500.10f);
      System.out.println(item4);
    } catch (Exception e) {
      JOptionPane.showMessageDialog(null, e.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
    }
  }
}

//  RESULTADO DE EXECUÇÃO DA MAIN
/*
  Item{data=Thu Apr 29 09:59:27 BRT 2021, tipo=C, historico='Item 1', valor=500.43}
 */
