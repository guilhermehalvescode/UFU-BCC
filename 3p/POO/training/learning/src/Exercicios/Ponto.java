package Exercicios;

public class Ponto {
    private float x;
    private float y;

    public float getX() {
        return this.x;
    }

    public float getY() {
        return this.y;
    }

    public void setPonto(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public float distancia(int x, int y) {
        float dist = (float) Math.sqrt(Math.pow(x - this.x, 2) + Math.pow(y - this.y, 2));
        return dist;
    }

    public float distancia(Ponto p) {
        float dist = (float) Math.sqrt(Math.pow(p.getX() - this.x, 2) + Math.pow(p.getY() - this.y, 2));
        return dist;
    }

    public static void main(String[] args) {
        Ponto p = new Ponto(), pontinho = new Ponto();
        pontinho.setPonto(1, 1);
        p.setPonto(0, 0);
        System.out.println(p.distancia(pontinho));
        return;
    }
}
