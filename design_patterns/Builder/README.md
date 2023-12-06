# BUILDER
Separate the construction of a complex object of your representation, so that the same build process can to create differents representations.
## Concepts
- Some objects are simple and can be created in single constructor call
- Other objects require a lot of ceremony to create
- Having an object with 10 constructor arguments is not productive 
- Instead, opt for piecewise construcrion
- Builder provides an API for constructing an object step-by-step