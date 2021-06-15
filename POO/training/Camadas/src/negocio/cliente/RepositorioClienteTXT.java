package negocio.cliente;

import dados.RepositorioGenericoTXT;

public class RepositorioClienteTXT extends RepositorioGenericoTXT <Cliente> {

	@Override
	public Cliente create() {
		// TODO Auto-generated method stub
		return new Cliente();
	}

}
