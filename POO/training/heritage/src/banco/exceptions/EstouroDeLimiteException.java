package banco.exceptions;

public class EstouroDeLimiteException extends Exception {
	private String mensagem;
		
	public EstouroDeLimiteException(String mensagem) {
		super();
		this.mensagem = mensagem;
	}

	@Override
	public String getMessage() {
		// TODO Auto-generated method stub
		return mensagem;
	}
	
	

}
