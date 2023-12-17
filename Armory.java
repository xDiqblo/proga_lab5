public class Armory {
    private int stormtrooperGearCount;
    private int sniperGearCount;
    private int artilleryGearCount;
    private Equip[][] gearList;

    public Armory(){
        this.stormtrooperGearCount = 0;
        this.sniperGearCount = 0;
        this.artilleryGearCount = 0;
        this.gearList = new Equip[3][];
    }

    public Armory(int stormtrooperGearCount,
                  int sniperGearCount,
                  int artilleryGearCount,
                  Equip[][] gearList){
        this.stormtrooperGearCount = stormtrooperGearCount;
        this.sniperGearCount = sniperGearCount;
        this.artilleryGearCount = artilleryGearCount;
        this.gearList = gearList;
    }

    public int getStormtrooperGearCount() {
        return stormtrooperGearCount;
    }

    public int getSniperGearCount() {
        return sniperGearCount;
    }

    public int getArtilleryGearCount() {
        return artilleryGearCount;
    }

    public Equip[][] getGearList() {
        return gearList;
    }

    public void setStormtrooperGearCount(int setStormtrooperGearCount) {
        this.stormtrooperGearCount = setStormtrooperGearCount;
    }

    public void setSniperGearCount(int setSniperGearCount) {
        this.sniperGearCount = setSniperGearCount;
    }

    public void setArtilleryGearCount(int setArtilleryGearCount) {
        this.artilleryGearCount = setArtilleryGearCount;
    }

    public void setGearList(Equip[][] setGearList) {
        this.gearList = setGearList;
    }

    public void addGearToArmory(Equip newEquipKit, int gearType) throws Exception{
        int gearTypeCount = 0;
        if (gearType < 1 | gearType > 3){
            throw new Exception("Введён неверный тип снаряжения!");
        }
        switch (gearType) {
            case (1):
                gearTypeCount = this.getStormtrooperGearCount();
                break;
            case (2):
                gearTypeCount = this.getSniperGearCount();
                break;

            case (3):
                gearTypeCount = this.getArtilleryGearCount();
                break;

            }
            this.gearList[gearType - 1][gearTypeCount - 1] = newEquipKit;
    }

    public void printGearInArmory(){
        int gearTypeCount;
        for (int i = 0; i < 3; i++){
            gearTypeCount = this.gearList[i].length;
            if (i == 0){
                System.out.println("Снаряжение штурмовиков:");
            }
            else if(i == 1){
                System.out.println("Снаряжение снайперов:");
            }
            else if(i == 2){
                System.out.println("Снаряжение артиллеристов:");
            }
            for (int j = 0; j < gearTypeCount; j++){
                System.out.println("Комплект " + (j + 1) + ":");
                this.gearList[i][j].printEquipKit();
            }

        }
    }
}
