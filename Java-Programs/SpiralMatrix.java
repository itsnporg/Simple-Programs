/**
 * Spiral Matrix
 */

public class SpiralMatrix {
  public static int[][] spiralMatrix(int count) {
    int[][] result = new int[count][count];
    int rowStart = 0;
    int rowEnd = count - 1;
    int columnStart = 0;
    int columnEnd = count - 1;
    int counter = 1;

    while (columnStart <= columnEnd && rowStart <= rowEnd) {
      // Top section
      for (int i = columnStart; i <= columnEnd; i++) {
        result[rowStart][i] = counter;
        counter++;
      }

      rowStart++;

      // Right Section
      for (int i = rowStart; i <= rowEnd; i++) {
        result[i][columnEnd] = counter;
        counter++;
      }

      columnEnd--;

      // bottom section
      for (int i = columnEnd; i >= columnStart; i--) {
        result[rowEnd][i] = counter;
        counter++;
      }

      rowEnd--;

      // left section
      for (int i = rowEnd; i >= rowStart; i--) {
        result[i][columnStart] = counter;
        counter++;
      }

      columnStart++;

    }

    return result;
  }

  public static void main(String[] args) {

    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        System.out.print(SpiralMatrix.spiralMatrix(6)[i][j] + "   ");
      }

      System.out.println("");
    }
  }
}