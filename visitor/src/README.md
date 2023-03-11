# Visitor Pattern

## Intent

Represent an operation to be performed on the elements of an object structure. Visitor lets you define a new operation without changing the classes of the elements on which it operates.

## Applicability

Use the Visitor pattern when you have an object structure that contains many classes of objects with differing interfaces, and you want to perform operations on these objects that depend on their concrete classes.

## Structure

![Visitor Pattern Structure]()

## Classes

### Visitor

Declares a Visit operation for each class of ConcreteElement in the object structure. The operation's name and signature identifies the class that sends the Visit request to the visitor. That lets the visitor determine the concrete class of the element being visited. Then the visitor can access the element directly through its particular interface.

### Serializer

Implements each operation declared by Visitor. Each operation implements a fragment of the algorithm defined for the corresponding class of object in the structure. ConcreteVisitor provides the context for the algorithm and stores its local state. This state often accumulates results during the traversal of the structure.

## Entity

Defines an Accept operation that takes a visitor as an argument.

## Monster (Entity)

Children of Entity, Accept calls the visitor's Visit operation that corresponds to its class.

## Hero (Entity)

Children of Entity, Accept calls the visitor's Visit operation that corresponds to its class.
