import javax.swing.JOptionPane;
import java.util.ArrayList;
import java.util.Collections;

public class Names {
    private ArrayList<String> names;

    public Names() {
        this.names = new ArrayList<>();
    }

    public void setNames() {
        while(true) {
            String nome = JOptionPane.showInputDialog(null, "Digite um nome: ", "Insira os nomes!", JOptionPane.INFORMATION_MESSAGE);
            if(nome.length() == 0) break;
            this.names.add(nome);
        }
        Collections.sort(names);
    }

    public void getNames() {
        StringBuffer out = new StringBuffer("Os nomes ordenados são: \n");
        for(String n : this.names) {
            out.append(n);
            out.append("\n");
        }
        JOptionPane.showMessageDialog(null, out, "Os nomes digitados ordenados são: ", JOptionPane.INFORMATION_MESSAGE);
    }

    public static void main(String[] args) {
        Names obj = new Names();
        obj.setNames();
        obj.getNames();
    }
}
