package apresentacao;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;

import negocio.IFachadaSistema;
import negocio.Sistema;
import negocio.Video.serie.Series;

import java.awt.Font;
import javax.swing.JTextArea;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class TelaSeries extends JFrame {

  private JFrame frame;
  private JTextField text_nome_serie;
  private JTextField text_duracao_serie;
  private JTextField text_genero_serie;
  private JTextField text_ano_serie_lancamento;
  private JTextField text_numero_total_ep_serie;
  private JTextField text_numero_total_temporadas;
  private IFachadaSistema IF;
  private Series series;

  /**
   * Launch the application.
   */
  public static void main(String[] args) {
    EventQueue.invokeLater(new Runnable() {
      public void run() {
        try {
          TelaSeries window = new TelaSeries();
          window.frame.setVisible(true);
        } catch (Exception e) {
          e.printStackTrace();
        }
      }
    });
  }

  /**
   * Create the application.
   */
  public TelaSeries() {
    initialize();
  }

  /**
   * Initialize the contents of the frame.
   */
  private void initialize() {
    frame = new JFrame();
    try {
      IF = Sistema.getFachada();
    } catch (Exception e) {
      JPanelMessages.erro(this, e.getMessage());
      e.printStackTrace();
    }
    frame.setBounds(100, 100, 804, 564);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.getContentPane().setLayout(null);

    JLabel lblSerie = new JLabel("Serie");
    lblSerie.setFont(new Font("Georgia", Font.BOLD, 99));
    lblSerie.setBounds(159, 0, 334, 119);
    frame.getContentPane().add(lblSerie);

    text_nome_serie = new JTextField();
    text_nome_serie.setColumns(10);
    text_nome_serie.setBounds(126, 165, 114, 19);
    frame.getContentPane().add(text_nome_serie);

    JLabel lblNomeDaSerie = new JLabel("Nome da Série");
    lblNomeDaSerie.setBounds(12, 167, 109, 15);
    frame.getContentPane().add(lblNomeDaSerie);

    JLabel lblDuracao = new JLabel("Duração");
    lblDuracao.setBounds(252, 167, 59, 15);
    frame.getContentPane().add(lblDuracao);

    text_duracao_serie = new JTextField();
    text_duracao_serie.setColumns(10);
    text_duracao_serie.setBounds(316, 165, 114, 19);
    frame.getContentPane().add(text_duracao_serie);

    JLabel lblGenero = new JLabel("Gênero");
    lblGenero.setBounds(452, 167, 52, 15);
    frame.getContentPane().add(lblGenero);

    text_genero_serie = new JTextField();
    text_genero_serie.setColumns(10);
    text_genero_serie.setBounds(522, 165, 114, 19);
    frame.getContentPane().add(text_genero_serie);

    JLabel lblAnoDeLanamento = new JLabel("Ano de Lançamento");
    lblAnoDeLanamento.setBounds(12, 190, 140, 15);
    frame.getContentPane().add(lblAnoDeLanamento);

    text_ano_serie_lancamento = new JTextField();
    text_ano_serie_lancamento.setColumns(10);
    text_ano_serie_lancamento.setBounds(157, 188, 114, 19);
    frame.getContentPane().add(text_ano_serie_lancamento);

    JLabel lblSinopse = new JLabel("Sinopse");
    lblSinopse.setBounds(283, 190, 57, 15);
    frame.getContentPane().add(lblSinopse);

    JTextArea text_serie_sinopse = new JTextArea();
    text_serie_sinopse.setLineWrap(true);
    text_serie_sinopse.setWrapStyleWord(true);
    text_serie_sinopse.setAutoscrolls(true);
    JScrollPane scrollTextArea = new JScrollPane(text_serie_sinopse);
    scrollTextArea.setBounds(358, 190, 140, 87);

    text_serie_sinopse.setBounds(358, 190, 140, 87);
    frame.getContentPane().add(scrollTextArea);

    JLabel lbl_n_t_ep = new JLabel("Total de Episódios");
    lbl_n_t_ep.setBounds(522, 213, 135, 15);
    frame.getContentPane().add(lbl_n_t_ep);

    text_numero_total_ep_serie = new JTextField();
    text_numero_total_ep_serie.setColumns(10);
    text_numero_total_ep_serie.setBounds(678, 211, 114, 19);
    frame.getContentPane().add(text_numero_total_ep_serie);

    JLabel lbl_n_t_ep_1 = new JLabel("Número Total de Temporadas");
    lbl_n_t_ep_1.setBounds(26, 302, 218, 15);
    frame.getContentPane().add(lbl_n_t_ep_1);

    text_numero_total_temporadas = new JTextField();
    text_numero_total_temporadas.setColumns(10);
    text_numero_total_temporadas.setBounds(240, 300, 114, 19);
    frame.getContentPane().add(text_numero_total_temporadas);

    JButton btn_cadastrar_Serie = new JButton("CADASTRAR SERIE");
    btn_cadastrar_Serie.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0) {
        Series series = new Series();
        try {
          series.setNome(text_nome_serie.getText());
          series.setDuracao(Double.parseDouble(text_duracao_serie.getText()));
          series.setGenero(text_genero_serie.getText());
          series.setSinopse(text_serie_sinopse.getText());
          series.setAno(Integer.parseInt(text_ano_serie_lancamento.getText()));
          series.setNumero_temporada(Integer.parseInt(text_numero_total_temporadas.getText()));
          series.setNumero_total_ep(Integer.parseInt(text_numero_total_ep_serie.getText()));
          IF.cadastrarSeries(series);
          JPanelMessages.sucesso(btn_cadastrar_Serie, "Série '" + series.getNome() + "' cadastrada com sucesso");
          text_nome_serie.setText("");
          text_duracao_serie.setText("");
          text_ano_serie_lancamento.setText("");
          text_genero_serie.setText("");
          text_serie_sinopse.setText("");
          text_numero_total_ep_serie.setText("");
          text_numero_total_temporadas.setText("");
        } catch (Exception e) {
          JPanelMessages.erro(btn_cadastrar_Serie, "Não é possível cadastrar a série");
        }

      }
    });
    btn_cadastrar_Serie.setBounds(12, 383, 197, 25);
    frame.getContentPane().add(btn_cadastrar_Serie);

    JButton btnBuscarSerie = new JButton("BUSCAR SERIE");
    btnBuscarSerie.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0) {
        try {
          series = IF.buscarSeries(text_nome_serie.getText());
          String
                  nome = series.getNome(),
                  sinopse = series.getSinopse(),
                  genero = series.getGenero(),
                  nTotEp = String.valueOf(series.getNumero_total_ep()),
                  nTotTemp = String.valueOf(series.getNumero_temporada()),
                  ano = String.valueOf(series.getAno()),
                  duracao = String.valueOf(series.getDuracao());
          text_nome_serie.setText(nome);
          text_serie_sinopse.setText(sinopse);
          text_genero_serie.setText(genero);
          text_numero_total_ep_serie.setText(nTotEp);
          text_numero_total_temporadas.setText(nTotTemp);
          text_ano_serie_lancamento.setText(ano);
          text_duracao_serie.setText(duracao);
          JPanelMessages.sucesso(btnBuscarSerie, "Nome: " + nome + "\nGênero: " + genero + "\nNúmero de episódios: "
                  + nTotEp + "\nNúmero de temporadas: " + nTotTemp
                  + "\nDuração: " + duracao + "\nSinopse: " + sinopse
                  + "\nAno: " + ano);
        } catch (Exception e) {
          JPanelMessages.erro(btnBuscarSerie, "Série '" + text_nome_serie.getText() + "' não existe na base de dados");
        }

      }
    });
    btnBuscarSerie.setBounds(240, 383, 160, 25);
    frame.getContentPane().add(btnBuscarSerie);

    JButton btnCancelar = new JButton("CANCELAR");
    btnCancelar.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0) {
        if (text_nome_serie.getText().length() <= 0 && text_duracao_serie.getText().length() <= 0
                && text_ano_serie_lancamento.getText().length() <= 0
                && text_genero_serie.getText().length() <= 0 && text_serie_sinopse.getText().length() <= 0
                && text_numero_total_temporadas.getText().length() <= 0
                && text_numero_total_ep_serie.getText().length() <= 0) {
          JPanelMessages.erro(btn_cadastrar_Serie, "Os campos já estão vazios");
        } else {
          text_nome_serie.setText("");
          text_duracao_serie.setText("");
          text_ano_serie_lancamento.setText("");
          text_genero_serie.setText("");
          text_serie_sinopse.setText("");
          text_numero_total_ep_serie.setText("");
          text_numero_total_temporadas.setText("");
        }
      }
    });
    btnCancelar.setBounds(424, 383, 117, 25);
    frame.getContentPane().add(btnCancelar);

    JButton btnExcluir = new JButton("EXCLUIR");
    btnExcluir.setBounds(-137, 437, 117, 25);
    frame.getContentPane().add(btnExcluir);

    JButton btnatualizarserie = new JButton("ATUALIZAR");
    btnatualizarserie.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0) {
        try {
          series.setNome(text_nome_serie.getText());
          series.setDuracao(Double.parseDouble(text_duracao_serie.getText()));
          series.setAno(Integer.parseInt(text_ano_serie_lancamento.getText()));
          series.setGenero(text_genero_serie.getText());
          series.setSinopse(text_serie_sinopse.getText());
          series.setNumero_total_ep(Integer.parseInt(text_numero_total_ep_serie.getText()));
          series.setNumero_temporada(Integer.parseInt(text_numero_total_temporadas.getText()));
          IF.atualizarSeries(series);
          JPanelMessages.sucesso(btnatualizarserie, "Série '" + series.getNome() + "' atualizado com sucesso");
        } catch (Exception e) {
          JPanelMessages.erro(btnatualizarserie, "Não é possível atualizar a série");
        }
      }
    });
    btnatualizarserie.setBounds(252, 420, 117, 25);
    frame.getContentPane().add(btnatualizarserie);

    JButton btnSair = new JButton("SAIR");
    btnSair.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0) {
        System.exit(0);
      }
    });
    btnSair.setBounds(434, 420, 101, 25);
    frame.getContentPane().add(btnSair);

    JButton btn_serie = new JButton("EXCLUIR");
    btn_serie.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0) {
        try {
          IF.excluirSerie(text_nome_serie.getText());
          JPanelMessages.sucesso(btnCancelar, "Série '" + text_nome_serie.getText() + "' excluida com sucesso");
        } catch (Exception e) {
          JPanelMessages.erro(btnExcluir, "Série '" + text_nome_serie.getText() + "' não excluida(não existe)");
        }
      }
    });
    btn_serie.setBounds(45, 420, 117, 25);
    frame.getContentPane().add(btn_serie);
  }

}
