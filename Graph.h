#ifndef Graph_h
#define Graph_h

#include "URLData.h"

class Graph


{
	public:
		Graph(std::string name);
		/**
		 * Creates file
		 * @params isOptionG true if the user uses -g option
		 * Creates a dataMapG if isOptionG is true, else creates a dataMapR
		 */

		 ~Graph();
		/**
		 * Destroys the Graph
		 */

		int GenerateDot(URLData*);

	private:

		std::string dotText;
		std::string fileName;

};

#endif // URLData_h
