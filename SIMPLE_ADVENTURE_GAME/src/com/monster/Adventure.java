package com.monster;

import java.util.Random;
import java.util.Scanner;
import com.hero.Backpack;
import com.hero.Item;
import com.hero.Player;

public class Adventure {
    private Player player;
    private Backpack backpack;
    private Scanner scan;
    private Random random = new Random();
    private Monster[] monsters = {
        new Monster("Tubes RPL", 90.0, 50.0),
        new Monster("Goblin", 50.0, 10.0),
        new Monster("Smilling Titan", 80.0, 15.0),
        new Monster("Dancing Dragon", 150.0, 25.0),
        new Monster("Stress", 60.0, 12.0),
        new Monster("Tubes PBO", 80.0, 30.0),

    };

    public Adventure(Player player, Backpack backpack, Scanner scan) {
        this.player = player;
        this.backpack = backpack;
        this.scan = scan;
    }

    public void explore() {
        while (true) {
            System.out.println();
            System.out.println("=== Adventure ===");
            System.out.println("1. Move Forward\n2. Move Right\n3. Move Left\n4. Move Back\n5. Check Backpack\n6. Exit Adventure");
            System.out.print("Enter your choice: ");
            char choice = scan.next().charAt(0);
            scan.nextLine();  

            if (choice == '1' || choice == '2' || choice == '3' || choice == '4') {
                encounter();
            } else if (choice == '5') {
                System.out.println();
                backpack.display();
            } else if (choice == '6') {
                break;
            } else {
                System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    private void encounter() {
        int event = random.nextInt(3); 
        if (event == 0) {
            findItem();
        } else if (event == 1) {
            encounterMonster();
        } else {
            System.out.println();
            System.out.println("Gaada Apa-apa cuy!.");
        }
    }

    private void findItem() {
        Item[] items = {
            new Item("Suwir Level 3", 10.0, 5.0),
            new Item("Ayam Geprek Simprug", 15.0, 10.0),
            new Item("Chicken Katsu", 5.0, 1.0),
            new Item("Cheat Potion", 100.0, 100.0),
            new Item("Chicken Oriental", 15.0, 10.0),
        }; 
        Item item = items[random.nextInt(items.length)];
        backpack.addItem(item);
        System.out.println();
        System.out.println("You found a " + item.getName() + " and it has been added to your backpack.");
    }

    private void encounterMonster() {
        Monster monster = monsters[random.nextInt(monsters.length)];
        System.out.println();
        System.out.println(monster.getName() + " is coming, HABISLAH!");
        monster.display();

        while (monster.getHealth() > 0 && player.getBlood() > 0) {
            System.out.println();
            System.out.println("Mau Ngapain??");
            System.out.println("1. Serang\n2. Kabur");
            System.out.print("Enter your choice: ");
            char choice = scan.next().charAt(0);
            scan.nextLine();  // consume the newline character
            System.out.println();
            if (choice == '1') {
                attackMonster(monster);
                if (monster.getHealth() > 0) {
                    monsterAttack(monster);
                }
            } else if (choice == '2') {
                System.out.println();
                System.out.println("Kamu kabur, dasar LEMAH.");
                return;
            } else {
                System.out.println("Invalid choice. Please try again.");
            }
        }

        if (player.getBlood() <= 0) {
            System.out.println();
            System.out.println("You have been defeated by the " + monster.getName() + ".");
            System.out.println("Game Over.");
            System.exit(0);
        } else if (monster.getHealth() <= 0) {
            System.out.println();
            System.out.println("You have defeated the " + monster.getName() + "!");
            player.increaseLevel();
            System.out.println("You leveled up!");
            player.display();
        }
    }

    private void attackMonster(Monster monster) {
        double damage = player.getAttack(); 
        if (player.getMana() <= 0) {
            System.out.println();
            System.out.println("You can't attack, you dont have mana");
        } else {
            System.out.println("You attack the " + monster.getName() + " for " + damage + " and " + (damage*0.5) + " mana cost.");
            monster.decreaseHealth(damage);
            monster.display();
            player.decreaseMana(damage*0.5);
        }
    }

    private void monsterAttack(Monster monster) {
        double damage = monster.getAttackDamage();
        System.out.println();
        System.out.println("The " + monster.getName() + " attacks you for " + damage + " damage.");
        player.decreaseBlood(damage);
        player.display();
    }
}
