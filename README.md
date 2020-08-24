# CarND-Controls-PID-Project
Self-Driving Car Engineer Nanodegree Program

[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)

<img src="./results/pid-intro.gif" width="700" height="500" align="center"/>

## Overview
In this project we revisit the lake race track from the Behavioral Cloning Project. This time, I implemented a PID controller in C++ to maneuver the vehicle around the track!

The simulator provided provided by Udacity (You can download the Simulator [here](https://github.com/udacity/self-driving-car-sim/releases)).. It is provided us with the cross track error (CTE) and the velocity (mph) in order to compute the appropriate steering angle. One more thing. The speed limit has been increased from 30 mph to 100 mph.
Udacity provides a seed project to start from on this project ([here](https://github.com/udacity/CarND-PID-Control-Project)).

## Important Dependencies

The minimum project dependency versions are:

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

Fellow students have put together a guide to Windows set-up for the project [here](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) if the environment you have set up for the Sensor Fusion projects does not work for this project. There's also an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3).

## Project files structure
The directory structure of this repository is as follows:

```
root
|   CMakeLists.txt
|   LICENSE
|   README.md
|   cmakepatch.xt
|   install-mac.sh
|   install-ubuntu.sh
|   set_git.sh
|   
|___src
    |   json.hpp
    |   main.cpp
    |   PID.cpp
    |   PID.h
    

```

## Basic Build Instructions

Note: The project must be buildable using cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

**The main program can be built and ran by doing the following from the project top directory.**

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`, this will create executable
    -  `./pid`, which is our implementation
4. Finally, run it: `./pid`. 

Alternatively some scripts have been included to streamline this process, these can be leveraged by executing the following in the top directory of the project:
```
$ ./clean.sh
$ ./build.sh
$ ./run.sh
```
Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Running the Code

To run the code we need to run both `./pid.sh` using the terminal and the simulator. The output should be like:

`Listening to port 4567
`

Which means that the implemtation code now connected to the simulator right away.

<img src="./results/simulator1-cmd.png" width="800" height="600" align="center"/>

Run the simulator shoud show the below image:

<img src="./results/simulator1.png" width="800" height="600" align="center"/>

Using the right arrow, we need to go to our project "PID Controller":

<img src="./results/simulator2.png" width="800" height="600" align="center"/>

By clicking the "Select" button, the car starts driving. The debugging information shown on the PID controller terminal. A recorded video for the final parameters could be found [here](https://github.com/aliasaswad/CarND-PID-Control-Project-P8/blob/master/results/pid_Final-with-calc_errorType.mp4).

<img src="./results/drive-and-calc.png" width="800" height="300" align="center"/>

## Code Implementation
In this implementation I followed what I had taught in the project lessons.
The PID implementation is done on the [`./src/PID.cpp`](https://github.com/aliasaswad/CarND-PID-Control-Project-P8/blob/master/scr/PID.cpp). The [`PID::UpdateError`](https://github.com/aliasaswad/CarND-PID-Control-Project-P8/blob/master/scr/PID.cpp#L55-#L77) method calculates proportional, integral and derivative errors and the [`PID::TotalError`](https://github.com/aliasaswad/CarND-PID-Control-Project-P8/blob/master/scr/PID.cpp#L13-#L19) calculates the total error using the appropriate coefficients.

## Code Reflection

The three types of the PID components had beed used here in this implementation until we got the final results that makes the car successfully drive on the track. The three components are differential, integral, and proportional. For the **differential**, it helps to counteract the proportional trend to overshoot the center line by smoothing the approach to it. A recorded video for this component could be found [here](https://github.com/aliasaswad/CarND-PID-Control-Project-P8/blob/master/results/pid_Differ_errorType.mp4). And for **integral**, it tries to eliminate a possible bias on the controlled system that could prevent the error to be eliminated. Using this component will makes the car move in a circles. In the case of the simulator, no bias is present. A recorded video for this component could be found [here](https://github.com/aliasaswad/CarND-PID-Control-Project-P8/blob/master/results/pid_Integ_errorType.mp4). Finally, for the **proportional**, it tries to steer the car toward the center line (against the cross-track error). Using this implementation will makes the car overshoots the central line very easily and go out of the road very quickly. A recorded video for this component could be found [here](https://github.com/aliasaswad/CarND-PID-Control-Project-P8/blob/master/results/pid_Prop_errorType.mp4).

### Final implementation used for the project

The final results goten by trying the parameters values manually and each time check the results unitl we found the best values that made the car drive on the track. First, we need to make sure the car can drive straight with zero as parameters. Then add the proportional and the car start going on following the road but it starts overshooting go out of it. Next, we put a value zero for the integral part because this parameter is only move the car out of the road. Finally,  we added the differential to try to overcome the overshooting. The final results after putting all of these parameters togethor made the car drove on the track without going out of it. These parameters increased to minimize the average cross-track error on a single track lap.

<img src="./results/pid-final-with-calc1.gif" width="800" height="300" align="center"/>

**A recorded video for with the final parameters could be found [here](https://github.com/aliasaswad/CarND-PID-Control-Project-P8/blob/master/results/pid_Final-with-calc_errorType.mp4).

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

