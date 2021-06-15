package negocio.produto;
import java.util.ArrayList;
import java.util.Iterator;

import dados.CadastroGenerico;
import dados.Gravavel;
import dados.RepositorioGenericoTXT;

public class ProdutoDAO extends CadastroGenerico<negocio.produto.Produto> {
	
	static private int cont;
	
	public int getNextId() {
		// TODO Auto-generated method stub
		return ++cont;
	}
	@Override
	public Produto busca(String chave) throws Exception {
		// TODO Auto-generated method stub
		for (int i = 0; i < this.lista.size(); i++) {
			Produto c = lista.get(i);
			if (c.getCodigo().equals(chave)){
				return c;
			}
		}
		throw new Exception("Cliente com chave "+chave+" não encontrado!");
	}

	@Override
	public int buscaPosicao(Produto t) throws Exception {
		for (int i = 0; i < this.lista.size(); i++) {
			Produto c = lista.get(i);
			if (c == t){
				return i;
			}
		}
		throw new Exception("Cliente com "+t.getCodigo()+" não encontrado!");
	}

	/**
	 * @param repo
	 */
	public ProdutoDAO() {
		RepositorioGenericoTXT<Produto> r = new RepositorioProdutoTXT();
		r.setNomeArquivo("PRODUTO.TXT");
		this.setRepo(r);
	}
	
	

	/* (non-Javadoc)
	 * @see dados.CadastroGenerico#recuperar()
	 */
	@Override
	public ArrayList<Produto> recuperar() throws Exception {
		// TODO Auto-generated method stub
		ArrayList <Produto> l = super.recuperar();
		cont = l.get(l.size()-1).getId();
		return l;
		
	}
	
	
	
}
