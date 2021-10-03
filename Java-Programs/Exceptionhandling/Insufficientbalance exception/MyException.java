package isufficientbalanceexception;

/**
 *
 * @author DeLL
 */
public class MyException extends Exception {
  public  MyException(String msg){
//supplies this message to the parent class constructor
    super(msg);
  }  
}
