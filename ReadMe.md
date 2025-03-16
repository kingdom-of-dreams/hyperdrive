# Hyperdrive

Another game engine. 

## Why ? Why C ? Why another game engine ? WHY ?

Yes we know, there's plenty of game engine out there (Unity, UnrealEngine, Godot to quote the most known). Each one of them will probably have more features than this one to be honest. But we thought that most of the games made with thoses can be _guessed_. How manu times you play a game and told yourself _Hmmm... Smells like Unity_ ? How many games suddenly acquires photorealistic stuff and great lightning since UE5 ? Did you ever found an asset in several games from different studio ?

At Kingdom of Dreams we have a certain way we want our games to be made, and we're convinced that you could build great games with generic engines, but greater games with a specific, tailor-to-your-needs, engine.

For example, we want to focus on VR and performance, one of the first platform ever we will support is the Oculus Quest 3, which is nothing more than an Android phone with stereoscoping rendering (which means twice the calculation for the rendering part on each frame). Most of the engine quoted above will offer VR support, but clearly as an addon, not as the primary target. And most of them will offer generic implementation where each platform have it's own specificities and performance tweaks available.

Finally, we want to _learn_, and no better way to learn than doing each line of code by ourself with our own thought process, instead of just copy&paste tutorials and obscur lines from documentations.

If we have some fun doing it, that's a bonus !

Now about the `C` part : if we want to control the performance, we need to control the memory layout to the bit, and how instruction are executed and their order. This leaves us with two choice : C or Rust. Rust is fun, but badly supported by the Game platforms. And C, despite is _old age_, is still a language that is supported by anyone, with a standard which can be mark on a single postcard, so it will force us to Keep it Simple.

## How to build it

If you want a full detail you can check the [.github](./.github) folder for a list of continuous integration actions, we cover in them all the platform we support and their build process.

### For Windows 

For building this project on Windows, you'll need VisualStudio (or at least the `msbuild` tool suite). You either run `msbuild` on the `.vcxproj` included at the root of this repo, or import this file directly in your solution in VisualStudio.

(This project was made with VisualStudio 2022).

## Credits & License

This project was created by [Sylvain Nieuwlandt](https://an0rka.dev) for [Kingdom of Dreams](https://github.com/kingdom-of-dreams).

It's released under the Apache 2.0 license, which you should find a complete copy [here](./LICENSE).

_Copyright (C) 2025 by Sylvain Nieuwlandt._