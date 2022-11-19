## The Autonomous Driving System Problem

As part of the software engineering team at AutoPilotCars AI startup, we have to come up with a solution to control normal cars (like a Toyota Camry).

After much thought, the team has decided to build two modules:

- a module that transforms the car into a “drivable” object. This module supports four simple commands: go forward or backward, turn left or right.
- an AutoPilot module that calculates a route and drives the car with the help of the four commands exposed by the drivable module.

Here is a diagram:

![](https://miro.medium.com/max/700/1*Y9nlNMTtxSaXmB9Sjv33eA.png)

We have to build two modules: one to control the car and one to drive the car. ©Mihai Sandu

And some basic C# code:



## Expanding into the truck market

Since our two modules were incredibly successful, the company decides to extend into a new market, trucks. We observe that trucks support the same kind of commands as cars do, so we want to reuse the AutoPilot module and reimplement the Drivable module.

We will extract the common abstractions into a separate interface and let the AutoPilot module control the drivable object. Here is the solution:

Based on the Car class, we have extracted the “IDrivable” interface. Now, the AutoPilot class depends on the IDrivable interface. All good up to here.

Things are going wonderfully so our company wants to expand into trains.

![](https://miro.medium.com/max/700/1*I1ssa2070cIhtJ2Uhv39nQ.png)

Trains can’t turn left or right. ©Mihai Sandu

This is our first speedbump. Trains can’t turn left or right since they are on tracks. So we have no choice but to overlook implementing the TurnLeft() and TurnRight() methods. That means throwing NotImplementedException or doing nothing (since in this case, the method returns void).

# **The problem**

Imagine that there is an AI algorithm behind the AutoPilot module. After countless hours of training, it finally mastered the four directions. The module doesn’t know if it controls a car, a truck, or a train, it just knows it will receive an “IDrivable” object.

For cars and trucks it works flawlessly, but for trains? We have two possible outcomes:

- if the TurnLeft() and TurnRight() methods throw an exception, it will unexpectedly stop the program at runtime. No good
- if the methods do nothing, the algorithm could learn to either ignore them (which is not good because on cars and trucks we don’t want them to be ignored) or could remain stuck on an infinite loop trying to take a turn. No good again

We broke the Liskov substitution principle by inheriting the IDrivable interface. Our AutoPilot class works only if we get a Car or a Truck, not a Train.

## Solution

We could omit to inherit the IDrivable interface for the Train class. This will have the logic separated and so all code looks ok. But doing this will also mean we have to build another AutoPilot module just for trains. Expensive.

We could update the AutoPilot module and verify if the received object is a Train. And update the code accordingly. But this is the first step before falling down the rabbit hole. And if leads to another if and so on until we reach a point where we wonder wtf happened.
