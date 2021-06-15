package banco;

public class ContaPoupanca extends ContaBancaria {
	
	
	public ContaPoupanca(String cliente, int num_conta, float saldo, int dia) {
		super(cliente, num_conta, saldo);
		// TODO Auto-generated constructor stub
		this.setDia(dia);
		
	}


	public ContaPoupanca() {
		// TODO Auto-generated constructor stub
	}


	private int dia;
	
	
	public int getDia() {
		return dia;
	}


	public void setDia(int dia) {
		this.dia = dia;
	}

	public void calcularNovoSaldo(float rendimento){
		this.setSaldo(this.getSaldo()+this.getSaldo()*rendimento/ 100f);
	}


	@Override
	public String toString() {
		return "ContaPoupanca [dia=" + dia + ", getCliente()=" + getCliente() + ", getNum_conta()=" + getNum_conta()
				+ ", getSaldo()=" + getSaldo() + "]";
	}
	
	
}
