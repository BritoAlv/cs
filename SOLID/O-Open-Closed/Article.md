# The Open-Closed principle made simple

## Following this principle should spare you from new bugs when adding new features to existing code.

![](https://miro.medium.com/max/700/1*RDuO4HcI6aPlxMozRNQO8w.png)

©Mihai Sandu

Trucks are one versatile piece of equipment. They can do different tasks based on the type of trailer attached to them. We can even chain trailers (if the load-weight allows it).

In short, trucks are **open** for extension with different trailers but **closed** to modifications (like engine or cabin). Writing extensible code should be just as easy as swapping trailers on a truck.

# The Ice-Cream maker problem

Let’s imagine we have to write a program that makes cacao ice cream for Ted&Kelly Ice-Cream Corp.

The code, although basic, looks ok. No principle seems to be broken. We deliver the software to our client and he is satisfied.

But we are coding real-world applications. This means requirements change and new features are requested all the time.

## First Requirement change — add new flavor

The initial program was such a big hit that Ted&Kelly wants to expand. They ask us to add support for vanilla ice cream.

After some thought, we end up with the following solution:

We modify the original code, add a parameter to specify the desired flavor, and add an “if” statement to switch between logics. Since we have updated the original method signature, the methods that were calling our code will be broken, but at least from now on, we should support additional flavors without breaking changes.

## Second Requirement change — create a cacao and vanilla combo

Business is going well so the client wants to add a combo, an ice cream made of cacao and vanilla. Things start to get complicated, but we can manage it.

We add another if statement and in this case the “logic” was copied inside each if. In a real-world application, I would probably extract the logic in a separate service. But as we will see, extracting services isn’t always the best idea.

What will happen when the Ted&Kelly Corp will ask for more flavors. What if he wants to combine them even further? Just adding if-clauses isn’t the ideal solution.

## Issues with this solution

Every time we add a new flavor or combo we have to update the IceCreamMachine class. This means:

- we update already deployed code
- the class becomes harder and harder to read. Imagine if we had 100 flavors. The class would easily bloat to 5000+ lines of code
- we could break existing unit tests

Think back to the truck analogy. Would you change the engine every time you change the trailer? Probably not. Let’s see how we can fix it.

# The Legacy approach to extensibility

Bertrand Meyer is the parent of the Open-Closed principle and he defined it as “S*oftware entities (classes, modules, functions, etc.) should be open for extension, but closed for modification.*”

In other words, whenever we need to add new behavior to old objects, inherit and update them as needed. The Open-Closed is one of those easy-to-understand hard to apply principles.

Let’s rewrite the code to follow this approach:

So what happened? The original class was broken up into four, one for every flavor plus a base object. With this solution we solved all initial problems:

- classes are small so it is easier to understand and manage them
- whenever a new flavor is needed we just add a new class
- existing unit tests aren’t impacted

On paper everything looks ok and we could stop here but there are some **issues with this solution**:

- can’t inherit multiple classes. So for a two flavor combo, we have to duplicate some code or extract the logic into a service
- if the code in the base class is updated, all class children are impacted. Imagine the base class has some dependencies injected through a constructor, every time we add a new dependency, all children have to parse that parameter to the base constructor

# The Modern approach to extensibility

When Robert C. Martin reiterated the principle from Meyer, he updated to **favor composition over inheritance**.

When we compose objects, we have the freedom to compose as many as we want and how we want. And if we program against abstractions (interfaces) we have the power to change the behavior of existing code without modifications. Let’s see the final solution:

I’ve broken the original class into three objects:

- **IMakeIceCream** interface defines the common abstraction for making an ice cream
- **CacaoIceCream** class which implements IMakeIceCream
- **VanillaIceCream** class which implements IMakeIceCream

By using interfaces we decouple classes and implementations. Interfaces are closed for modifications so once we define one, it can’t be changed. But we can define new interfaces for new features and inherit them. That makes the code extendable.

Why did I add an “IMakeIceCream” parameter to each constructor? Does the new code have all the features of the old or legacy approach?

The answer is YES. The cacao-vanilla combo is still here but we don’t need an if-clause or a class dedicated to it. We can leverage the constructor parameter.

var cacaoVanillaIceCream = new CacaoIceCream(new VanillaIceCream());cacaoVanillaIceCream.Make();

That’s it. The beauty of composition is that we can compose as many objects as we want, how we want them. Need 4 flavors? Just write a chain of constructors. This is called the **decorator** pattern. You can read more about it.

Notice that the IMakeIceCream parameter is optional. This allows me to use the class in composition or on its own.

Writing code like this leads to plugin architecture. This is great as we can add new features by writing code and never change the existing one. Mission completed.
