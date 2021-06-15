package banco;

import banco.exceptions.EstouroDeLimiteException;

public class ContaBancaria {
	private String cliente;
	private int num_conta;
	private float saldo;
	
	
	
	public ContaBancaria() {
		
	}

	public ContaBancaria(String cliente, int num_conta, float saldo) {
		this.cliente = cliente;
		this.num_conta = num_conta;
		this.saldo = saldo;
	}

	public String getCliente() {
		return cliente;
	}

	public void setCliente(String cliente) {
		this.cliente = cliente;
	}

	public int getNum_conta() {
		return num_conta;
	}

	public void setNum_conta(int num_conta) {
		this.num_conta = num_conta;
	}

	public float getSaldo() {
		return saldo;
	}

	public void setSaldo(float saldo) {
		this.saldo = saldo;
	}

	public void sacar(float valor) throws Exception{
		if (valor < 0)
			throw new IllegalArgumentException("O valor do saque deve ser maior que zero");
		if (valor <= this.getSaldo()){
			this.setSaldo(this.getSaldo()-valor);
			System.out.println("==> Saque "+valor);
		} else
			throw new EstouroDeLimiteException("Saldo "+this.getSaldo()+" insuficiente para sacar "+valor);
	}
	
	public void depositar(float valor) throws Exception{
		if (valor < 0)
			throw new IllegalArgumentException("O valor do dep�sito deve ser maior que zero");
		this.setSaldo(this.getSaldo()+valor);
		System.out.println("==> Deposito "+valor);
	}

	@Override
	public String toString() {
		return "ContaBancaria [cliente=" + cliente + ", num_conta=" + num_conta + ", saldo=" + saldo + "]";
	}
	
	
}
