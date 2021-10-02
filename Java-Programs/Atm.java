package atm;

import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class Main {
	//Global vars
	public static int balance = 0;
	public static int pin = 1234;
	public static boolean first = true;
	public static int depositAmount;
	public static int withdrawAmount;
	public static int count = 0;

	//**********************************************************************************   Main func
	public static void main(String[] args) {
		login();
	}

	//**********************************************************************************   Log in
	public static void login() {


		System.out.println("**************************");
		System.out.println("* Welcome to BS bank atm *");
		System.out.println("**************************");
		System.out.print("\nPlease insert your card and enter your atm pin.(default:1234) ");
		logInPin();
		timeDelay(800);

	}

	private static void logInPin() {
		int userPin;
		Scanner sc = new Scanner(System.in);
		userPin = sc.nextInt();
		if(count>=3){
			System.out.println("Congratulations, Your card is blocked.");
			timeDelay(1000);
			System.exit(0);
		}

		if (pinAuth(pin, userPin)) {
			timeDelay(400);
			homepage();
		} else {
			System.out.println("Invalid pin. Try again"+(3-count)+" attempt left");
			count++;
			logInPin();
		}
		sc.close();
	}


	//**********************************************************************************   Homepage
	public static void homepage() {

		int index;
		if (first) firstLogin();
		System.out.println("**************************");
		System.out.println("* Welcome to BS bank atm *");
		System.out.println("**************************");
		System.out.println("1. Withdraw");
		System.out.println("2. Deposit");
		System.out.println("3. Check Balance");
		System.out.println("4. Change atm pin");
		System.out.println("5. Log out");
		Scanner sc = new Scanner(System.in);
		index = sc.nextInt();

		switch (index) {
			case 1 -> withdraw();
			case 2 -> deposit();
			case 3 -> checkBalance();
			case 4 -> changePin();
			case 5 -> logOut();
			default -> {
				System.out.println("Invalid input");
				homepage();
			}
		}
		sc.close();

	}

	//**********************************************************************************   Redirect
	private static void redirectMessage() {
		System.out.print("\n\tRedirecting you in ");
		for (int i = 1; i <= 3; i++) {
			System.out.print(i + " ");
			timeDelay(800);
		}
		System.out.println("");

	}

	//**********************************************************************************   Deposit
	private static void deposit() {
		System.out.println("*************************");
		System.out.println("***** DEPOSIT MONEY *****");
		System.out.println("*************************");
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter amount to deposit: ");
		depositAmount = sc.nextInt();
		System.out.print("Enter your pin: ");
		depositPin();
		sc.close();

	}

	private static void depositPin() {
		Scanner sc = new Scanner(System.in);
		int userPin = sc.nextInt();
		cardBlockMsg();
		if (pinAuth(pin, userPin)) {
			balance += depositAmount;
			timeDelay(1000);
			System.out.println("Rs." + depositAmount + " deposited in your account");
			timeDelay(1000);
			System.out.println("Your new balance is " + balance);
		} else {
			timeDelay(900);
			count++;
			System.out.println("Invalid pin. Try again ."+(3-count)+" attempt left");
			depositPin();
		}
		timeDelay(1000);
		redirectMessage();
		homepage();
		sc.close();
	}

	//**********************************************************************************   Time Delay
	//Adds time delay in execution
	private static void timeDelay(int ms) {
		try {
			TimeUnit.MILLISECONDS.sleep(ms);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	//**********************************************************************************   Log out
	private static void logOut() {
		System.out.print("Are you sure to exit? y/n ");
		Scanner sc = new Scanner(System.in);
		String index = sc.next();
		if (index.equalsIgnoreCase("y")) {
			timeDelay(1000);
			System.exit(0);
		} else homepage();
		sc.close();

	}

	//**********************************************************************************   Change pin
	private static void changePin() {
		System.out.print("Please enter old pin:");
		Scanner sc = new Scanner(System.in);
		int userPin = sc.nextInt();
		cardBlockMsg();
		if (!pinAuth(pin, userPin)) {
			System.out.println("Invalid pin. Try again. "+(3-count)+" attempt left");
			count++;
			changePin();
		}
		System.out.print("Please enter new pin:");
		pin = sc.nextInt();
		System.out.println("Your pin is successfully changed.");
		timeDelay(1000);
		redirectMessage();
		homepage();
		sc.close();
	}

	//**********************************************************************************   Check Balance
	private static void checkBalance() {
		timeDelay(1000);
		System.out.println("Your current balance is " + balance);
		redirectMessage();
		homepage();
	}

	//**********************************************************************************   Pin Authorization
	private static boolean pinAuth(int pin, int defPin) {
		return pin == defPin;
	}

	//**********************************************************************************   Withdraw
	private static void withdraw() {
		int withdrawAmount;
		System.out.println("**************************");
		System.out.println("***** WITHDRAW MONEY *****");
		System.out.println("**************************");
		System.out.print("Enter amount to withdraw: ");
		bounceCheck();
		System.out.print("Enter your pin: ");


		withdrawPin();

	}

	private static void bounceCheck() {
		Scanner sc = new Scanner(System.in);
		withdrawAmount = sc.nextInt();
		if (balance < withdrawAmount) {
			System.out.println("Sorry, You don't have enough Balance.");
			System.out.println("Your current balance is Rs." + balance);
			System.out.println("Please enter amount less than or equal to your current balance");
			bounceCheck();
		}
	}

	private static void withdrawPin() {
		Scanner sc = new Scanner(System.in);
		cardBlockMsg();
		int userPin = sc.nextInt();
		if (pinAuth(pin, userPin)) {
			balance -= withdrawAmount;
			timeDelay(1000);
			System.out.println("Rs." + withdrawAmount + " withdrawn from your account\n");
			timeDelay(1000);
			System.out.println("Your new balance is " + balance);
		} else {
			timeDelay(900);
			count++;
			System.out.println("Invalid pin. Try again "+(3-count)+" attempt left");
			withdrawPin();
		}
		timeDelay(1000);
		redirectMessage();
		homepage();
		sc.close();
	}

	//**********************************************************************************   First Log in
	private static void firstLogin() {
		first = false;
		System.out.println("You seem to have log in for the first time\n* Please setup your atm pin\n* Please deposit your money.\n");
		timeDelay(700);
		setPin();
		System.out.println("\n");
		timeDelay(500);
		deposit();
	}
	private static void setPin(){
		System.out.print("Enter new pin for you: ");
		Scanner sc = new Scanner(System.in);
		pin = sc.nextInt();
	}
	private static void cardBlockMsg(){
		if(count>=3){
			System.out.println("Too many invalid pin attempts. Congratulations, Your card is blocked.");
			timeDelay(1000);
			System.exit(0);
		}
	}
}
