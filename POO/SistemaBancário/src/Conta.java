public class Conta {
    private int numero;
    private double saldo;
    private double limite;
    private Cliente titular;
    private static int contador = 0;

    public Conta(Cliente cli) {
        this.titular = cli;
        this.setNumero(this.contador++);
    }

    public Conta(Cliente cli, double depositoInicial) {
        this(cli);
        this.setSaldo(depositoInicial);
    }

    public boolean saca(double valor) {
        boolean saca = valor <= (this.saldo + this.limite);
        if(saca) this.setSaldo(this.getSaldo() - valor);
        return saca;
    }

    public void deposita(double valor) {
        if(valor > 0) this.setSaldo(this.getSaldo() + valor);
    }

    public boolean trasfere(Conta contaDestino, double valor) {
        boolean podeSacar = this.saca(valor);
        if(podeSacar) contaDestino.deposita(valor);
        return podeSacar;
    }

    public int getNumero() {
        return numero;
    }
    public void setNumero(int numero) {
        this.numero = numero;
    }

    public double getSaldo() {
        return this.saldo;
    }
    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public double getLimite() {
        return this.limite;
    }
    public void setLimite(double limite) {
        this.limite = limite;
    }

    public Cliente getTitular() {
        return this.titular;
    }

    public static int getContador() {
        return contador;
    }

    @Override
    public String toString() {
        return "Conta{" +
                "titular=" + titular +
                ", numero=" + numero +
                ", saldo=" + saldo +
                ", limite=" + limite +
                '}';
    }
}
