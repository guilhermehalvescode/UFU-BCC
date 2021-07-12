package negocio.Video.filme;

import dados.RepositorioGenericoTXT;

public class RepositorioFilmeTXT extends RepositorioGenericoTXT<Filme> {

	@Override
	public Filme create() {
		// TODO Auto-generated method stub
		return new Filme();
	}

}
