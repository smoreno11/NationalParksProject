CODING STANDARDS

Throughout your code there should be short comment boxes explaining calculations done
in certain segments. Also make sure to put spaced inbetween certin things explain below.

Example:

        int x, y, z;
	
        x = 5;     // can be commented like this 
        y = 10;    // 
        z = x + y; // 
        /************************
         or like this 
        *************************/
	
Variables - Variables must be descripitive, lined up, and put in this format.
Example: 

	    int    sumOfNumbers;
	    string firstName;

Each variable put in a variable comment section with a short description.
Example:

            int x, y, z;
	    /*********************************************
	     int x - used to hold a number to add
	     int y - used to hold a number to add
	     int z - used to hold the sum of both x and y variables
	    **********************************************/
--------------------------------------------------------------------------------------------------
Functions - Functions must be documented by what they do and what parameters they accept or their return value.
Example:

	    void printStudent(string firstName, string lastName);
	    /********************************************************************
             void printStudent - is a function that will print out
                                 both the first and last name of a 
                                 student.
                                 Parameters:
                                            firstName - first name of the student
                                            lastName  - last name of the student
            ***********************************************************************/
--------------------------------------------------------------------------------------------------
