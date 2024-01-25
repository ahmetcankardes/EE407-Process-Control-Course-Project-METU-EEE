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
  <em>Figure 2 - Connection Diagram</em>
</p>

### Control Approach
