package banco;

public class ContaEspecial extends ContaBancaria {
	
	public ContaEspecial(String cliente, int num_conta, float saldo, float limite) {
		super(cliente, num_conta, saldo);
		// TODO Auto-generated constructor stub
		this.setLimite(limite);
	}
	
	public ContaEspecial(){
		
	}

	private float limite;

	public float getLimite() {
		return limite;
	}

	public void setLimite(float limite) {
		this.limite = limite;
	}

	@Override
	public void sacar(float valor) throws Exception {
		if (valor < 0)
			throw new IllegalArgumentException("O valor do saque deve ser maior que zero");
		// TODO Auto-generated method stub
		if (valor <= this.getSaldo()+limite){
			this.setSaldo(this.getSaldo()-valor);
			System.out.println("==> Saque "+valor);
		} else
			throw new Exception("Saldo "+this.getSaldo()+" insuficiente para sacar "+valor
					+ " mesmo com limite de "+this.getLimite());
	}

	@Override
	public String toString() {
		return "ContaEspecial [limite=" + limite + ", getCliente()=" + getCliente() + ", getNum_conta()="
				+ getNum_conta() + ", getSaldo()=" + getSaldo() + "]";
	}
	
	
}
