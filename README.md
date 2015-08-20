#ANALOG

Analog is written in c++ and is able to format and analyze
a big amount of Apache logs,depending on the options called with,
it will display the analyse as plain text or as a DotFile.

============================================================================
###Description
Analog must be called with a log file as last argument to 
format and display the 10 most hit pages.

============================================================================
###Options
```
	-x 		 	Exclude file extension that is in "extension.ini"
				(that can be filled up by user)

	-t hour		 	Exclude results out this hour (24 hours format)

	-g DotFileName.dot	A dotfile is done and can be vizualized by using graphviz
				to show link between request

	-c			Clean the URL from "jsession","php?..."
```
=============================================================================
###error code
	0 		Every thing has gone right
	1		ERROR1: The logfile is incorrect
	2		ERROR2: The time is incorrect
	3		ERROR3: The dotfile is incorrect
==============================================================================
###Authors:		- Binomes B 3214 - 

	Yassir Bouiry: yassir.bouiry@insa-lyon.fr
	Cyril Canete:  cyril.canete@insa-lyon.fr
	Robin Royer: robin.royer@insa-lyon.fr
	
===============================================================================
