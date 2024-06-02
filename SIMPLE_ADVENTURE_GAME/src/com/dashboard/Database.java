package com.dashboard;

import java.io.*;
import java.util.ArrayList;

public class Database implements Serializable {
    private static final long serialVersionUID = 1L;
    private ArrayList<User> users;

    public Database() {
        this.users = new ArrayList<>();
    }

    public void addUser(User user) {
        users.add(user);
    }

    public boolean userExists(String username) {
        for (User user : users) {
            if (user.getUsername().equals(username)) {
                return true;
            }
        }
        return false;
    }

    public User getUser(String username, String password) {
        for (User user : users) {
            if (user.getUsername().equals(username) && user.getPassword().equals(password)) {
                return user;
            }
        }
        return null;
    }

    public void saveToFile(String filename) {
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(filename))) {
            out.writeObject(this);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static Database loadFromFile(String filename) {
        Database database = null;
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(filename))) {
            database = (Database) in.readObject();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        return database;
    }

    public void saveToTextFile(String filename) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(filename))) {
            for (User user : users) {
                writer.println(user.getUsername() + "," + user.getPassword());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static Database loadFromTextFile(String filename) {
        Database database = new Database();
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 2) {
                    String username = parts[0];
                    String password = parts[1];
                    database.addUser(new User(username, password));
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return database;
    }
}
