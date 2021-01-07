import java.util.LinkedList;
import java.util.ListIterator;

/*
 * Created by Aldo Manco
 */

public class HashtableChaining {
    LinkedList<EmployeeHashtable>[] hashtable;

    public HashtableChaining() {
        this.hashtable = new LinkedList[10];
        for (int i = 0; i < hashtable.length; i++) {
            hashtable[i] = new LinkedList<>();
        }
    }

    public int hashCode(String key) {
        return key.length() % hashtable.length;
    }

    public void put(String key, Employee employee){
        int hashedKey = hashCode(key);
        hashtable[hashedKey].add(new EmployeeHashtable(key, employee));
    }

    public Employee remove(String key){
        int hashedKey = hashCode(key);
        ListIterator<EmployeeHashtable> listIterator = hashtable[hashedKey].listIterator();
        EmployeeHashtable employee = null;
        int index = -1;
        while (listIterator.hasNext()){
            employee = listIterator.next();
            index++;
            if (employee.getKey().equals(key)){
                break;
            }
        }

        if (employee==null){
            return null;
        }else {
            hashtable[hashedKey].remove(index);
            return employee.getEmployee();
        }
    }

    public Employee get(String key){
        int hashedKey = hashCode(key);

        ListIterator<EmployeeHashtable> listIterator = hashtable[hashedKey].listIterator();
        EmployeeHashtable employee = null;

        while (listIterator.hasNext()){
            employee = listIterator.next();
            if (employee.getKey().equals(key)){
                return employee.getEmployee();
            }
        }
        return null;
    }

    public void printHashtable(){
        for (int i = 0; i < 10; i++) {
            if (hashtable[i].isEmpty()){
                System.out.println("Hashtable is Empty");
            }else {
                System.out.print("Hashtable: ");
                ListIterator<EmployeeHashtable> listIterator = hashtable[i].listIterator();
                while (listIterator.hasNext()){
                    System.out.print(listIterator.next().getEmployee() + " -> ");
                }
                System.out.println("null");
            }
        }
    }
}