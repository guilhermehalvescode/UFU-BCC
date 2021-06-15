package negocio;

import negocio.cliente.Cliente;

public interface ICliente {
	
	void cadastrar(Cliente c) throws Exception;

	public Cliente buscar(String cpf) throws Exception;

	public void excluir(String cpf) throws Exception;

	public void atualizar(Cliente c) throws Exception;
}
