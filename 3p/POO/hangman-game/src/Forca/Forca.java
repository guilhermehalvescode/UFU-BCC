package Forca;

public class Forca {
    private final StringBuffer word; //Hidden word
    private final String sortedWord; //Sorted word
    private Tries triedLetters;
    private final int length;

    public Forca() {
        this.sortedWord = new SortedWord().getSorted();
        this.triedLetters = new Tries();
        this.length = sortedWord.length();
        this.word = initWord(this.length);
    }
    //Sets char in word for forca
    public void setWord(char triedChar) {
        triedChar =  this.triedLetters.normalizeToLowerChar(triedChar);
        //If letter already tried, dont setWord
        if(this.triedLetters.getLetters().indexOf(String.valueOf(triedChar)) != -1) return;
        boolean success = false;
        for(int i = 0; i < this.length; i++) {
            if(this.sortedWord.charAt(i) == triedChar) {
                success = true;
                this.word.replace(i, i + 1, String.valueOf(triedChar));
            }
        }
        this.triedLetters.setLetters(triedChar);
        if(!success) this.triedLetters.handleTry();
    }

    public StringBuffer getWord() {
        return this.word;
    }

    public String getSortedWord() {
        return this.sortedWord;
    }

    public StringBuffer getTriedLetters() {
        return this.triedLetters.getLetters();
    }

    public Boolean isAlive() {
        return this.triedLetters.getTries() != 0;
    }

    public Boolean isOver() { return this.word.indexOf("_") == -1; }

    public void showForca() {
        byte tries = this.triedLetters.getTries();
        System.out.println("*-----------*");
        System.out.println("|           |");
        if(tries <= 5) {
            System.out.println("|           O");
        } else {
            System.out.println("|            ");
        }

        if(tries == 4) {
            System.out.println("|           |");
        } else if (tries == 3){
            System.out.println("|          /|");
        } else if (tries <= 2){
            System.out.println("|          /|\\");
        } else {
            System.out.println("|            ");
        }

        if(tries == 1) {
            System.out.println("|          /");
        } else if(tries == 0) {
            System.out.println("|          / \\");
        } else {
            System.out.println("|            ");
        }
        System.out.println("|            ");
        System.out.println("|            ");
    }

    private StringBuffer initWord(int length) {
        StringBuffer str = new StringBuffer(length + 1); //(length + 1) Extra space for '\0'
        for (int i = 0; i < length; i++) {
            str.replace(i, i + 1, "_");
        }
        return str;
    }

    public static void main(String[] args) {
        Forca word = new Forca();
        System.out.println(word.getSortedWord());
        word.setWord('c');
        System.out.println(word.getWord());

    }
}
