package apresentacao;

import javax.swing.*;
import java.awt.Component;

public class JPanelMessages {
  protected static void erro(Component comp , String msg){
    JOptionPane.showMessageDialog(comp, msg,"ERRO", JOptionPane.ERROR_MESSAGE);
  }

  protected static void aviso(Component comp ,String msg){
    JOptionPane.showMessageDialog(comp, msg,"AVISO", JOptionPane.WARNING_MESSAGE);
  }

  protected static void sucesso(Component comp ,String msg){
    JOptionPane.showMessageDialog(comp, msg,"INFORMAÇÃO", JOptionPane.INFORMATION_MESSAGE);
  }
}