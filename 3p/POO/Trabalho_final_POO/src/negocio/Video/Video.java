package negocio.Video;

import java.time.Year;

public class Video {
	private String nome;
	private double duracao;
	private String genero;
	private int ano;
	private String sinopse;

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) throws Exception {
		if (nome == null || nome.isEmpty()) {
			throw new Exception("Nome inválido");
		}
		this.nome = nome;

	}

	public double getDuracao() {
		return duracao;
	}

	public void setDuracao(double duracao) throws Exception {
		if (duracao <= 0) {
			throw new Exception("Número da duração não pode ser nulo/negativo");
		}
		this.duracao = duracao;
	}

	public String getGenero() {

		return genero;
	}

	public void setGenero(String genero) throws Exception {
		if (genero == null || genero.isEmpty()) {
			throw new Exception("Genero não pode ser nulo/vazio");
		}
		this.genero = genero;
	}

	public int getAno() {
		return ano;
	}

	public void setAno(int ano) throws Exception {
		if (ano <= 0 || ano > Year.now().getValue()) {
			throw new Exception("Número do ano não pode ser nulo/negativo");
		}
		this.ano = ano;
	}

	public String getSinopse() {
		return sinopse;
	}

	public void setSinopse(String sinopse) throws Exception {
		if (sinopse == null || sinopse.isEmpty()) {
			throw new Exception("Sinopse não pode ser nula/vazia");
		}
		this.sinopse = sinopse;
	}
}