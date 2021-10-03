# Constructors And Destructors In OOPS



>**Definitions :**


* **Constructor :** Constuctor is basically a **member function** of the class **which initializes the object of the class** in the main function. 
    * It **runs in default** even if we not make in the public part of the class.

    * To declare a constructor (also a member function) in the public part of the class we should have to **give it name as same as the class' name**.

    * A constructor is **automatically** called when an object in created in the main function.

    * Constructors **don't have return** type.

    * ### Types of constructors:
        * 1) *Default Constructors* :  Doesn't take any arguments.



        * 2) *Parameterized Constructors* : Take arguments and is used to print given arguments in main function.


        * 3) *Copy Constructors* : It intializes an object using the another object in the same class. Basically it copies the data of another object for the obect made by it.


* **Destructors :** This is also a **member function** which **destructs or delete** the object in the main function. It is initialize with the "~" along with the same class name.

    * **When it is called :**
        * A function ends.
        * A program ends.
        * A block containg local variable ends.
        * A delete operator is called.
        






