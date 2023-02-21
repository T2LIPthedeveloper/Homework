public class LoopArrayList {
    public static Double sumList(ArrayList<Double> doubleArrayList){
        double sum = 0;
        for (double arrayItem: doubleArrayList) {
            sum += arrayItem;
        }
        return sum;
    }
}
