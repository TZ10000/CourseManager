# CourseManager
Course managing system for student.
课表管理与生成系统
描述：该程序具有输入课程，搜索课程，生成课表以及按需求自动生成课表的功能。

变量定义：
主课程： 学期，学院，课名，课号，上课时间以及课程描述
例如： 	    2021春
           	   工程学院
                  EC440A1，
                 操作系统入门
                 描述：Hello World
                 MW 4:30 pm-6:15 pm
课表：一张具有所有课程的表格，横轴为星期几，纵轴为时间，课程在表中显示为小方格
1.输入课程：用户输入课程信息并放在txt文件中保存。
2.搜索课程： 用户输入学期以及想要搜索的课号，程序输出当前学期，学院的所有课程（以该课为首），如果课不存在则向后生成课号与之接近的课程如 “EC441”。
3.生成课表： 用户选择自己想上的课后，可以生成出具有这些课信息的表格
4.按需求自动生成课表： 用户可以输入本学期中所有自己想上的课的学院以及课号，系统会为学生自动选课并生成课表。如果讨论课与主课程有冲突则在不改变主课程的情况下，搜索其他讨论课并加入课表。
报错条件：
1.没有所选的课程。
2.主课程与主课程之间有冲突。
3.主课程与讨论课有冲突，但已无其他同类讨论课。





Environment setup:
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

Build the project:

Testing:

