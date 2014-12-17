#ifndef Graph_h
#define Graph_h

#include "URLData.h"

class Graph

/**
 * Graph class that generates the dot file
 */



{
	public:
		Graph(std::string name);
		/**
		 * Creates a Graph object
		 * @params name : name of the file to generate
		 */

		 ~Graph();
		/**
		 * Destroys the Graph
		 */

		int GenerateDot(URLData*);
		/**
		 * Generates the dot file with the links
		 * @params name : name of the file to generate
		 * @return it returns the error code
		 */


	private:

		std::string dotText;
		std::string fileName;

};

#endif // URLData_h
