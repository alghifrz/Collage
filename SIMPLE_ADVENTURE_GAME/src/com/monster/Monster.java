package com.monster;

public class Monster {
    private String name;
    private double health;
    private double attackDamage;

    public Monster(String name, double health, double attackDamage) {
        this.name = name;
        this.health = health;
        this.attackDamage = attackDamage;
    }

    public String getName() {
        return name;
    }

    public double getHealth() {
        return health;
    }

    public double getAttackDamage() {
        return attackDamage;
    }

    public void decreaseHealth(double amount) {
        this.health -= amount;
    }

    public void display() {
        System.out.println("Monster\t\t: " + name);
        System.out.println("Health\t\t: " + health);
        System.out.println("Attack Damage\t: " + attackDamage);
    }
}
