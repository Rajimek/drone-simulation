## Collaborators:
- Name: Connor Holm (holm0850), Raji Mekonen (mekon033), Alexandra Delacruz (delac105), Curtis Kokuloku (kokul003)

## Project Description
The project introduces a dynamic system employing drones to deliver packages to designated robot customers within the University of Minnesota campus. It integrates a fleet of drones operating autonomously in a simulated environment mimicking the university campus. The drones have a variety of diverse routing algorithms, including Depth-First Search (DFS), Breadth-First Search (BFS), A* (Astar), and Dijkstra, to optimize delivery routes and enhance system efficiency. The simulation environment replicates campus features, obstacles, and varied terrains to challenge the routing algorithms and drones' navigation capabilities realistically. Utilizing C++ as the backend language, the project implements robust code to manage complex computations, drone movements, and algorithmic calculations seamlessly. The project aims to analyze and compare the efficacy of these algorithms, optimize package delivery routes, and evaluate the feasibility of drone-based delivery systems in a campus setting. Additionally, all the code was written in a SOLID fashion to allow for easy extensibility and maintainability especially when working with a large team.

## Running Simulation
In order to run the simulation, you must first clone the code onto your local machine. Once you have done this, you can run the simulation by running the following commands in the terminal:

* `make run`

> Note that this will start running a local server on the default port 8081.

Additionally, you can clean the build files by running the following command in the terminal:

* `make clean`

## UML Diagram
<object data="./UML_Diagram" type="application/pdf" width="700px" height="700px">
    <embed src="./UML_Diagram">
        <p>This browser does not support PDFs. Please download the PDF to view it: <a href="./UML_Diagram.pdf">Download PDF</a>.</p>
    </embed>
</object>

## Docker
View project on Docker Hub: [link](https://hub.docker.com/r/mekon033/final_drone_sim)
