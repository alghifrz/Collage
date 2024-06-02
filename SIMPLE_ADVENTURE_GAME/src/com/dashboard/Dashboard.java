package com.dashboard;

import java.util.Scanner;
import com.role.SelectRole;

public class Dashboard {
    private static final String DATABASE_FILE = "data.txt";
    private Scanner scan = new Scanner(System.in);
    private char choice;
    private Database database;

    public Dashboard() {
        database = Database.loadFromTextFile(DATABASE_FILE);
    }

    public void display() {
        while (true) {
            System.out.println("====== Game Kocak ======");
            System.out.println();
            System.out.println("Menu:");
            System.out.println("1. Login\n2. Sign Up\n3. Exit");
            System.out.print("Enter your choice: ");
            choice = scan.next().charAt(0);
            scan.nextLine();  // consume the newline character
            if (choice == '1') {
                choiceLogin();
            } else if (choice == '2') {
                choiceSignUp();
            } else if (choice == '3') {
                saveDatabase();
                break;
            } else {
                System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    private void choiceLogin() {
        Login login = new Login(scan, database);
        User user = login.loginUser();
        if (user != null) {
            SelectRole selectRole = new SelectRole(scan, user);
            selectRole.selectRoles();
        }
    }

    private void choiceSignUp() {
        Signup signup = new Signup(scan, database);
        signup.signupUser();
        choiceLogin();
    }

    private void saveDatabase() {
        database.saveToTextFile(DATABASE_FILE);
    }

    public static void main(String[] args) {
        Dashboard dashboard = new Dashboard();
        dashboard.display();
    }
}
