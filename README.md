# Tutorial W01 - Settings things up

This tutorial has two purposes:

1. match your github username to your student ID
2. make sure you can build and run the starter code

## Part 1: match github to student ID

1. Insert your information (full name, student id, nethz username) into `my-info.json`.

2. Commit and push the changes to `my-info.json`. For example:

   ```
   git add my-info.json
   git commit -m "added my information"
   git push
   ```

3. Verify that your changes were uploaded to github.com by checking github.com/DigitalHumans-23/a0-YOUR_GITHUB_NAME

## Part 2: build and run starter code

This tutorial is to make sure your computer and you are both set up for future assignements. For future assignements, you will have to commit and push your solutions to github. Commits (or rather pushes) after the deadline will be disregarded. So make sure you are ready and test out things with this assignment.

### Prerequisites
Make sure you install the following:

- Git (https://git-scm.com)
    + Windows: download installer from website
    + Linux: e.g. `sudo apt install git`
    + MacOS: e.g. `brew install git`
- CMake (https://cmake.org/) 
    + Windows: download installer from website
    + Linux: e.g. `sudo apt install cmake`
    + MacOS: e.g. `brew install cmake`

- Build tools:
    + Windows: Install Microsoft visual studio C++ build tools. (https://visualstudio.microsoft.com/downloads/)
    + Linux: `sudo apt-get install build-essential`
    + MacOS: If you already have the latest version of Xcode, this is not necessary. Otherwise, see this https://www.freecodecamp.org/news/install-xcode-command-line-tools/
     
- Additional dependencies: 
    + Linux: `sudo apt-get install -y --no-install-recommends -qq freeglut3-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev` 
 
### Building the code

On Windows, you can use Git Bash to perform the steps mentioned below.

1. Git clone your project, e.g.:

   ```
   git clone git@github.com:Digital-Humans-23/a0-XXX.git
   ```

2. Run CMake to create project files
    ```
    cd a0-XXX
    mkdir build && cd build
    cmake ..
    ```
3. Compile code and run executable
    - for Linux:
        ```
        make
        ./src/basicApp/basicApp
        ```
    - for MacOS:
        ```
        make
        ./src/apps/basicApp/basicApp
        ```
    - for Windows: 
        * open `build/a0.sln` in Visual Studio
        * in the project explorer, right-click target "app" and set as startup app.
        * Hit F5!

3. Implement the function `math::add` in the file `src/libs/simple-math/src/add.cpp`

4. Check if test passed: `make && make test && ctest -V`

5. Commit and push changes, and check on github if test also passed.

### Some comments

- If you are new to git, there are many tutorials online, e.g. http://rogerdudler.github.io/git-guide/.

- You will not have to edit any CMake file, so no real understanding of CMake is required. You might however want to generate build files for your favorite editor/IDE: https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html

- If you want to use [VS Code](https://code.visualstudio.com/), follow the instructions below:
    - Install the following VS Code extensions.
        - [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
        - [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
    - Create a folder called `.vscode` and copy paste the file `misc/settings.json` into it. 
    - Select a kit/variant and configure the project. See [this](https://vector-of-bool.github.io/docs/vscode-cmake-tools/getting_started.html#configuring-your-project) for more details (this corresponds to ```cmake ..```)
    - Click "Build" button in status bar (bar at the botton) to compile and run the executable by "Launch" button.
    - If you want to debug your code, set cmake mode into "CMake: [Debug]" and click "Launch the debugger" button. 
        - In "CMake: [Debug]" mode, the executable tends to run very slowly. Select "CMake: [Release]" to run the code fast (but in Release mode you cannot use breakpoints). 

![status bar](misc/vscode.png)
