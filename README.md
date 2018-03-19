# SAM
Arduino files for SAM microcontroller.


# Folder structure
archive contains old and obsolete code which can be used for reference. 

src and lib are used for the C++ implementations of the arduino test code. (maintained by Controls).

Test code is the current arduino test code

I don't know what wcosa is. 


# Important Constants

We are currently testing with:

20ms Movement time.
255 on PWM up/down.
250 on PWM right/left. 

# Setup instructions
A. 
With the current setup, first, do the following
1. Connect the Arduino to the computer
2. Connect the microscope camera to the computer
3. Set up the microscope by using tcam-view which can be found on the Desktop. 
4. Upload the code to the Arduino through minotaur or the Arduino IDE.

IF THE COMPETITION STAGE IS READY AND THE ROBOT IS ALREADY PLACED, SKIP THE FOLLOWING STEPS.
B. 
The SAM drawer is the bottommost horizontal drawer to the left of the table. Obtain a competition arena from the wafer-holder with the arena. Put a piece of the arena onto the stage in the middle of the solenoids. Breaking the wafers into small enough pieces may be necessary. Contact someone from SAM if you are unclear on how to break them. 

You can obtain the shapes on the same wafer that holds the competition arenas. They should be to the left or right of each arena on the wafer. Use tweezers and avoid damaging the arena. 

Now, in order to get the robot on the stage, use the non-magnetic tweezers and seperate one from the others in the vial. The bag holding the robots should be in the SAM drawer. The vials containing the robots should be in a ziploc bag, and each vial should also contain a ziplock bag. The robots should look like little iron specks, and are square in shape. Ask someone from SAM if you are unable to find the robots or the bag. 


Once robots are obtained, put on the competition arena in the middle of the solenoids. Centering the arena and the robot will be necessary for even movement. 

RESUME 
C. 

1. Add Isopropyl alcohol to stage with robot until arena is fully submerged. Cover arena with glass slide to prevent evaporation of alcohol.

2. Turn on power supply (output should be inactive). 

3. Activate the current build of minotaur at ~/Desktop/minotaur/build. 

4. Activate the power supply's output when ready to test. 

5. Periodically reapply alcohol if it is beggining to evaporate. Also, center arena if necessary.  

6. Keep track of all lost robots on the paper *attribute to the Grinch if you are Controls*. 

