package apresentacao;
import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import negocio.IFachadaSistema;
import negocio.Sistema;
import negocio.produto.Produto;

import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import javax.swing.SwingConstants;
import javax.swing.JButton;
import javax.swing.JTextField;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class TelaProduto extends JFrame {

	private JPanel contentPane;
	private JTextField tfDescricao;
	private JTextField tfCodigo;
	private JButton btnIncluir;
	private JButton btnBuscar;
	private JButton btnCancel;
	private JButton btnExcluir;
	private JButton button_4;
	private JButton btnSair;
	
	IFachadaSistema fc;
	Produto p;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					
					TelaProduto frame = new TelaProduto();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	public void erro(String msg){
		JOptionPane.showMessageDialog(this, msg,"ERRO",JOptionPane.ERROR_MESSAGE);
	}

	public void aviso(String msg){
		JOptionPane.showMessageDialog(this, msg,"AVISO",JOptionPane.WARNING_MESSAGE);
	}
	
	public void sucesso(String msg){
		JOptionPane.showMessageDialog(this, msg,"INFORMAÇÂO",JOptionPane.INFORMATION_MESSAGE);
	}

	/**
	 * Create the frame.
	 */
	public TelaProduto() {
		
		try {
			fc = Sistema.getFachada();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			erro(e.getMessage());
		}
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 803, 425);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblCadastroDeClientes = new JLabel("Cadastro de Produtos");
		lblCadastroDeClientes.setHorizontalAlignment(SwingConstants.CENTER);
		lblCadastroDeClientes.setFont(new Font("Times New Roman", Font.BOLD, 22));
		lblCadastroDeClientes.setBounds(274, 39, 233, 20);
		contentPane.add(lblCadastroDeClientes);
		
		tfDescricao = new JTextField();
		tfDescricao.setBounds(186, 142, 258, 29);
		contentPane.add(tfDescricao);
		tfDescricao.setColumns(10);
		
		JLabel lblDescricao = new JLabel("Descri\u00E7\u00E3o");
		lblDescricao.setBounds(83, 146, 69, 20);
		contentPane.add(lblDescricao);
		
		JLabel lblCdigo = new JLabel("C\u00F3digo");
		lblCdigo.setBounds(83, 93, 69, 20);
		contentPane.add(lblCdigo);
		
		tfCodigo = new JTextField();
		tfCodigo.setBounds(186, 90, 146, 26);
		contentPane.add(tfCodigo);
		tfCodigo.setColumns(10);
		
		btnIncluir = new JButton("INCLUIR");
		
		btnIncluir.setBounds(59, 212, 115, 29);
		contentPane.add(btnIncluir);
		
		btnBuscar = new JButton("BUSCAR");
		btnBuscar.setBounds(200, 212, 115, 29);
		contentPane.add(btnBuscar);
		
		btnCancel = new JButton("Cancelar");
		btnCancel.setEnabled(false);
		btnCancel.setBounds(342, 212, 115, 29);
		contentPane.add(btnCancel);
		
		btnExcluir = new JButton("EXCLUIR");
		btnExcluir.setEnabled(false);
		btnExcluir.setBounds(472, 212, 115, 29);
		contentPane.add(btnExcluir);
		
		button_4 = new JButton("ATUALIZAR");
		button_4.setEnabled(false);
		button_4.setBounds(602, 212, 138, 29);
		contentPane.add(button_4);
		
		btnSair = new JButton("SAIR");
		
		btnSair.setBounds(342, 303, 115, 29);
		contentPane.add(btnSair);
		
		btnIncluir.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				p = new Produto();
				p.setCodigo(tfCodigo.getText());
				p.setDescricao(tfDescricao.getText());
				try {
					fc.cadastrarProduto(p);
				} catch (Exception e) {
					// TODO Auto-generated catch block
					erro(e.getMessage());
				}
				tfCodigo.setText("");
				tfDescricao.setText("");
			}
		});
		
		btnSair.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				aviso("Fim de programa!");
				System.exit(0);
			}
		});
	}
}
