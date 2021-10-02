public class MaxAndNextMax {

    public static void main(String[] args) {

        int[] A = {15, 25, 87, 36, 64};
        int n = A.length;
        int max = A[0];
        int nextMax = A[0];

        for (int i = 0; i < n; i++) {
            if (max < A[i]) {
                max = A[i];

            }
            if (A[i] > nextMax && max < A[i]) {
                nextMax = A[i];

            }
        }

        System.out.println("Maximum number : " + max);
        System.out.println("Next maximum number : " + nextMax);

    }
}