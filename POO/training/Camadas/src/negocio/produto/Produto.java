package negocio.produto;

import java.util.StringTokenizer;

import dados.Gravavel;

public class Produto implements Gravavel{
	
	
	static final String SEPARADOR = "#";
	
	private String descricao;
	private String codigo;
	private int id;
	/**
	 * @return the nome
	 */
	public String getDescricao() {
		return descricao;
	}
	/**
	 * @param nome the nome to set
	 */
	public void setDescricao(String nome) {
		this.descricao = nome;
	}
	/**
	 * @return the cpf
	 */
	public String getCodigo() {
		return codigo;
	}
	/**
	 * @param cpf the cpf to set
	 */
	public void setCodigo(String codigo) {
		this.codigo = codigo;
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
		reg.append(this.getCodigo());
		reg.append(SEPARADOR);
		reg.append(this.getDescricao());
		reg.append("\n");
		
		// TODO Auto-generated method stub
		return reg.toString();
	}
	@Override
	public void setRegistro(String reg) {
		StringTokenizer st = new StringTokenizer(reg,SEPARADOR);
		this.setId(Integer.parseInt(st.nextToken()));
		this.setCodigo(st.nextToken());
		this.setDescricao(st.nextToken());
	}
	/* (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString() {
		return "Cliente [id=" + id +", cpf=" + codigo + ", nome=" + descricao +  "]";
	}
		

}
