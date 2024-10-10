/* ex12-3: design an airline reservation data structure (info on required fields in textbook) */

struct flight	{
	unsigned short int flightNumber;	// assuming pos only, and relatively small num
	char[3] orgPort;					// originating airport; 3 chars 
	char[3] destPort;					// destination airport; 3 chars
	unsigned short int startTime;		// start time; assuming HHMM
	unsigned short int arrTime;			// arrival time, HHMM
	/* should probably be using the datetime structure defined in ex12-2  which should be 
	 * defined in a separate header file that both these files include but honestly, can't
	 * be assed here (just a practice problem)
	 * /
};

