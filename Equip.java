import java.util.Scanner;

public class Equip{
    private String weaponName;
    private String helmetName;
    private String armorName;

    public Equip(){

    }

    public Equip(String setWeaponName,
                 String setHelmetName,
                 String setArmorName)
    {
        this.weaponName = setWeaponName;
        this.helmetName = setHelmetName;
        this.armorName = setArmorName;
    }

    public void setWeaponName(String weaponName) throws Exception{
        if (weaponName.isEmpty()){
            throw new Exception("Вы ввели пустую строку!");
        }
        this.weaponName = weaponName;
    }


    public void setHelmetName(String helmetName) {
        this.helmetName = helmetName;
    }

    public void setArmorName(String armorName) {
        this.armorName = armorName;
    }

    public String getWeaponName(){
        return weaponName;
    }

    public String getHelmetName(){
        return helmetName;
    }

    public String getArmorName(){
        return armorName;
    }

    public void createEquipKit(){
        String weaponNameStorage;
        String helmetNameStorage;
        String armorNameStorage;

        Scanner input = new Scanner(System.in);

        System.out.print("Введите название оружия: ");
        weaponNameStorage = input.nextLine();

        System.out.print("Введите название шлема: ");
        helmetNameStorage = input.nextLine();

        System.out.print("Введите название бронежилета: ");
        armorNameStorage = input.nextLine();

        this.weaponName = weaponNameStorage;
        this.helmetName = helmetNameStorage;
        this.armorName = armorNameStorage;
    }

    public void printEquipKit() {
        System.out.println("Оружие: " + weaponName);
        System.out.println("Шлем: " + helmetName);
        System.out.println("Бронежилет: " + armorName);

    }

}