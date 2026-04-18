# GLbasic — Minimal OpenGL Rendering Framework

GLbasic is a structured OpenGL rendering framework built from scratch to understand and implement a clean graphics pipeline architecture using modern OpenGL (Core Profile).

This project is not a tutorial dump — it is an attempt to design a **modular, scalable rendering system** with clear separation of responsibilities.

---

## 🚀 Features

* Custom Buffer abstraction (VBO/EBO)
* Vertex Array Object (VAO) management
* Mesh system with indexed & non-indexed rendering
* Minimal Renderer abstraction
* Window and input handling using GLFW
* Clean separation between data, state, and execution

---

## 🧠 Architecture Overview

The rendering pipeline is structured into independent components:

```
CPU Data → Buffer → VertexArray → Mesh → Renderer → GPU
```

### Core Components

| Component   | Responsibility                              |
| ----------- | ------------------------------------------- |
| Buffer      | Manages GPU memory (VBO/EBO)                |
| VertexArray | Stores attribute layout and buffer bindings |
| Mesh        | Represents drawable geometry                |
| Renderer    | Executes draw calls                         |
| Shader      | Compiles and manages GPU programs           |
| Window      | Handles OpenGL context and input            |

---

## 🔧 Design Principles

* **Separation of Concerns**

  * Geometry (Mesh) is independent of rendering logic (Renderer)
  * Shader is not owned by Mesh
* **Minimal Abstraction**

  * No over-engineering in V1
  * Direct mapping to OpenGL concepts
* **Deterministic Behavior**

  * No hidden state changes
  * Explicit control over bindings
* **Extensibility**

  * Designed to evolve into a full engine (V2+)

---

## 📦 Project Structure

```
GLbasic/
│
├── src/
│   ├── graphic/
│   │   ├── Buffer.*
│   │   ├── VertexArray.*
│   │   ├── Mesh.*
│   │   ├── Renderer.*
│   │   └── Shader.*
│   │
│   ├── window/
│   │   └── Window.*
│   │
│   └── main.cpp
│
├── shaders/
├── libs/
├── CMakeLists.txt
└── .gitignore
```

---

## ⚙️ Build & Run

### Requirements

* C++17 or later
* OpenGL 3.3+
* GLFW
* GLAD
* CMake

---

### Build Steps

```bash
git clone https://github.com/KrishMaheshwariDev/LearningOpenGL.git
cd GLbasic

mkdir build
cd build

cmake ..
cmake --build .
```

---

### Run

```bash
./GLbasic
```

(Windows)

```bash
GLbasic.exe
```

---

## 🧪 Current Capabilities

* Render triangle (non-indexed)
* Render quad using EBO (indexed rendering)
* Basic shader pipeline

---

## ⚠️ Known Limitations (V1)

* No camera system
* No transformation matrices (MVP)
* No material/texture system
* Single VBO per mesh
* No instancing or batching

---

## 🧭 Roadmap

### V1 (Current)

* Basic pipeline
* Clean abstractions
* Working rendering loop

### V2 (Planned)

* Layout abstraction system
* Multiple buffer support
* Material & texture system
* MVP transformations

### V3 (Future)

* Scene graph
* Camera system
* Lighting
* Instancing
* Engine-level architecture

---

## 📄 Documentation (WIP)

Full documentation will be available as a static website:

* Architecture deep dive
* Design decisions
* Internal data flow
* Usage guide

---

## 🎯 Goal of This Project

This project is built to:

* Understand OpenGL beyond tutorials
* Design scalable rendering architecture
* Practice low-level system design in C++

---

## 🤝 Contributing

This is a personal learning + system design project. Contributions are welcome but should align with the architectural direction.

---

## 📜 License

TBD

---

## ⚡ Final Note

If you are reading this expecting a ready-made engine, this is not it.

If you want to understand **how a rendering pipeline is structured from scratch**, this is exactly that.
