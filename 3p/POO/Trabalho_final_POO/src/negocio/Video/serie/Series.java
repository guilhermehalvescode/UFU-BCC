package negocio.Video.serie;

import java.util.StringTokenizer;

import dados.Gravavel;
import negocio.Video.Video;

public class Series extends Video implements Gravavel {
	private int numero_temporada, numero_total_ep;
	static final String SEPARADOR = "#";

	public int getNumero_temporada() {
		return numero_temporada;
	}

	public void setNumero_temporada(int numero_temporada) throws Exception {
		if (numero_temporada <= 0) {
			throw new Exception("Número temporadas não pode ser nulo/negativo");
		}
		this.numero_temporada = numero_temporada;
	}

	public int getNumero_total_ep() {
		return numero_total_ep;
	}

	public void setNumero_total_ep(int numero_total_ep) throws Exception {
		if (numero_total_ep <= 0) {
			throw new Exception("Número total de episódios não pode ser nulo/negativo");
		}
		this.numero_total_ep = numero_total_ep;
	}

	@Override
	public String getRegistro() {
		StringBuffer reg = new StringBuffer();
		reg.append(this.getNome());
		reg.append(SEPARADOR);
		reg.append(this.getDuracao());
		reg.append(SEPARADOR);
		reg.append(this.getGenero());
		reg.append(SEPARADOR);
		reg.append(this.getAno());
		reg.append(SEPARADOR);
		reg.append(this.getSinopse());
		reg.append(SEPARADOR);
		reg.append(this.getNumero_temporada());
		reg.append(SEPARADOR);
		reg.append(this.getNumero_total_ep());
		reg.append("\n");
		return reg.toString();
	}

	@Override
	public void setRegistro(String reg) throws Exception {
		StringTokenizer st = new StringTokenizer(reg, SEPARADOR);
		this.setNome(st.nextToken());
		this.setDuracao(Double.parseDouble(st.nextToken()));
		this.setGenero(st.nextToken());
		this.setAno(Integer.parseInt(st.nextToken()));
		this.setSinopse(st.nextToken());
		this.setNumero_temporada(Integer.parseInt(st.nextToken()));
		this.setNumero_total_ep(Integer.parseInt(st.nextToken()));

	}

	@Override
	public String toString() {
		return "Serie [nome: " + this.getNome() + ", duracao: " + this.getDuracao() + ", genero: " + this.getGenero() + ", ano: "
				+ this.getAno() + ", sinopse: " + this.getSinopse() + ", numero_temporada: " + this.numero_temporada
				+ ", numero_total_ep: " + this.numero_total_ep + "]";
	}

}