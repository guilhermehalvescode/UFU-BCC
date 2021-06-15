package Lampada;

public class Switch {
    //
    private boolean state;
    private boolean broken;
    private int switches;

    public Switch(boolean state, boolean broken) {
        this.state = state;
        this.broken = broken;
        this.switches = (int) Math.ceil(Math.random() * 70);
    }

    public void toggle() {
        if(!this.broken && this.switches > 0) {
            this.state = !state;
            this.switches--;
            if(this.switches == 0) this.broken = true;
        }
    }
    
    public String getState() {
        if(!this.broken) {
            return this.state ? "on" : "off";
        } else return "broken";
    }
    
    public String isBroken() {
        if(this.broken) 
            return "Switch is broken, fix it please!!! :((";
        return "Switch has " + this.switches + " toggles left";
    }
}
