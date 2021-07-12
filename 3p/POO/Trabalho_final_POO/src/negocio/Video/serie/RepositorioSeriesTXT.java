package negocio.Video.serie;

import dados.RepositorioGenericoTXT;

public class RepositorioSeriesTXT extends RepositorioGenericoTXT<Series> {

	@Override
	public Series create() {
		// TODO Auto-generated method stub
		return new Series();
	}

}
