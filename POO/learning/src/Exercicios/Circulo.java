package Exercicios;

public class Circulo {
    private Ponto centro;
    private float raio;
    private String nome;

    public Circulo(float raio, Ponto centro) {
        this.setCentro(centro);
        this.setRaio(raio);
    }

    //Get & Set centro
    public Ponto getCentro() {
        return this.centro;
    }

    private void setCentro(Ponto p) {
        if(p != null) this.centro = p;
    }


    //Get & Set raio
    public float getRaio() {
        return this.raio;
    }

    private void setRaio(float r) {
        if(r > 0) this.raio = r;
    }

    //Get & Set nome

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        if(!nome.isEmpty())
            this.nome = nome;
    }

    //Methods

    public float diametro() {
        return this.raio * 2;
    }

    public float area() {
        return (float) (Math.PI * Math.pow(this.raio, 2));
    }

    public float circunferencia() {
        return (float) (2 * Math.PI * this.raio);
    }

    @Override
    public String toString() {
        return "Circulo{" +
                "centro=(" + centro.getX() + ", " + centro.getY() + ")" +
                ", raio=" + raio +
                ", nome='" + nome + '\'' +
                ", diametro=" + this.diametro() +
                ", area=" + this.area() +
                ", circunferencia=" + this.circunferencia() +
                '}';
    }

    public static void main(String[] args) {
        Ponto point = new Ponto();
        point.setPonto(1, 1);
        Circulo cir = new Circulo(5f, point);
        cir.setNome("Fire Area");
        System.out.println(cir);
    }
}
