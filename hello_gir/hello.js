const Hello = imports.gi.Hello;

let greet = new Hello.World();

greet.set_greeting("hello world from javascript!");
print(greet.get_greeting());

