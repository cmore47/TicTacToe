#include "error.hpp"

using namespace std;

// This function uses an error code to add the appropriate text to the error variable in the board class.
void findError(board& b, int errCode)
{
	switch (errCode)
	{
	case -1:
		b.addError("Uh oh, looks like an invalid value was entered!"); // -1, Invalid number.
		b.modDoSpcAgain(true);
		break;

	case -2:
		b.addError("Uh oh, an invalid argument error has occured!"); // -2, Invalid argument error.
		b.modDoSpcAgain(true);
		break;

	case -3:
		b.addError("Uh oh, that space is used!"); // -3, Taken space.
		b.modDoSpcAgain(true);
		break;

	default:
		b.addError("Uh oh, and unknown error has occured!"); // Unknown error has occured.
		b.modDoSpcAgain(true);
		break;
	}
}