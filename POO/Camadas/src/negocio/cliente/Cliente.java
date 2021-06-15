package negocio.cliente;

import java.util.StringTokenizer;

import dados.Gravavel;

public class Cliente implements Gravavel{
	
	
	static final String SEPARADOR = "#";
	
	private String nome;
	private String cpf;
	private int id;
	/**
	 * @return the nome
	 */
	public String getNome() {
		return nome;
	}
	/**
	 * @param nome the nome to set
	 */
	public void setNome(String nome) {
		this.nome = nome;
	}
	/**
	 * @return the cpf
	 */
	public String getCpf() {
		return cpf;
	}
	/**
	 * @param cpf the cpf to set
	 */
	public void setCpf(String cpf) {
		this.cpf = cpf;
	}
	/**
	 * @return the id
	 */
	public int getId() {
		return id;
	}
	/**
	 * @param id the id to set
	 */
	public void setId(int id) {
		this.id = id;
	}
	@Override
	public String getRegistro() {
		
		StringBuffer reg = new StringBuffer();
		reg.append(this.getId());
		reg.append(SEPARADOR);
		reg.append(this.getCpf());
		reg.append(SEPARADOR);
		reg.append(this.getNome());
		reg.append("\n");
		
		// TODO Auto-generated method stub
		return reg.toString();
	}
	@Override
	public void setRegistro(String reg) {
		StringTokenizer st = new StringTokenizer(reg,SEPARADOR);
		this.setId(Integer.parseInt(st.nextToken()));
		this.setCpf(st.nextToken());
		this.setNome(st.nextToken());
	}
	/* (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString() {
		return "Cliente [id=" + id +", cpf=" + cpf + ", nome=" + nome +  "]";
	}
		

}
