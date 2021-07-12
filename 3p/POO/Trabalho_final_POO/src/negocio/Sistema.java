package negocio;

import negocio.Video.anime.Anime;
import negocio.Video.anime.AnimeDAO;
import negocio.Video.filme.Filme;
import negocio.Video.filme.FilmeDAO;
import negocio.Video.serie.Series;
import negocio.Video.serie.SeriesDAO;

public class Sistema implements IFachadaSistema {

  AnimeDAO daoAnime = new AnimeDAO();
  FilmeDAO daoFilme = new FilmeDAO();
  SeriesDAO daoSerie = new SeriesDAO();

  private static IFachadaSistema fc;


  private Sistema() throws Exception {
    daoAnime.recuperar();
    daoFilme.recuperar();
    daoSerie.recuperar();
  }

  static public IFachadaSistema getFachada() throws Exception {
    if(fc == null)
      fc = new Sistema();
    return fc;
  }
  @Override
  public void cadastrarAnime(Anime a) throws Exception {
    try {
      daoAnime.busca(a.getNome());
    } catch (Exception e) {
      daoAnime.incluir(a);
      daoAnime.salvar();
      return;
    }
    throw new Exception("Anime já se encontra cadastrado!");
  }

  @Override
  public Anime buscarAnime(String nome) throws Exception {
    return daoAnime.busca(nome);
  }

  @Override
  public void excluirAnime(String nome) throws Exception {
    daoAnime.remover(nome);
    daoAnime.salvar();
  }

  @Override
  public void atualizarAnime(Anime a) throws Exception {
    daoAnime.atualizar(a.getNome(), a);
    daoAnime.salvar();
  }

  @Override
  public void cadastrarFilme(Filme f) throws Exception {
    try {
      daoFilme.busca(f.getNome());
    } catch (Exception e) {
      daoFilme.incluir(f);
      daoFilme.salvar();
      return;
    }
    throw new Exception("Filme já se encontra cadastrado!");
  }

  @Override
  public Filme buscarFilme(String nome) throws Exception {
    return daoFilme.busca(nome);
  }

  @Override
  public void excluirFilme(String nome) throws Exception {
    daoFilme.remover(nome);
    daoFilme.salvar();
  }

  @Override
  public void atualizarFilme(Filme f) throws Exception {
    daoFilme.atualizar(f.getNome(), f);
    daoFilme.salvar();
  }

  @Override
  public void cadastrarSeries(Series s) throws Exception {
    try {
      daoSerie.busca(s.getNome());
    } catch (Exception e) {
      daoSerie.incluir(s);
      daoSerie.salvar();
      return;
    }
    throw new Exception("Serie já se encontra cadastrada!");
  }

  @Override
  public Series buscarSeries(String nome) throws Exception {
    return daoSerie.busca(nome);
  }

  @Override
  public void excluirSerie(String nome) throws Exception {
    daoSerie.remover(nome);
    daoSerie.salvar();
  }

  @Override
  public void atualizarSeries(Series s) throws Exception {
    daoSerie.atualizar(s.getNome(), s);
    daoSerie.salvar();
  }
}
