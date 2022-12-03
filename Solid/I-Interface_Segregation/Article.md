# Interface Segregation Principle made simple

## How granularity will improve your code resilience to changing requirements in real-world applications.

![](https://miro.medium.com/max/700/1*y4VS9XUxG_EZqClInuiGGg.png)

©Mihai Sandu

Both images above are formed from the same number of pixels, but while one looks like a bear, the other one looks more like a shocked square. It is not a difference of quantity, but one of granularity. It is easier to compose something with smaller pieces.

The same logic can be applied to writing good, resilient code. Client code shouldn’t be forced to implement methods that it doesn’t use. This is the Interface Segregation Principle as defined by Robert C. Martin.

Code should be flexible enough to allow client code to use only the needed abstractions. This makes classes easier to understand and to compose.

# The Autonomous Driving System Problem

In the Liskov Substitution  we had to build two modules that control a normal car. The modules are:

- a module that transforms the car into a “drivable” object. This module supports four simple commands: go forward or backward, turn left or right.
- an AutoPilot module that calculates a route and drives the car with the help of the four commands exposed by the drivable module.

After building the software, we have installed it on cars and trucks. Everything went well until the company decided to expand into the train market. This is where we’ve hit our first speedbump.

![](https://miro.medium.com/max/700/1*I1ssa2070cIhtJ2Uhv39nQ.png)

Trains can’t turn left or right. ©Mihai Sandu

Because we defined the IDrivable interface based on the first implementation of the Car class, we’ve ended up with an interface with four methods. While not a problem for cars and trucks, it’s a big NO for trains. We need to reimagine the solution.

## Segregate the interface

Since the problem was with TurnRight or Left, we can split the interface into ITurnable and IDrivable interfaces. Now, objects can choose what they do and implement only the needed methods.

Ok, this seems like a pretty good abstraction, right? Before reading on, think if we can spot any issues.

## The plot twist — plane autonomous module

Our software has been so great that the company wants to expand in another market, planes. This creates another problem: planes can move forward and take turns, but they can’t go backward (at least not while flying).

Again, we are breaking the [Liskov Substitution Principle](https://levelup.gitconnected.com/the-liskov-substitution-principle-made-simple-5e69165e7ab5). Since IDrivable defines both GoForward() and GoBackward() methods we have to throw a NotImplementedException for GoBackward.

# In real-world, you can’t always have the perfect abstraction

Sometimes it’s just impossible to foresee what the client will need. So there are times when past abstractions turn out to be wrong. What can we do?

Leave them be and create new ones. Think of your code as an append-only system. So whenever we have some wrong abstractions in production, leave them be. At that point, probably other clients are already using the interfaces and any changes to them will create a cascade of issues.

![](https://miro.medium.com/max/700/0*rJCQRNp2L3AOwozG)

Your code can act like the strangler fig. Photo by [David Clode](https://unsplash.com/@davidclode?utm_source=medium&utm_medium=referral) on [Unsplash](https://unsplash.com/?utm_source=medium&utm_medium=referral)

Instead, **use the Strangler pattern**. The strangler fig is a plant growing around a tree. Slowly, the plant grows so big that it covers the entire host tree taking its sun and nutrients from the soil. In the end, the tree will die and the fig will become tree-like. It will retain the original tree form but with no sign of the host.

The same thing can be done in real-world code. Going back to the IDrivable problem, we can leave the original interface and create the two new ones, IForwardDrivable and IBackwardDrivable.

Then, mark the old interface as deprecated. Java, C#, Javascript, Python all support signaling deprecated methods. This allows the client code to update on its own timeframe. And after at least a year, you can assume the code has been updated and safely “kill” the original interface. This approach resembles the lazy execution.

# Be careful

The ideal interface should have only one method, also known as Role interfaces. That’s the most granular interface possible and it will provide the most flexibility. As we saw in the autonomous driving problem, breaking the GoForward() and GoBackward() from the beginning could have saved us a refactoring.

So why didn’t I also break the ITurnable interface? I could have defined an ITurnRight and ITurnLeft interface. But would it have made sense? Is there any motorized vehicle that can only turn in one direction and not the other? Personally, I can’t think of one.

Having the methods split into two interfaces would have added code complexity with 0 benefits. This is how the principle might make your codebase too granular. So be careful. Separate but if there are methods that can’t live one without the other, maybe it’s best to keep them together.

Don’t confuse this principle with the Single Responsibility Principle. At a first glance, they might seem similar, but they target different problems. The Single Responsibility Principle tries to help you define a class around a single reason for the change. The Interface Segregation Principle is a blueprint for how to define interfaces. A class can implement as many interfaces as it wants.

# Takeaways

- Avoid at all costs extracting an interface based on a class. Interfaces aren’t defined by classes, but by the client’s needs.
- The fewer the methods in the interface the better. But don’t overdo it. For example, if you implement a Repository interface, don’t write an interface for Add, one for Update, one for Get, and so on. But something like IReadOnlyRepository and IFullAccessRepository might make sense.
- Production code should be append-only (and delete eventually). Use the strangler pattern. Whenever a deployed interface needs changes, leave it. Create the new abstraction and mark the old one as deprecated. Only after at least a year, delete the deprecated interface.
- the full benefits of the principle are reaped when it is applied together with the other SOLID principles.
