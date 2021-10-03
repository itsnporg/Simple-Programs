import java.util.Scanner;

public class Matrix_Operations{
    Scanner sc = new Scanner (System.in);
    int matrix[][]; //initializing a 2D array for matrix
    int row, column;
    Matrix_Operations ()
    {
        row = column = 0;
        
    }
    Matrix_Operations (int r, int c)
    {
        row = r;
        column = c;
        matrix = new int[row][column];
        
    }
    
    //to create a matrix
    void create ()
    {
        System.out.println ("Enter no. of rows:");
        row = sc.nextInt ();
        System.out.println ("Enter no. of columns:");
        column = sc.nextInt ();
        matrix = new int[row][column];
        System.out.println ("Enter the elements in the Matrix:");
        for (int i = 0; i < matrix.length; i++)
        {
            for (int j = 0; j < matrix[i].length; j++)
            {
                matrix[i][j] = sc.nextInt ();
                
            }
            
        }
        
    }
    
    //to display the matrix
    void display ()
    {
        for (int i = 0; i < matrix.length; i++)
        {
            for (int j = 0; j < matrix[i].length; j++)
            {
                System.out.print (matrix[i][j] + " ");
                
            }
            System.out.println ();
            
        }
        
    }
    
    //to check for a square matrix
    void squarematrix ()
    {
        //if number of rows equals the number of columns in a matrix
        if (row == column)
        {
            System.out.println ("It is a square matrix!!");
            
        }
        else
        {
            System.out.println ("It is not a square matrix!!");
            
        }
        
    }
    
    //to check for an uppertriangular matrix
    void uppertriangular ()
    {
        int flag = 1;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (j < i && matrix[i][j] != 0)
                {
                    flag = 0;
                }
            }
        }
        
        if (flag == 0)
        {
            System.out.println ("It is Not Upper Triangular Matrix!!");
            
        }
        else
        {
            System.out.println ("It is Upper Triangular Matrix!!");
        }
    }
    
    //to add 2 matrices
    void add (Matrix_Operations M)
    {
        //if both matrices have the same number of rows and columns
        if (row == M.row && column == M.column)
        {
            Matrix_Operations c = new Matrix_Operations (row, column);
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    c.matrix[i][j] = matrix[i][j] + M.matrix[i][j];
                }
            }
            System.out.println ("Addition resultant matrix:");
            c.display ();
        }
        
        else
        {
            System.out.println ("Addition is not possible!!");
        }
        
    }
    
    //to multiply 2 matrices
    void mul (Matrix_Operations M)
    {
        //if the number of columns in the first matrix equals to the number of rows in the second matrix
        if (column == M.row)
        {
            Matrix_Operations c = new Matrix_Operations (row, column);
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    int temp = 0;
                    for (int k = 0; k < column; k++)
                    {
                        temp = temp + matrix[i][k] * M.matrix[k][j];
                    }
                    c.matrix[i][j] = temp;
                }
            }
            System.out.println ("Multiplication resultant matrix:");
            c.display ();
        }
        
        else
        {
            System.out.println ("Multiplication is not possible!!");
        }
    }
    
    //to find a transpose matrix
    void transpose ()
    {
        int temp = 0;
        //if the number of rows and columns are equal
        if (row == column)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
            System.out.println ("After Transpose:");
            display ();
        }
        
        else
        {
            Matrix_Operations T = new Matrix_Operations (column, row);
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    T.matrix[j][i] = matrix[i][j];
                }
            }
            System.out.println ("After Transpose:");
            T.display ();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
		Matrix_Operations obj = new Matrix_Operations();
		Matrix_Operations obj1 = new Matrix_Operations();

        //menu display
        System.out.println("~~~~~~MATRIX OPERATIONS~~~~~~");
        do {
            System.out.println("1.Create\n2.Display\n3.Check Square Matrix\n4.Check UpperTriangular Matrix\n5.Transpose\n6.Addition\n7.Multiplication");

            System.out.println("Enter your choice:");
            int ch = sc.nextInt();
            switch(ch)
            {
                case 1:
                    obj.create();
                    break;
                case 2:
                    obj.display();
                    break;

                case 3:
                    obj.squarematrix();
                    break;
                case 4:
                    obj.uppertriangular();
                    break;
                case 5:
                    obj.transpose();
                    break;
                case 6:
                    System.out.println("Create another matrix to add!!");
                    obj1.create();
                    obj.add(obj1);
                    break;
                case 7:
                    obj.mul(obj1);
                    break;
            }
            System.out.println("Press 1 to continue!!");
            
        }
        while(sc.nextInt() == 1);
        System.out.println("----THANK YOU----");
        
    }
    
}