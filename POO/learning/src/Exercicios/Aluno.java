package Exercicios;

public class Aluno {
    private static int contador = 0;
    private int matricula;
    private String nome;
    private double p1, p2, trab;

    public Aluno(String nome) {
        this.matricula = contador++;
        this.setNome(nome);
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        if(nome != null && !nome.isEmpty())
            this.nome = nome;
    }

    public double getP1() {
        return this.p1;
    }

    public void setP1(double p1) {
        if(p1 < 0) return;
        this.p1 = p1;
    }

    public double getP2() {
        return this.p2;
    }

    public void setP2(double p2) {
        if(p2 < 0) return;
        this.p2 = p2;
    }

    public double getTrab() {
        return this.trab;
    }

    public void setTrab(double trab) {
        if(trab < 0) return;
        this.trab = trab;
    }

    public double calculaMedia() {
        double media = (this.p1 * 2.5 + this.p2 * 2.5 + this.trab * 2)/ 7;
        return media;
    }

    public double calculaFinal(){
        double media = this.calculaMedia();
        if (media >= 30)
            return 60 - media;
        else
            return 0;
    }

    @Override
    public String toString() {
        return "Aluno{" +
                "matricula=" + matricula +
                ", nome='" + nome + '\'' +
                ", p1=" + p1 +
                ", p2=" + p2 +
                ", trab=" + trab +
                '}';
    }
}
