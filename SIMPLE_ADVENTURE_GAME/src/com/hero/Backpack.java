package com.hero;

import java.util.ArrayList;

public class Backpack {
    private ArrayList<Item> items;

    public Backpack() {
        this.items = new ArrayList<>();
    }

    public void addItem(Item item) {
        this.items.add(item);
    }

    public Item getItem(int index) {
        if (index >= 0 && index < items.size()) {
            return items.get(index);
        } else {
            return null;
        }
    }

    public void removeItem(int index) {
        if (index >= 0 && index < items.size()) {
            items.remove(index);
        }
    }

    public void display() {
        if (items.isEmpty()) {
            System.out.println("Backpack is empty");
        } else {
            System.out.println("Items in backpack:");
            for (int i = 0; i < items.size(); i++) {
                System.out.println((i + 1) + ". " + items.get(i).getName());
            }
        }
    }
}
