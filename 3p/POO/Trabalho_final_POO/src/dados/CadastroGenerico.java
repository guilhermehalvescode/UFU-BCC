package dados;

import java.util.ArrayList;

public abstract class CadastroGenerico<T extends Gravavel> {
  RepositorioGenericoTXT<T> repo;
  protected ArrayList<T> lista;

  public CadastroGenerico() {
    this.lista = new ArrayList<>();
  }

  public void incluir(T t) {
    this.lista.add(t);
  }

  public void remover(String chave) throws Exception {
    this.lista.remove(busca(chave));
  }

  public void atualizar(String key, T t) throws Exception {
    this.lista.set(buscaPosicao(key), t);
  }

  public ArrayList<T> getLista() {
    return this.lista;
  }

  abstract public T busca(String chave) throws Exception;

  abstract public int buscaPosicao(String nome) throws Exception;


  public void setRepo(RepositorioGenericoTXT repo) {
    this.repo = repo;
  }

  public ArrayList<T> recuperar() throws Exception {
    if (repo != null) {
      this.lista = repo.recuperar();
      return this.lista;
    } else
      throw new Exception("Repositório não configurado!");
  }

  public void salvar() throws Exception {
    if (repo != null)
      repo.salvar(this.lista);
    else
      throw new Exception("Repositório não configurado!");
  }
}
