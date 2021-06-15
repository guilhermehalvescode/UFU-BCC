package Exercicios;

public class Conta {
    private static int count = 0;
    private int nroConta;
    private Cliente cliente;
    private float saldo;

    public Conta(Cliente cli) {
        this.nroConta = count++;
        this.setCliente(cli);
        this.setSaldo(0);
    }

    public void depositar(float valor) {
        if(valor > 0) {
            this.setSaldo(this.saldo += valor);
        }
    }

    public float sacar(float valor) {
        if(valor <= this.saldo) {
            this.setSaldo(this.saldo - valor);
            return valor;
        }
        return -1;
    }

    public float getSaldo() {
        return this.saldo;
    }

    private void setSaldo(float valor) {
        if (saldo >= 0) this.saldo = valor;
    }

    public Cliente getCliente() {
        return this.cliente;
    }

    private void setCliente(Cliente cli) {
        if(cli != null) this.cliente = cli;
    }

    @Override
    public String toString() {
        return "Conta{" +
                "nroConta=" + nroConta +
                ", cliente=" + cliente +
                ", saldo=" + saldo +
                '}';
    }
    public static void main(String[] args) {
        Cliente cliente = new Cliente("Fernando Capataz Filho");
        Conta c1 = new Conta(cliente);
        c1.depositar(1000);
        System.out.println(c1.sacar(600));
        c1.depositar(300);
        System.out.println(c1);
    }
}
