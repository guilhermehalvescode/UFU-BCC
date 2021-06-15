import Lampada.Switch;

public class Main {
    public static void main(String[] args) {
        Switch light =  new Switch(false, false);
        int n = (int) Math.ceil(Math.random() * 100);

        for(int i = 0; i < n; i++)
            light.toggle();

        System.out.println("Switch pressed " + n + " times.");
        System.out.println(light.isBroken());
        System.out.println("The switch is " + light.getState());
    }
}
