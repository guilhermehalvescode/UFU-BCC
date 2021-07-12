package negocio;

import negocio.produto.Produto;

public interface IVendas {

	void cadastrarVenda(Produto c) throws Exception;

	public Produto buscarVenda(String codigo) throws Exception;
	
	public void excluirVenda(String codigo) throws Exception;
	
	public void atualizarVenda(Produto c) throws Exception;
	
}
