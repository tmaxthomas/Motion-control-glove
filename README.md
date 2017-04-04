# Motion-control-glove
This project contains all the code for my motion control project, both computer-side and glove-side. 
This includes both the program for creating macros and the one for parsing macros from the glove in real time.
NOTE: All computer-side programs must be run as superuser


Specifications for MakeMacros.exe:	
	Format: sudo ./MakeMacros.exe [port#] [filepath]
	To add a new macro: add_macro [macro_name] [macro_length]
	To remove a macro: remove_macro [macro_name]