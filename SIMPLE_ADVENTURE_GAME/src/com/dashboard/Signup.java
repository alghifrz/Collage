package com.dashboard;

import java.util.Scanner;

public class Signup {
    private Scanner scan;
    private Database database;

    public Signup(Scanner scan, Database database) {
        this.scan = scan;
        this.database = database;
    }

    public void signupUser() {
        System.out.println();
        System.out.println("=== Sign Up ===");
        System.out.print("Enter a username: ");
        String username = scan.nextLine();
        System.out.print("Enter a password: ");
        String password = scan.nextLine();
        System.out.print("Confirm password: ");
        String confirmPassword = scan.nextLine();

        if (!password.equals(confirmPassword)) {
            System.out.println("Passwords do not match. Please try again.");
            return;
        }

        if (database.userExists(username)) {
            System.out.println("Username already exists. Please choose a different username.");
            return;
        }

        database.addUser(new User(username, password));
        System.out.println("Sign Up successful. Please log in now.");
        System.out.println();
    }
}
