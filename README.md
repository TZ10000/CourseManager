# CourseManager
Course schedule generate system. Student can input their major(minor), their topic of interest, their expect workload, and their expect graduate quarter(semesters). The system can produce a quarter(semester) base schedule(no time confliction) for the student.

## Input: 
Course schedule for all courses(schedule), All major course requirement list(majorReq), Special topic cover list(specialTopics), If their school are quarter base or not(quarter), Expected workload for each quarter/semester(expectedWorkLoad), Expected graduate quarter(expectedGraduateQuarter).

Format of input:

schedule, majorReq, and specialTopics are stored in .txt files. All other inputs are passed in by command line input.

Example of schdule(json format?):

Coursename:     CSE 1

Section name:   A01

Instructor:     Bill the coder

Classroom:      Edward's Spaceship 

Time:           MWF 9:00 - 9:50

DI:             Th 10:00 - 10:50


Example of majorReq:

Major:          CSE

Lower division: CSE 1, CSE 3, ...

Upper division: CSE 100, CSE 101...


Example of specialTopics:

Major:          CSE

Topics:         System      - CSE 120, CSE 123..

                Network     - CSE 186, CSE 199..

                ..


## Output: 
The organized course schedules for all quarters(semester). There may be some different versions, produce them all.

Format of course schedule: x axies are the day in a week, y axies are the time for each day. The course will be shown in the grids with the location and name of professor.

For example: 	 

Example of a course schedule:


## Errors that may happen:
There is no way to generate a schedule with the given inputs. Such like you want to spend 3 quarters to guadrate, or you expect workload of 1 course a quater. Mostly this will not happen.



## Environment setup:
1.	Clone the project: 

2.	Download and install Docker Desktop: https://www.docker.com/products/docker-desktop
-	Note: Windows users, when installing Docker it may ask you if you want to configure it for running Windows containers or Linux containers. Choose Linux containers.
-	Note: Windows users, if you are running Windows Home edition, first read the note below the next item!
-	Note: Docker Desktop for Windows requires the Hyper-V Windows feature which is not available on Home-edition. If you are running Windows Home-edition, install Docker Toolbox instead: https://docs.docker.com/toolbox/toolbox_install_windows/

3.	Open VS code, click the "Extensions" icon on the left and install the "Remote Development" extension by Microsoft Remote Development Extension

4.	Open the project in VSCode, it will ask you if you want to open it in the container, click reopen in the container.

If you don't see the popup, you can also open the devcontainer with a command.
open the Command Palette in VSCode: ctrl+shift+p (cmd+shift+p on mac)
type "reopen" and hit enter

5.	The first time you are opening the devcontainer it will take a couple of minutes to install. But if you reopen it again at a later moment it should only take a matter of seconds.

6.	Once the devcontainer is up and running you'll see the files in your project reappear on the left


7.	Open bash in the VSCode Terminal tab:  
If you don't see a TERMINAL tab in the bottom panel of your screen, hit ctrl+`
If you don't see a "Bash" option in the dropdown, click the plus icon to the right of the dropdown

## Build the project:
This project uses the meson build system along with ninja. In short, meson is comparable to cmake, it helps you configure your build. And ninja is comparable to make, which helps you actually build your binaries. Ninja uses the file called compile_commands.json in the build directory generated by meson to find out how to build your binaries. You can find more information on meson here: https://mesonbuild.com/

To initialize the build setup using meson run: meson build in the terminal.

A folder with the name "build" has now appeared in your project (but no executables have been built yet)

To compile all the executables type: ninja -C build (-C build means we're first going into the build directory before running any of the ninja commands)

To compile a single executable after build setup, type: ninja -C build followed by the path of the executable. For instance, to compile main in bst folder, type ninja -C build test/bst/main.cpp.executable

All the executables are under ./build/test/. For instance, to run the main executable in bst folder, type: ./build/test/bst/main.cpp.executable

(Take a look at the meson.build files in the project root, src and test directories to understand how the build process works.)

## Testing:
There are 2 ways of running the unit tests (files with test_ prefix in test folder):

meson test -C build

ninja -C build test

Both of these commands have their own special use cases:


Running a test under GDB

meson test -C build --gdb 'the name of my test'

Running all the tests under valgrind

meson test -C build --wrapper=valgrind

Other than unit tests, there are also testing executables compiled using your code (like main.cpp.executable).


Compiling a single testing executable

ninja -C build test/path/file-name.cpp.executable

If you have already compiled testing executable, you can run it like so: ./build/test/path/file-name.cpp.executable

