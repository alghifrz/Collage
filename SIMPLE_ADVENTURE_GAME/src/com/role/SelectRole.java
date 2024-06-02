package com.role;

import java.util.Scanner;
import com.dashboard.User;
import com.hero.Backpack;
import com.hero.Item;
import com.hero.Player;
import com.monster.Adventure;

public class SelectRole {
    private Scanner scan;
    private User user;
    private Player player;
    private Backpack backpack;

    public SelectRole(Scanner scan, User user) {
        this.scan = scan;
        this.user = user;
        this.backpack = new Backpack();
    }

    public void selectRoles() {
        System.out.println("Choose your Role:");
        System.out.println("1. Magician\n2. Fighter");
        System.out.print("Your choice: ");
        char choice = scan.next().charAt(0);
        scan.nextLine();  // consume the newline character
        if (choice == '1') {
            player = new Player("Magician");
        } else if (choice == '2') {
            player = new Player("Fighter");
        } else {
            System.out.println("Invalid choice. Defaulting to Fighter.");
            player = new Player("Fighter");
        }
        player.display();
        mainMenu();
    }

    private void mainMenu() {
        while (true) {
            System.out.println();
            System.out.println("=== Main Menu ===");
            System.out.println("1. Open Backpack\n2. Start Adventure\n3. Hero Info\n4. Use Potion\n5. Exit");
            System.out.print("Enter your choice: ");
            char choice = scan.next().charAt(0);
            scan.nextLine();  // consume the newline character
            if (choice == '1') {
                openBackpack();
            } else if (choice == '2') {
                startAdventure();
            } else if (choice == '3') {
                player.display();
            } else if (choice == '4') {
                usePotion();
            } else if (choice == '5') {
                break;
            } 
            else {
                System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    private void openBackpack() {
        System.out.println();
        backpack.display();
    }

    private void startAdventure() {
        Adventure adventure = new Adventure(player, backpack, scan);
        adventure.explore();
    }

    private void usePotion() {
        System.out.println();
        System.out.println("=== Use Potion ===");
        System.out.println("Choose a potion to use:");
        backpack.display();
        System.out.print("Enter the number of the potion: ");
        int choice = scan.nextInt();
        scan.nextLine();  // consume the newline

        Item item = backpack.getItem(choice - 1); // Get item by index
        if (item != null) {
            double healthEffect = item.getHealthEffect();
            double manaEffect = item.getManaEffect();

            player.increaseBlood(healthEffect);
            player.increaseMana(manaEffect);

            System.out.println("You used " + item.getName() + "! HP increased by " + healthEffect + " and Mana increased by " + manaEffect + ".");
            backpack.removeItem(choice - 1); // Remove item from backpack
        } else {
            System.out.println("Invalid potion selection.");
        }
    }

}
