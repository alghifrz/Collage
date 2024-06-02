package com.dashboard;

import java.util.Scanner;

public class Login {
    private Scanner scan;
    private Database database;

    public Login(Scanner scan, Database database) {
        this.scan = scan;
        this.database = database;
    }

    public User loginUser() {
        System.out.println();
        System.out.println("=== Login ===");
        System.out.print("Enter a username: ");
        String username = scan.nextLine();
        System.out.print("Enter a password: ");
        String password = scan.nextLine();

        User user = database.getUser(username, password);
        if (user != null) {
            System.out.println("Login successful.");
            System.out.println();
            System.out.println("=== Welcome " + username + "! ===");
            System.out.println();
            return user;
        } else {
            System.out.println("Login failed.\nAccount does not exist or incorrect password.");
            System.out.println();
            return null;
        }
    }
}
