# EE407 Process Control Project - Ball and Beam System with Electronic Controller

This repository contains the term project for the EE407 Process Control course at METU EEE. The team, consisting of Ahmet Cankardes, [Furkan Karatoprak](https://www.linkedin.com/in/furkan-karatoprak-5991201bb/), and [Nermin Bozkurt](https://www.linkedin.com/in/nerminbozkurt/), developed an innovative approach to the classic Ball and Beam System using an Arduino ultrasonic sensor and a cool Hot Wheels car 🚗.

## Project Definition

The objective of this experiment was to investigate the effects of P, PI, and PID controllers on the Ball and Beam System. The team utilized a Hot Wheels car with a straight surface attached to it to improve measurements instead of a ball, enabling it to move on rails(rails are maden by wooden chopsticks 😃).

<p align="center">
  <img src="/images/setup.png" alt="Figure 1 - Setup"/>
</p>

<p align="center">
  <em>Figure 1 - Setup</em>
</p>

## Background Information on Ball and Beam Setup

The ball and beam setup is a classic control system widely used in control theory. It involves a horizontal beam connected to a motor that adjusts the beam's slope, with a ball placed on the beam free to move. The setup parameters are provided in Figure 2 and Table 1.

<p align="center">
  <img src="/images/diagram.png" alt="Figure 2 - Model Diagram"/>
</p>

<p align="center">
  <em>Figure 2 - Model Diagram</em>
</p>

#### System Parameters

*Table-1. Required Parameters for Setup*

| Parameter                        | Value        |
| -------------------------------- | ------------ |
| Mass of the car (m1)              | 31.55 g      |
| Mass of the car wheel (m2)        | 1 g          |
| Radius of the wheel (R)           | 0.55 cm      |
| Lever arm offset (r)              | 0.038 m      |
| Gravitational acceleration (g)    | 9.8 m/s^2    |
| Length of the beam (L)            | 35.5 cm      |

Since the rotational effect of wheels are too low, you can just ignore it. Also, this parameters can vary if you built your own setup. Please update them accordingly 🙂.

### Experimental Setup

The experimental setup includes a digital controller, a servo motor attached to the beam, and an HC-SR04 ultrasonic distance sensor. The Futaba S3003 servo motor controls the slope of the beam, and an Arduino UNO adjusts the slope based on data acquired from the sensor.

The [Electronoobs](https://www.youtube.com/@ELECTRONOOBS) designs are used for 3D parts. You can find more [here](https://youtu.be/JFTJ2SS4xyA?si=9nZ70lV41_FnEzLK). Also, you can see our connection diagram in Figure 3 for Arduino, Servo Motor and HC-SR04 sensor.

<p align="center">
  <img src="/images/connections.png" alt="Figure 3 - Connection Diagram"/>
</p>

<p align="center">
  <em>Figure 3 - Connection Diagram</em>
</p>

## Controller Approach

### Proportional (P) Controller
The Proportional (P) controller adjusts the system based on the current error, which is the difference between the desired setpoint and the current position. Increasing the P value generally improves the response time but may lead to overshooting.

### Integral (I) Controller
The Integral (I) controller focuses on the accumulated error over time. It is effective in eliminating steady-state errors but may cause instability if set too high.

### Derivative (D) Controller
The Derivative (D) controller anticipates future behavior based on the rate of change of the error. It helps dampen oscillations and improve stability.

### Proportional-Integral-Derivative (PID) Controller
The PID controller combines P, I, and D actions to achieve a balance between responsiveness, elimination of steady-state error, and stability.

<p align="center">
  <img src="/images/system_diagram.png" alt="Figure 4 - Controller Diagram"/>
</p>

<p align="center">
  <em>Figure 4 - Controller Diagram</em>
</p>

## Code Explanation

The provided Arduino code (`PID.ino`) implements a PID controller to control the Ball and Beam System. The code utilizes an ultrasonic sensor, a servo motor, and PID library functions.

Adjust the PID coefficients (`Kp`, `Ki`, `Kd`) based on your system characteristics. Experiment with different values to find the optimal settings for your specific setup.

## Saving and Plotting Data

When it comes to interacting with different sensors and devices, the Arduino microcontroller platform proves to be a reliable and adaptable instrument. However, Arduino faces a significant limitation in directly publishing data to a file on a linked PC. The microcontroller is not inherently designed to communicate directly with the file system of a computer, preventing it from independently saving or modifying data directly on the storage of the linked PC.

To overcome this limitation and efficiently analyze and visualize the data, external tools become essential. In our experiment, we employed the following external tools:

1. **Open the `Measurements.xlsx` file:**
   - Ensure you have an Excel file named `Measurements.xlsx` ready for data storage. If not, create a new Excel file.

2. **Ensure the Data Streamer Tab is Present:**
   - If the Data Streamer tab is not visible in Excel, follow [this link](https://support.microsoft.com/en-us/office/enable-the-data-streamer-add-in-70052b28-3b00-41e7-8ab6-8a9f142dffeb) to enable it.

<p align="center">
  <img src="/images/datastream.png"/>
</p>

3. **Connect Arduino to a Different USB Port:**
   - After placing the car approximately at the setpoint and uploading the PID.ino code with the required parameters, unplug the Arduino USB cable and reconnect it to a different USB port. This ensures a proper connection.

4. **Connect Arduino using 'Connect a Device' Option:**
   - Click on 'Connect a Device' in the Data Streamer tab. Choose the 'COMx' port where Arduino is connected.

5. **Adjust Special Settings:**
   - Open the Settings tab at the bottom of the Excel file.
   - Set `Data Interval(ms)` to 100 and `Data Rows` to 500.

<p align="center">
  <img src="/images/settingstab.pnh.png"/>
</p>   

6. **Start and Record Data in Excel:**
   - Click 'Start Data' to begin capturing data.
   - Once started, click 'Record Data' to save the measured position data to a .csv file (e.g., 'trial.csv').
   - Create a disturbance by pushing the car, and when the system settles down, click 'Stop Recording'. Save this data as a .csv file.

7. **Open MATLAB:**
   - Launch MATLAB for further analysis.

8. **Import Data to MATLAB:**
   - Click 'Import Data' in the Home tab in MATLAB.
   - Choose the corresponding .csv file ('trial.csv' in this case).
   - Select the column where the measurements are present.

<p align="center">
  <img src="/images/importmatlab.png"/>
</p>

9. **Plot the Response:**
   - Use the provided `data_plotter.m` code in MATLAB to plot the response. Modify the code based on your specific data and preferences.

<p align="center">
  <img src="/images/example.png"/>
</p>

## Conclusion

In wrapping up our journey with the Ball and Beam control system, we've not only deepened our understanding of control theory but also had a good time doing it. Tackling the challenges of system modeling, hardware tinkering, and algorithm implementation as a team of three brought both joy and valuable lessons.

Selecting our project, getting hands-on with hardware, and implementing various control algorithms allowed us to bridge theory and real-world application. Dealing with the Arduino's limitations in direct PC communication led us to appreciate the importance of external tools like Excel’s Data Streamer and MATLAB for data analysis and visualization.

## References

1. [Ball & Beam: System Modeling](https://ctms.engin.umich.edu/CTMS/index.php?example=BallBeam&section=SimulinkModeling)
2. [AntonAshraf/Ball-Beam-PID-Control](https://github.com/AntonAshraf/Ball-Beam-PID-Control)
3. Electronoobs Designs
   - [YouTube Channel](https://www.youtube.com/@ELECTRONOOBS)
   - [3D Parts Video](https://youtu.be/JFTJ2SS4xyA?si=9nZ70lV41_FnEzLK)

*Authors: Ahmmet Cankardes, Furkan Karatoprak, Nermin Bozkurt*