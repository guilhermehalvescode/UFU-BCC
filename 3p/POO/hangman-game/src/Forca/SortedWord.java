package Forca;
import java.util.Random;

public class SortedWord {
    private static final String[] words = { "dinossauro", "bola" , "skate", "carro", "esfera", "jogador", "cerveja", "game"};
    private final String sorted;

    public SortedWord() {
        this.sorted = this.getWord();
    }

    public String getSorted() {
        return this.sorted;
    }

    private String getWord() {
       Random rand = new Random();
       return words[rand.nextInt(words.length)];
    }
}
