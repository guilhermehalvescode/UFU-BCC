package Exercicios;

public class Turma {
    final private int TAMANHO = 10;
    private Aluno[] alunos = new Aluno[TAMANHO];
    private int cont = 0;

    public void listaAlunos() {
        for(int i = 0; i < cont; i++) {
            System.out.println(alunos[i]);
        }
    }

    public void adicionaAluno(Aluno a) {
        if(cont < TAMANHO) {
            alunos[cont++] = a;
        } else System.out.println("Limite de alunos na turma alcançado!!");
    }

    public void removeAluno(int indice) {
        if(indice < 0 || indice >= cont) return;
        for (int i = indice + 1; i < cont; i++) {
            alunos[i - 1] = alunos[i];
        }
        alunos[--cont] = null;
    }

    public void removeAluno(String nome) {
        this.removeAluno(buscaAluno(nome));
    }

    public void removeAluno(Aluno a) {
        this.removeAluno(a.getNome());
    }

    private int buscaAluno(String nome) {
        for(int i = 0; i < cont; i++) {
            if(alunos[i].getNome().equals(nome)) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Turma t1 = new Turma();
        for(int i = 0; i < 10; i++) {
            Aluno a = new Aluno("Aluno " + i);
            t1.adicionaAluno(a);
        }
        t1.removeAluno("Aluno 8");
        t1.listaAlunos();
    }
}
