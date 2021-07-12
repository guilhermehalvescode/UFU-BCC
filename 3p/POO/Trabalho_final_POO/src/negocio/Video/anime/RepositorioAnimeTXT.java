package negocio.Video.anime;

import dados.RepositorioGenericoTXT;

public class RepositorioAnimeTXT extends RepositorioGenericoTXT<Anime> {

	@Override
	public Anime create() {
		// TODO Auto-generated method stub
		return new Anime();
	}

}
