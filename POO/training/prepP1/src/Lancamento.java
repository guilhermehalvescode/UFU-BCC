import java.util.Date;

public class Lancamento {
  private Date data = new Date();
  private char tipo;
  private String historico;
  private float valor;

  public Lancamento(char tipo, String historico, float valor) throws Exception {
    this.setTipo(tipo);
    this.setHistorico(historico);
    this.setValor(valor);
  }

  public String getData() {
    return this.data.toString();
  }

  public char getTipo() {
    return this.tipo;
  }

  private void setTipo(char tipo) throws Exception {
    if(tipo != 'C' && tipo != 'D') throw new Exception("Tipo informado para lançamento inválido!");
    this.tipo = tipo;
  }

  public float getValor() {
    return this.valor;
  }

  public void setValor(float valor) throws Exception {
    if(valor <= 0) throw new Exception("Valor informado para lançamento inválido!");
    this.valor = valor;
  }

  public String getHistorico() {
    return this.historico;
  }

  public void setHistorico(String historico) throws Exception {
    if(historico.isEmpty()) throw new Exception("Histórico informado para lançamento inválido");
    this.historico = historico;
  }

  @Override
  public String toString() {
    return "Lancamento{" +
            "data=" + this.getData() +
            ", tipo=" + this.getTipo() +
            ", historico='" + this.getHistorico() + '\'' +
            ", valor=" + this.getValor() +
            '}';
  }
}
