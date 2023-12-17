import java.util.ArrayList;
import java.util.Scanner;

public class Proga_lab3 {

    public static void main(String args[]) throws Exception {
        /*System.out.println("Введите название оружия: ");
        String weaponName;
        Equip equipKit1 = new Equip();
        Scanner input = new Scanner(System.in);
        weaponName = input.nextLine();
        try {
            equipKit1.setWeaponName(weaponName);
            System.out.println("Оружие: " + equipKit1.getWeaponName());
        }
        catch (Exception exception){
            System.out.println(exception.getMessage());
        }*/

        Equip stormtrooperKit = new Equip("AK-47", "6B33", "6B11-M");
        Equip sniperKit = new Equip("ВСК-94", "6B47", "Модуль-5М");
        Equip artillerymanKit = new Equip("Абакан", "П7", "6B13");
        Equip gearList[][] = new Equip[3][];
        gearList[0] = new Equip[2];
        gearList[1] = new Equip[1];
        gearList[2] = new Equip[1];

        gearList[0][0] = stormtrooperKit;
        gearList[1][0] = sniperKit;
        gearList[2][0] = artillerymanKit;

        Equip stormtrooperKit2 = new Equip("VAL", "6B37", "6B11-M");
        Armory armory1 = new Armory(2,1,1, gearList);
        armory1.addGearToArmory(stormtrooperKit, 1);
        armory1.printGearInArmory();


    }
}
