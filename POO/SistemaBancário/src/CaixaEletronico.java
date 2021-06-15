public class CaixaEletronico {
    public static void main(String[] args) {
        Cliente cli1 = new Cliente("Fernando", "Avenida dos morrinhos", "147.351.436-97");
        Cliente cli2 = new Cliente("Fernando Costa", "Avenida dos palanques", "147.351.436-37");
        Conta c1 = new Conta(cli1);
        Conta c2 = new Conta(cli2);
        c1.deposita(1000.20);
        c2.deposita(1100.20);
        c2.trasfere(c1, 100);
        System.out.println(c1);
        System.out.println(c2);
    }
}
