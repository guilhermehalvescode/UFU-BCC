package negocio.Video.serie;

import dados.CadastroGenerico;
import dados.RepositorioGenericoTXT;

public class SeriesDAO extends CadastroGenerico<Series> {

	public SeriesDAO() {
		RepositorioGenericoTXT<Series> r = new RepositorioSeriesTXT();
		r.setNomeArquivo("./db/Series.txt");
		this.setRepo(r);
	}

	@Override
	public Series busca(String chave) throws Exception {
		for (int i = 0; i < lista.size(); i++) {
			Series s = lista.get(i);
			if (s.getNome().equals(chave))
				return s;
		}
		throw new Exception("Serie com o nome '" + chave + "' não encontrado!");
	}

	@Override
	public int buscaPosicao(String nome) throws Exception {
		for (int i = 0; i < this.lista.size(); i++) {
			Series s = lista.get(i);
			if (s.getNome().equals(nome)) {
				return i;
			}
		}
		throw new Exception("Serie com o nome '" + nome + "' não encontrado!");
	}

}
