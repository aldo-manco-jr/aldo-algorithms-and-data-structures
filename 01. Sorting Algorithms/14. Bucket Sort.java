import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/*
 * Created by Aldo Manco
 */

public class Main {
    public static void main(String[] args) {
        int[] radixArray = {47, 25, 45, 86, 13, 30, 87, 92, 15, 94, 57, 29};

        bucketSort(radixArray);

        for (int i = 0; i < radixArray.length; i++) {
            System.out.println(radixArray[i]);
        }
    }

    public static void bucketSort(int[] array) {

        List<Integer>[] buckets = new List[10];

        for (int i = 0; i < buckets.length; i++) {
            buckets[i] = new LinkedList<>();
        }

        for (int i = 0; i < array.length; i++) {
            buckets[hashCode(array[i])].add(array[i]);
        }

        for (List<Integer> bucket : buckets) {
            insertionSort(bucket);
        }

        int j=0;
        for (int i = 0; i < buckets.length; i++) {
            for (int k = 0; k < buckets[i].size(); k++) {
                array[j++] = buckets[i].get(k);
            }
        }
    }

    public static int hashCode(int value) {
        return value / (int) 10;
    }

    public static void insertionSort(List<Integer> list) {
        if (list.size() < 2) return;

        for (int i = 1; i < list.size(); i++) {

            int newElement = list.get(i);
            int j;

            for (j = i; j > 0 && newElement < list.get(j - 1); j--) {
                list.set(j, list.get(j-1));
            }
            list.set(j, newElement);
        }
    }
}
