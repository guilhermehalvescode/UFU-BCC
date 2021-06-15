package Exercicios;

public class Cliente {
    private static int cont = 0;
    private int id;
    private String nome;

    public Cliente(String nome) {
        this.id = cont++;
        this.setNome(nome);
    }

    public int getId() {
        return this.id;
    }

    public String getNome() {
        return this.nome;
    }

    private void setNome(String nome) {
        if(nome != null && !nome.isEmpty()) {
            this.nome = nome;
        }
    }

    @Override
    public String toString() {
        return "Cliente{" +
                "id=" + id +
                ", nome='" + nome + '\'' +
                '}';
    }
}
