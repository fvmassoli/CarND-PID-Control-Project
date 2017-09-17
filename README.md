# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

## Project Description
The goal of this project is to implement an algorithm that is able to drive a simulated car on a track.

In order to do that I implemented a PID controller that is based on the three main components: the P, I and D.

The input data comes from a simulator that gives to the algorithm the cte on which the algorithm evaluates the steering angle of the car.

## Reflection
A video of the implemented PID can be found here https://www.youtube.com/watch?v=FGRTCbF8F_U&feature=youtu.be

The algorightm takes the CTE as input. The CTE simply quantify the distance (in this case Euclidean) of the car from the ideal trajectory. Based on it's value the algorithm evaluates the steering angle.

As said above, the PID is made of three components:
* "P" is the proportional term. This term has the major direct impact on the steering angle. It sets a steering angle that is directly proportional to the CTE. Althought this term can help to approach very quickly the ideal trajectory since it can give very high sterring angle at the same time it can cause oscillations with very large amplitude. In particular a large value for this value will have the effect of causing very large oscillation while a too small value can cause the car to go out of the road in the curves since it will react with too small steering angle.
* "I" is the integral term. It takes into account the integral of CTE over the past time and it is used to reduce systematic bias. 
* "D" is the differential term. In order to mitigate the effect of the "P" term, the differential term where the steering angle is proportional to the first derivative of the CTE. This term gives a much smoother approach to the ideal trajectory since the amplitude of the steering angle will depend of the "velocity" at which the CTE will change. 

### Results
Before to reach the final results I tried different implementations. In particular I also tried to use Twiddle but finally I have found very nice results even w/o using it. For that reason I commented that part od the code. At the beginning I tuned the hyperparameters by hand and then after few laps the algorithm set proper values for them and the car appeared to be quite stable (video https://www.youtube.com/watch?v=FGRTCbF8F_U&feature=youtu.be). The can never crashed or exited the track.
The inital value for the paramters has been set to 0.2, 3.0, 0.004 for P, D and I respectively.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
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

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

