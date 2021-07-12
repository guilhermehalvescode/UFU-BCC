import Forca.Forca;

import java.io.IOException;
import java.util.Scanner;



public class main {
    public static void main(String[]args) {
        Scanner teclado = new Scanner(System.in);
        String rep;
        do {
            rep = "";
            Forca game = new Forca();
            System.out.println("-----JOGO DA FORCA-----");
            while(game.isAlive()) {
                game.showForca();
                System.out.println("Letras tentadas: " + game.getTriedLetters());
                System.out.println("Palavra: " + game.getWord());
                if(game.isOver()) break;
                System.out.println("Digite sua tentativa: ");
                String tent = teclado.next();
                game.setWord(tent.charAt(0));
            }
            System.out.println("-----FIM DE JOGO-----");
            game.showForca();
            if(game.isAlive())
                System.out.println("VOCE VENCEU!");
            else
                System.out.println("VOCE PERDEU!");
            System.out.println("A palavra era: " + game.getSortedWord());
            do {
                System.out.println("\nDeseja jogar novamente? (s/n): ");
                rep = teclado.next();
            } while(!rep.equals("s") && !rep.equals("n"));
        } while(rep.equals("s"));
    }
}


