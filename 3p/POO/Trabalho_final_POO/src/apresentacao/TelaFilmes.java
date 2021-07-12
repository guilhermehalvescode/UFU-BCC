package apresentacao;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;

import java.awt.Font;
import javax.swing.JTextField;

import negocio.IFachadaSistema;
import negocio.Sistema;
import negocio.Video.filme.Filme;

import javax.swing.JTextArea;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class TelaFilmes extends JFrame {

	private JFrame frame;
	private JTextField text_nome_filme;
	private JTextField text_duracao_filme;
	private JTextField text_genero_filme;
	private JTextField text_ano_lancamento_filme;
	private IFachadaSistema IF;
	private Filme filme;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					TelaFilmes window = new TelaFilmes();
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
	public TelaFilmes() {
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
		}
		frame.setBounds(100, 100, 640, 452);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);

		JLabel lblFilmes = new JLabel("Filmes");
		lblFilmes.setFont(new Font("Georgia", Font.BOLD, 99));
		lblFilmes.setBounds(24, 0, 450, 119);
		frame.getContentPane().add(lblFilmes);

		text_nome_filme = new JTextField();
		text_nome_filme.setColumns(10);
		text_nome_filme.setBounds(126, 131, 114, 19);
		frame.getContentPane().add(text_nome_filme);

		JLabel lblNomeDaSerie = new JLabel("Nome do Filme");
		lblNomeDaSerie.setBounds(12, 133, 109, 15);
		frame.getContentPane().add(lblNomeDaSerie);

		JLabel lblDuracao = new JLabel("Duração");
		lblDuracao.setBounds(250, 133, 59, 15);
		frame.getContentPane().add(lblDuracao);

		text_duracao_filme = new JTextField();
		text_duracao_filme.setColumns(10);
		text_duracao_filme.setBounds(314, 131, 114, 19);
		frame.getContentPane().add(text_duracao_filme);

		JLabel lblGenero = new JLabel("Gênero");
		lblGenero.setBounds(432, 133, 52, 15);
		frame.getContentPane().add(lblGenero);

		text_genero_filme = new JTextField();
		text_genero_filme.setColumns(10);
		text_genero_filme.setBounds(502, 131, 114, 19);
		frame.getContentPane().add(text_genero_filme);

		JLabel lblAnoDeLanamento = new JLabel("Ano de Lançamento");
		lblAnoDeLanamento.setBounds(34, 164, 140, 15);
		frame.getContentPane().add(lblAnoDeLanamento);

		text_ano_lancamento_filme = new JTextField();
		text_ano_lancamento_filme.setColumns(10);
		text_ano_lancamento_filme.setBounds(179, 162, 114, 19);
		frame.getContentPane().add(text_ano_lancamento_filme);

		JLabel lblSinopse = new JLabel("Sinopse");
		lblSinopse.setBounds(305, 164, 57, 15);
		frame.getContentPane().add(lblSinopse);

		JTextArea text_filme_sinopse = new JTextArea();
		text_filme_sinopse.setBounds(380, 164, 140, 87);
		text_filme_sinopse.setLineWrap(true);
		text_filme_sinopse.setWrapStyleWord(true);
		text_filme_sinopse.setAutoscrolls(true);
		JScrollPane scrollTextArea = new JScrollPane(text_filme_sinopse);
		scrollTextArea.setBounds(380, 164, 140, 87);
		frame.getContentPane().add(scrollTextArea);

		JButton btn_cadastrar_Filme = new JButton("CADASTRAR FILME");
		btn_cadastrar_Filme.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				Filme filme = new Filme();
				try {
					filme.setNome(text_nome_filme.getText());
					filme.setDuracao(Double.parseDouble(text_duracao_filme.getText()));
					filme.setGenero(text_genero_filme.getText());
					filme.setAno(Integer.parseInt(text_ano_lancamento_filme.getText()));
					filme.setSinopse(text_filme_sinopse.getText());
					IF.cadastrarFilme(filme);
					JPanelMessages.sucesso(btn_cadastrar_Filme, "Filme " + filme.getNome() + " Cadastrado com sucesso");
					text_nome_filme.setText("");
					text_duracao_filme.setText("");
					text_genero_filme.setText("");
					text_ano_lancamento_filme.setText("");
					text_filme_sinopse.setText("");

				} catch (Exception e) {
					JPanelMessages.erro(btn_cadastrar_Filme, "Não é possível cadastrar filme");
				}
			}
		});
		btn_cadastrar_Filme.setBounds(12, 348, 197, 25);
		frame.getContentPane().add(btn_cadastrar_Filme);

		JButton btnBuscarFilme = new JButton("BUSCAR FILME");
		btnBuscarFilme.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					filme = IF.buscarFilme(text_nome_filme.getText());
					String
									nome = filme.getNome(),
									duracao = String.valueOf(filme.getDuracao()),
									genero = filme.getGenero(),
									ano = String.valueOf(filme.getAno()),
									sinopse = filme.getSinopse();
					text_nome_filme.setText(nome);
					text_filme_sinopse.setText(sinopse);
					text_genero_filme.setText(genero);
					text_duracao_filme.setText(duracao);
					text_ano_lancamento_filme.setText(ano);
					JPanelMessages.sucesso(btn_cadastrar_Filme, "Nome: " + nome + "\nDuração: " + duracao + "\nGênero: "
									+ genero + "\nAno de Lançamento: " + ano + "\nSinopse: " + sinopse);
				} catch (Exception e) {
					JPanelMessages.erro(btnBuscarFilme, "Filme '"+ text_nome_filme.getText()+"' nao existe na base de dados");
				}
			}
		});
		btnBuscarFilme.setBounds(240, 348, 160, 25);
		frame.getContentPane().add(btnBuscarFilme);

		JButton btnCancelar = new JButton("CANCELAR");
		btnCancelar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (text_nome_filme.getText().length() <= 0 && text_duracao_filme.getText().length() <= 0
						&& text_filme_sinopse.getText().length() <= 0
						&& text_ano_lancamento_filme.getText().length() <= 0
						&& text_genero_filme.getText().length() <= 0) {
					JPanelMessages.sucesso(btn_cadastrar_Filme, "Todos os campos estão vazios");
				} else {
					text_nome_filme.setText("");
					text_duracao_filme.setText("");
					text_filme_sinopse.setText("");
					text_ano_lancamento_filme.setText("");
					text_genero_filme.setText("");
				}
			}
		});
		btnCancelar.setBounds(424, 348, 117, 25);
		frame.getContentPane().add(btnCancelar);

		JButton btnSair = new JButton("SAIR");
		btnSair.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				System.exit(0);
			}
		});
		btnSair.setBounds(434, 385, 101, 25);
		frame.getContentPane().add(btnSair);

		JButton btnAtualizar_Filme = new JButton("ATUALIZAR");
		btnAtualizar_Filme.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					filme.setNome(text_nome_filme.getText());
					filme.setDuracao(Double.parseDouble(text_duracao_filme.getText()));
					filme.setAno(Integer.parseInt(text_ano_lancamento_filme.getText()));
					filme.setGenero(text_genero_filme.getText());
					filme.setSinopse(text_filme_sinopse.getText());
					IF.atualizarFilme(filme);
					JPanelMessages.sucesso(btnAtualizar_Filme, "Filme '" + filme.getNome() + "' atualizado com sucesso");
				} catch (Exception e) {
					JPanelMessages.erro(btnAtualizar_Filme, "Não é possível atualizar o filme");
				}
			}
		});
		btnAtualizar_Filme.setBounds(252, 385, 117, 25);
		frame.getContentPane().add(btnAtualizar_Filme);

		JButton btn_excluir_filme = new JButton("EXCLUIR");
		btn_excluir_filme.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					IF.excluirFilme(text_nome_filme.getText());
					JPanelMessages.sucesso(btn_excluir_filme, "Filme '" + text_nome_filme.getText() + "' excluido com sucesso");
				} catch (Exception e) {
					JPanelMessages.erro(btn_excluir_filme, "Filme '" + text_nome_filme.getText() + "' não excluido(não existe)");
				}
			}
		});
		btn_excluir_filme.setBounds(45, 385, 117, 25);
		frame.getContentPane().add(btn_excluir_filme);
	}

}
