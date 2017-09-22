# WAGLM
> **W**eb **A**ssembly **GL** **M**atrix

Inspired heavily by [gl-matrix](https://github.com/toji/gl-matrix/). Vector and Matrix operations for high performance WebGL apps. Waglm is **not** production ready.
_______________________________
<div style="text-align:center">
<img src="https://upload.wikimedia.org/wikipedia/commons/3/30/WebAssembly_Logo.png" align="center" width="120">
<br>
<small>Now 100% more wasm!</small>
</div>

_______________________________

### Getting Started
Like most web assembly apps, this one requires some familiarity with the [Emscripten](https://github.com/kripken/emscripten) toolchain. **Note:** the wasm world is changing fast. These instructions may not be current.

1. Get started with Emscripten. [Tutorial](https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm)

2. Clone the repo

3. Build wasm with `npm run build`
    - Runs emcc `/build/build.js`
    - `/build/config.js` contains configuration options for emcc

4. Run a server and navigate to `/bin/waglm.html`
    - try [http-server](https://www.npmjs.com/package/http-server)

5. Profit!

6. Build an exe with gcc (requires [mingw](http://www.mingw.org/)) with `npm run build:exe`
    - This can be helpful to get a second compiler output.

### Hints

- Compiled wasm runs in the browser. As such, you don't need to stall the program to prevent near-immediate exit. However, remember to add something like `std::cin >> a` when compiling an .exe so you can inspect the console output.

