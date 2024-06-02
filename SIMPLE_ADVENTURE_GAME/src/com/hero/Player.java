package com.hero;

public class Player {
    private String role;
    private double blood;
    private double mana;
    private int level = 1;
    private double attack;

    public Player(String role) {
        this.role = role;
        if (role.equals("Magician")) {
            this.blood = 70.0;
            this.mana = 100.0;
            this.attack = 20.0;
        } else if (role.equals("Fighter")) {
            this.blood = 100.0;
            this.mana = 70.0;
            this.attack = 25.0;
        }
    }

    public int getLevel() {
        return level;
    }
    
    public double getBlood() {
        return blood;
    }

    public double getMana() {
        return mana;
    }

    public double getAttack() {
        return attack;
    }

    public void decreaseBlood(double amount) {
        this.blood -= amount;
    }
    
    public void increaseBlood(double amount) {
        this.blood += amount;
    }
    
    public void decreaseMana(double amount) {
        this.mana -= amount;
    }
    
    public void increaseMana(double amount) {
        this.mana += amount;
    }

    public void increaseLevel() {
        this.level += 1;
    }

    public void display() {
        System.out.println();
        System.out.println("=== Hero Info ===");
        System.out.println("Role\t\t: " + role);
        System.out.println("Level\t\t: " + level);
        System.out.println("HP\t\t: " + blood + "%");
        System.out.println("Mana\t\t: " + mana + "%");
        System.out.println("Attack Power\t: " + attack);
    }
}
