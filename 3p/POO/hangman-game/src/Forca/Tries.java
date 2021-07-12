package Forca;

public class Tries {
    private Boolean[] letters = new Boolean[26];
    private byte tries;

    public Tries() {
        //User has 6 tries;
        this.tries = 6;
        for(int i = 0; i < 26; i++) {
            this.letters[i] = false;
        }
    }

    public byte getTries() {
        return this.tries;
    }

    public void handleTry() {
        this.tries--;
    }

    public void setLetters(char triedLetter) {
        byte index = (byte) (normalizeToLowerChar(triedLetter) - 97);
        this.letters[index] = true;
    }

    public StringBuffer getLetters() {
        StringBuffer triedletters = new StringBuffer(27);
        for(int i = 0; i < this.letters.length; i++) {
            if(this.letters[i] == true) {
                triedletters.append((char) (i + 97));
            }
        }
        return triedletters;
    }

    protected char normalizeToLowerChar(char c) {
        if(c >= 65 && c <= 90) c += 32;
        return c;
    }
}
