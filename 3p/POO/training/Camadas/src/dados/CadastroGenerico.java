package dados;

import java.util.ArrayList;

/**
 *
 * @author Bacalá
 */
public abstract class CadastroGenerico<T extends Gravavel> {
	
	RepositorioGenericoTXT <T> repo;
	
    protected ArrayList<T> lista;

    public CadastroGenerico() {
        this.lista = new ArrayList<>();
        
    }
    
    public void incluir(T t){
        this.lista.add(t);
    }
    
    public void remover(String chave)throws Exception{
        this.lista.remove(busca(chave));
    }
    
    public void atualizar (T t) throws Exception{
        this.lista.set(buscaPosicao(t), t);
    }
    
    public ArrayList<T> getLista(){
        return this.lista;
    }
    abstract public T busca(String chave) throws Exception;

    abstract public int buscaPosicao(T t) throws Exception;
    
    
	
	/**
	 * @param repo the repo to set
	 */
	public void setRepo(RepositorioGenericoTXT repo) {
		this.repo = repo;
	}
    
	public ArrayList<T> recuperar() throws Exception{
		if (repo != null){
			this.lista = repo.recuperar();
			return this.lista;
		}
		else
			throw new Exception("Repositorio não configurado!");
			
	}
    
	public void salvar() throws Exception{
		if (repo != null)
			repo.salvar(this.lista);
		else
			throw new Exception("Repositorio não configurado!");
	}
}
