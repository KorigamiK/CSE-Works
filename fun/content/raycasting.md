# Raycasting Adventures

This is going to be more of a summary and some implementation details of
my first ever experience with computer graphics and making games.

Two weeks ago, not knowing anything about computer graphics and game
development, I embarked on a journey down the rabbit hole of creating
one of the pioneering games of video game history, such as the OG *Doom*
and *Wolfenstein 3D*.

I decided to create a raycasting engine in *C++* using the *Simple
DirectMedia Layer* graphics library. And for a beginner like me, it was
quite the challenge.

The whole idea of making this in a very bare-bones library and language
like *SDL2* and *C++* was because I wanted to create something that
would be truly cross-platform from the start. And by cross-platform I
mean **cross-platform**. The game would run on all desktop operating
systems (Linux, Windows, Apple) and all mobile operating systems
(Android, iOS, Raspberry Pi, Chrome)! And of course the
[PSP]{.smallcaps}. I could talk a lot about why the PSP, but I'll save
that for another time.

## Introduction {#introduction .unnumbered}

Now you must be asking - \"Bruh, what even is a Raycaster\".

The simplest way to explain it is that it's a rendering technique to
create a 3D perspective from a 2D map, what we like to call as 2.5D.

Although this is about the making of a raycasting game engine, I had to
give a lot of thought on how game engines are structured in the first
place.

I wanted my project to follow the *Object-Oriented* design pattern as
well so that it would be easy to extend and plug in components without
touching a lot of code, enabling a deeper level of abstraction. I taught
me a lot about inheritance and composition in C++.

## The Game Engine {#the-game-engine .unnumbered}

I'll talk about the game architecture in this section.

The engine was written in C++ and then compiled using the *CMake* build
system, which enables me to go completely cross-platform.

The high level architecture of the engine looks something like this:\

## Raycasting {#raycasting .unnumbered}

What actually distinguishes my project from any other implementation
that you may find on the web is the fact that instead of dividing the
whole world into square grids, it defines all the objects and texture
rendering using their actual coordinates.

Looking back, using the 2D grid approach while being a lot easier to
implement, it's also quite a bit more efficient and accurate.

Having said that, it also restricts a lot of what can be actually
created in the game.

The biggest leap of faith I took for this engine was to create the
raycasting logic. So, here's how raycasting actually works.

We first need to define these terms:

-   **Player direction $\alpha$ :** The direction that the player is
    currently facing.

-   **Maximum view distance $d$ :** The position of the player in the
    world.

-   **Horizontal field of view $\Omega$ :** The visible field of view
    the player sees in the horizontal direction. I assumed this to be,
    100°.

-   **Vertical field of view :** This gives an idea of how high or low
    can the person see. I assume this to be, 60°.

-   **Number of rays :** This is the number of rays that we cast from
    the player's position. You can set this number a lot of ways, and
    how high you set this will determine how accurate the raycasting
    will be.

Now we are ready to tackle the actual casting of rays. What our aim is
to cast a ray from the player's position in the direction of the
player's direction $\alpha$ and then check if it intersects with any of
the walls in the map. If it does, then we need to calculate the distance
between the player and the wall and then draw a slice of the player's
view corresponding to that ray.

So, consider this diagram of the player's situation:

![Raycasting](./images/raycasting.png){#fig:rays width="\\textwidth"}

This circle corresponds to the player's maximum view distance ($d$).

It should be noted that half of the cast rays would be on the left side
of the player's field of view ($\frac{\Omega}{2}$) and the other half
would be on the right side.

Now, we can define the angle between each ray as:

$$\delta = \frac{\text{Vertical field of view}}{\text{Rays casted}}$$

We are going to construct the view of the player by drawing a slice of
the view for each ray. The rays would be equally spaced (suspending the
angle $\gamma$ at the player) starting from point $O$ till the
$X_{max}$.

We'll calculate $X_{max}$ (distance taken from $O$) by using the
following formula:

$$X_{max} = 2 d \sin\frac{\Omega}{2}$$

So, the distance $X$ for any ray at angle $\beta$ would be:

$$X = d \cos\frac{\Omega}{2} \tan\beta$$

Now, we can calculate the width of the slice ($W$) for each ray as:

$$W = \frac{X_{max}}{2} + d \cos\frac{\Omega}{2} (\tan\beta - \tan(\beta - \delta))$$
