package com.hero;

public class Item {
    private String name;
    private double healthEffect;
    private double manaEffect;

    public Item(String name, double healthEffect, double manaEffect) {
        this.name = name;
        this.healthEffect = healthEffect;
        this.manaEffect = manaEffect;
    }

    public String getName() {
        return name;
    }

    public double getHealthEffect() {
        return healthEffect;
    }

    public double getManaEffect() {
        return manaEffect;
    }
}
