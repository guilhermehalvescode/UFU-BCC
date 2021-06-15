package dados;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

abstract public class RepositorioGenericoTXT <T extends Gravavel> {

	private String nomeArquivo = "repositorioGenerico.txt";
	private File f = new File(this.nomeArquivo);

	public void setNomeArquivo(String nome) {
		this.nomeArquivo = nome;
		f = new File(this.nomeArquivo);
	}

	abstract public T create();
	
	public T create(String classe) {
		try {
			Class type = Class.forName(classe);
			T aux = (T) type.newInstance();

			System.out.println(aux);
			return aux;
			// (T)(Class.forName( t.toString() ).newInstance());
		} catch (Exception e) {
			return null;
		}
	}

	public ArrayList<T> recuperar() throws IOException {
		ArrayList<T> lista = new ArrayList<>();
		FileInputStream fi = null;
		try{
			fi = new FileInputStream(f);
		} catch(FileNotFoundException e){
			FileOutputStream fo = new FileOutputStream(f);
			fo.close();
			fi = new FileInputStream(f);
		}
		InputStreamReader ir = new InputStreamReader(fi);
		BufferedReader br = new BufferedReader(ir);
		String linha;
		while ((linha = br.readLine()) != null) {
			T o = create();
			o.setRegistro(linha);
			lista.add(o);
		}
		fi.close();
		// TODO Auto-generated method stub
		return lista;
	}

	public void salvar(ArrayList<T> lista) throws IOException {
		// TODO Auto-generated method stub

		FileOutputStream fo = new FileOutputStream(f);
		for (Gravavel g : lista) {
			fo.write(g.getRegistro().getBytes());
		}
		fo.close();
		System.out.println("Arquivo gravado com sucesso");
	}

}
