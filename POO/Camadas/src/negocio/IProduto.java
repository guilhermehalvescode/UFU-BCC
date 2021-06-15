package negocio;

import negocio.produto.Produto;

public interface IProduto {

	void cadastrarProduto(Produto c) throws Exception;

	public Produto buscarProduto(String codigo) throws Exception;
	
	public void excluirProduto(String codigo) throws Exception;
	
	public void atualizarProduto(Produto c) throws Exception;
	
}
