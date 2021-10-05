import java.util.Scanner;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.lang.Math;
public class AgeDifference {

	public static void main(String[] args) {
		SimpleDateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy"); // Stating the format that will be used
		Scanner scanner = new Scanner(System.in);
		while (true) {
			System.out.println("Write the date in the format: dd-mm-yyyy"); // Ex 20-03-1990
			System.out.print("Enter person A's date of birth: ");
			String inputPersonA = scanner.nextLine();
			System.out.print("Enter person B's date of birth: ");
			String inputPersonB = scanner.nextLine();

			try {
				Date personA = dateFormat.parse(inputPersonA); // The birth date of person A
				Date personB = dateFormat.parse(inputPersonB); // The birth date of person B
				int ageDiff = (int) ((personB.getTime() - personA.getTime()) / (24 * 60 * 60 * 1000)); // Calculating
				// the age difference between person A & B in days
				if (ageDiff > 0) // If ageDiff is bigger than 0, it means that person A is older
					System.out.println("Person A is older than Person B by " + ageDiff + " days");
				else {
					// Otherwise person B is older
					ageDiff = ageDiff * -1; // Convert ageDiff from negative to positive
					System.out.println("Person B is older than Person A by " + ageDiff + " days");
				}
				break;
			}
			// If either of the dates are incorrect, the user will get to try again until it is correct
			catch (Exception ex) {
				System.out.println("Invalid, try again by pressing Enter");
				scanner.nextLine();
				continue;

				
			}
			
		}
		scanner.close();
	}
}
