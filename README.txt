/* ABOUT THE PROGRAM! 
-ABOUT THE USER EXPERIENCE:
For optimal experience, use numpad. 
The "UI" was made to be intuitive, so it tells the user what to do.
And for ease of use, the calculator uses "elapsed" values, eliminating the need to use star and stop values, making the inputs simple. 


-ABOUT THE POSSIBLE RED UNDERLINES:
Not sure why the prev_results vector claims it has no members: pushback, back, size, erase or begin.
It worked fine before in Visual Studio 2019, but after moving to Visual Studio 2022, it gives the red underline, but still works..


-ABOUT RUNNING THE CODE: 
The code works as intended in the online compiler used for testing, and the "UI" was created with that in mind. 
The online compiler was necessary, since the computer used to write the code is getting old, and takes a "few" minutes per compile..
*** USED ONLINE COMPILER: 
https://www.onlinegdb.com/online_c++_compiler
-- For ease of use: CTRL + A --> CTRL + C -- To compiler --> CTRL + V --> RUN
On the top left of the screen is a small green RUN button, which starts the program instantly. 
***


-ABOUT DECISIONS: 
The ui does not print the available function list eachtime a function is done, because in the long run the outputfield becomes cluttered.
--! Could be that as the maker of the program, knowing the program and having spent time with it, I have become blind to the real/first time user experince.
	-- It is easy to fix by moving the show_available_func() inside to the while function just below it.


*/
