package apresentacao;

import java.awt.EventQueue;

import javax.swing.*;

import java.awt.Color;
import java.awt.Font;

import negocio.IFachadaSistema;
import negocio.Sistema;
import negocio.Video.anime.Anime;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class TelaAnime extends JFrame {

	private JFrame frame;
	private JTextField text_nome_anime;
	private JTextField text_duracao_anime;
	private JTextField text_anime_genero;
	private JTextField text_anime_ano_lacamento;
	private JTextField text_anime_n_Ep;
	private JTextField text_n_t_temporada;
	private IFachadaSistema IF;
	private Anime anime;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					TelaAnime window = new TelaAnime();
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
	public TelaAnime() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		try {
			IF = Sistema.getFachada();
		} catch (Exception e) {
			JPanelMessages.erro(this, e.getMessage());
		}
		frame = new JFrame();
		frame.getContentPane().setForeground(Color.WHITE);
		frame.setBounds(100, 100, 656, 424);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);

		JLabel lblNewLabel = new JLabel("Animes");
		lblNewLabel.setBounds(47, 5, (int) (frame.getWidth() * 0.8), 113);
		lblNewLabel.setFont(new Font("Georgia", Font.BOLD, 99));
		lblNewLabel.setForeground(Color.BLACK);
		frame.getContentPane().add(lblNewLabel);

		JLabel lblNomeDoAnime = new JLabel("Nome do anime");
		lblNomeDoAnime.setBounds(6, 125, 109, 15);
		frame.getContentPane().add(lblNomeDoAnime);

		text_nome_anime = new JTextField();
		text_nome_anime.setBounds(120, 123, 114, 19);
		frame.getContentPane().add(text_nome_anime);
		text_nome_anime.setColumns(10);

		JLabel lblDuracao = new JLabel("Duracao");
		lblDuracao.setBounds(239, 125, 59, 15);
		frame.getContentPane().add(lblDuracao);

		text_duracao_anime = new JTextField();
		text_duracao_anime.setBounds(303, 123, 114, 19);
		frame.getContentPane().add(text_duracao_anime);
		text_duracao_anime.setColumns(10);

		JLabel lblGenero = new JLabel("Genero");
		lblGenero.setBounds(422, 125, 52, 15);
		frame.getContentPane().add(lblGenero);

		text_anime_genero = new JTextField();
		text_anime_genero.setBounds(492, 123, 114, 19);
		frame.getContentPane().add(text_anime_genero);
		text_anime_genero.setColumns(10);

		JLabel lblAnoDeLanamento = new JLabel("Ano de Lancamento");
		lblAnoDeLanamento.setBounds(136, 149, 140, 15);
		frame.getContentPane().add(lblAnoDeLanamento);

		text_anime_ano_lacamento = new JTextField();
		text_anime_ano_lacamento.setBounds(281, 147, 114, 19);
		frame.getContentPane().add(text_anime_ano_lacamento);
		text_anime_ano_lacamento.setColumns(10);

		JLabel lblSinopse = new JLabel("Sinopse");
		lblSinopse.setBounds(417, 154, 57, 15);
		frame.getContentPane().add(lblSinopse);

		JTextArea text_anime_sinopse = new JTextArea();
		text_anime_sinopse.setBounds(492, 154, 140, 87);
		text_anime_sinopse.setLineWrap(true);
		text_anime_sinopse.setWrapStyleWord(true);
		text_anime_sinopse.setAutoscrolls(true);
		JScrollPane scrollTextArea = new JScrollPane(text_anime_sinopse);
		scrollTextArea.setBounds(492, 154, 140, 87);
		frame.getContentPane().add(scrollTextArea);

		JLabel lbl_n_t_ep = new JLabel("Numero Total de Episodios");
		lbl_n_t_ep.setBounds(6, 176, 135, 15);
		frame.getContentPane().add(lbl_n_t_ep);

		text_anime_n_Ep = new JTextField();
		text_anime_n_Ep.setBounds(159, 174, 114, 19);
		frame.getContentPane().add(text_anime_n_Ep);
		text_anime_n_Ep.setColumns(10);

		JLabel lbl_n_t_ep_1 = new JLabel("Numero Total de Temporadas");
		lbl_n_t_ep_1.setBounds(6, 224, 218, 15);
		frame.getContentPane().add(lbl_n_t_ep_1);

		text_n_t_temporada = new JTextField();
		text_n_t_temporada.setColumns(10);
		text_n_t_temporada.setBounds(220, 222, 114, 19);
		frame.getContentPane().add(text_n_t_temporada);

		JButton btnCadastrarAnime = new JButton("CADASTRAR ANIME");
		btnCadastrarAnime.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				anime = new Anime();
				try {
					anime.setNome(text_nome_anime.getText());
					anime.setDuracao(Double.parseDouble(text_duracao_anime.getText()));
					anime.setAno(Integer.parseInt(text_anime_ano_lacamento.getText()));
					anime.setGenero(text_anime_genero.getText());
					anime.setSinopse(text_anime_sinopse.getText());
					anime.setNumero_total_ep(Integer.parseInt(text_anime_n_Ep.getText()));
					anime.setNumero_temporada(Integer.parseInt(text_n_t_temporada.getText()));
					IF.cadastrarAnime(anime);
					JPanelMessages.sucesso(btnCadastrarAnime, "Anime '" + anime.getNome() + "' cadastrado com sucesso");
					text_nome_anime.setText("");
					text_duracao_anime.setText("");
					text_anime_ano_lacamento.setText("");
					text_anime_genero.setText("");
					text_anime_sinopse.setText("");
					text_anime_n_Ep.setText("");
					text_n_t_temporada.setText("");

				} catch (Exception e) {
					JPanelMessages.erro(btnCadastrarAnime, "Erro: " + e.getMessage());
				}
			}
		});
		btnCadastrarAnime.setBounds(27, 285, 197, 25);
		frame.getContentPane().add(btnCadastrarAnime);

		JButton btnBuscarAnime = new JButton("BUSCAR ANIME");
		btnBuscarAnime.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					anime = IF.buscarAnime(text_nome_anime.getText());
					String
									nome = anime.getNome(),
									sinopse = anime.getSinopse(),
									genero = anime.getGenero(),
									nTotEp = String.valueOf(anime.getNumero_total_ep()),
									nTotTemp = String.valueOf(anime.getNumero_temporada()),
									ano = String.valueOf(anime.getAno()),
									duracao = String.valueOf(anime.getDuracao());
					text_nome_anime.setText(nome);
					text_anime_sinopse.setText(sinopse);
					text_anime_genero.setText(genero);
					text_anime_n_Ep.setText(nTotEp);
					text_n_t_temporada.setText(nTotTemp);
					text_anime_ano_lacamento.setText(ano);
					text_duracao_anime.setText(duracao);
					JPanelMessages.sucesso(btnBuscarAnime, "Nome: " + nome + "\nGênero: " + genero + "\nNúmero de episódios: "
									+ nTotEp + "\nNúmero de temporadas: " + nTotTemp
									+ "\nDuração: " + duracao + "\nSinopse: " + sinopse
									+ "\nAno: " + ano);
				} catch (Exception e) {
					JPanelMessages.erro(btnBuscarAnime, "Anime com nome '" + text_nome_anime.getText() + "' não existe na base de dados");
				}
			}
		});
		btnBuscarAnime.setBounds(255, 285, 160, 25);
		frame.getContentPane().add(btnBuscarAnime);

		JButton btnCancelar = new JButton("CANCELAR");
		btnCancelar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (text_nome_anime.getText().length() <= 0 && text_duracao_anime.getText().length() <= 0
						&& text_anime_ano_lacamento.getText().length() <= 0 && text_anime_genero.getText().length() <= 0
						&& text_anime_sinopse.getText().length() <= 0 && text_n_t_temporada.getText().length() <= 0
						&& text_anime_n_Ep.getText().length() <= 0) {
					JPanelMessages.sucesso(btnCadastrarAnime, "Os campos já estão vazios");
				} else {
					text_nome_anime.setText("");
					text_duracao_anime.setText("");
					text_anime_ano_lacamento.setText("");
					text_anime_genero.setText("");
					text_anime_sinopse.setText("");
					text_anime_n_Ep.setText("");
					text_n_t_temporada.setText("");
				}
			}
		});
		btnCancelar.setBounds(453, 285, 117, 25);
		frame.getContentPane().add(btnCancelar);

		JButton btnExcluir = new JButton("EXCLUIR");
		btnExcluir.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					IF.excluirAnime(text_nome_anime.getText());
					JPanelMessages.sucesso(btnExcluir, "Anime '" + text_nome_anime.getText() + "' excluido com sucesso");
				} catch (Exception e) {
					JPanelMessages.erro(btnExcluir, "Anime '" + text_nome_anime.getText() + "' não excluido(não existe)");
					e.printStackTrace();
				}
			}
		});
		btnExcluir.setBounds(59, 322, 117, 25);
		frame.getContentPane().add(btnExcluir);

		JButton btnAtualizar = new JButton("ATUALIZAR");
		btnAtualizar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					anime.setNome(text_nome_anime.getText());
					anime.setDuracao(Double.parseDouble(text_duracao_anime.getText()));
					anime.setAno(Integer.parseInt(text_anime_ano_lacamento.getText()));
					anime.setGenero(text_anime_genero.getText());
					anime.setSinopse(text_anime_sinopse.getText());
					anime.setNumero_total_ep(Integer.parseInt(text_anime_n_Ep.getText()));
					anime.setNumero_temporada(Integer.parseInt(text_n_t_temporada.getText()));
					IF.atualizarAnime(anime);
					JPanelMessages.sucesso(btnAtualizar, "Anime '" + anime.getNome() + "' atualizado com sucesso");
				} catch (Exception e) {
					JPanelMessages.erro(btnAtualizar, "Não é possível atualizar o anime");
				}
			}
		});
		btnAtualizar.setBounds(278, 322, 117, 25);
		frame.getContentPane().add(btnAtualizar);

		JButton btnSair = new JButton("SAIR");
		btnSair.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				System.exit(0);
			}
		});
		btnSair.setBounds(453, 322, 117, 25);
		frame.getContentPane().add(btnSair);
	}
}
