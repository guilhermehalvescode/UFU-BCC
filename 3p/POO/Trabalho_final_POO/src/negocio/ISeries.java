package negocio;

import negocio.Video.serie.Series;

public interface ISeries {
	public void cadastrarSeries(Series s) throws Exception;

	public Series buscarSeries(String nome) throws Exception;

	public void excluirSerie(String nome) throws Exception;

	public void atualizarSeries(Series s) throws Exception;

}
