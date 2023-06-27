package Week14.Practice2;

import java.util.ArrayList;
import java.util.List;

public class PriorityQueue<T> {
    private List<T> items;
    private List<Integer> priorities;

    public PriorityQueue() {
        items = new ArrayList<>();
        priorities = new ArrayList<>();
    }

    public void add(T item, int priority) {
        items.add(item);
        priorities.add(priority);
        sort();
    }

    public T remove() {
        if (items.isEmpty()) return null;

        T highestPriorityItem = items.get(0);
        items.remove(0);
        priorities.remove(0);
        return highestPriorityItem;
    }

    private void sort() {
        int size = priorities.size();
        for (int i = size - 1; i >= 0; i--) {
            for (int j = 1; j <= i; j++) {
                if (priorities.get(j - 1) < priorities.get(j)) {
                    swap(j - 1, j);
                }
            }
        }
    }

    private void swap(int i, int j) {
        T tempItem = items.get(i);
        int tempPriority = priorities.get(i);

        items.set(i, items.get(j));
        priorities.set(i, priorities.get(j));

        items.set(j, tempItem);
        priorities.set(j, tempPriority);
    }
}

