package negocio.Video.anime;

import dados.CadastroGenerico;
import dados.RepositorioGenericoTXT;

public class AnimeDAO extends CadastroGenerico<Anime> {

	public AnimeDAO() {
		RepositorioGenericoTXT<Anime> r = new RepositorioAnimeTXT();
		r.setNomeArquivo("./db/Animes.txt");
		this.setRepo(r);
	}

	@Override
	public Anime busca(String chave) throws Exception {
		for (int i = 0; i < lista.size(); i++) {
			Anime a = lista.get(i);
			if (a.getNome().equals(chave))
				return a;
		}
		throw new Exception("Anime com o nome '" + chave + "' não encontrado!");
	}

	@Override
	public int buscaPosicao(String nome) throws Exception {
		for (int i = 0; i < this.lista.size(); i++) {
			Anime a = lista.get(i);
			if (a.getNome().equals(nome)) {
				return i;
			}
		}
		throw new Exception("Anime com o nome '" + nome + "' não encontrado!");
	}
}
