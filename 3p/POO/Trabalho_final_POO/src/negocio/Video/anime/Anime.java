package negocio.Video.anime;

import java.util.StringTokenizer;

import dados.Gravavel;
import negocio.Video.serie.Series;

public class Anime extends Series implements Gravavel {
	@Override
	public String toString() {
		return "Anime [nome: " + this.getNome() + ", genero: " + this.getGenero() + ", sinopse: " + this.getSinopse() + ", duracao: "
				+ this.getDuracao() + ", ano: " + this.getAno() + "]";
	}
}
