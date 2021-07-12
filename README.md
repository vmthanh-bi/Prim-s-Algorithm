<!-- PROJECT START -->
# Prim-s-Algorithm
Writing Prim's algorithm to find the *shortest path* for a given set of a graph's edges and vertices.

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#help">Help</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About the project

In a weighted, undirected graph *the shortest path problem* is the problem of finding the shortest path connecting one vertex (the start vertex)
to another vertex (the destination vertex).

To solve this problem, I will use a setup similar to the Breadth First Search (BFS) algorithm. Every vertex in the graph will contain both a *d* 
value and a predecessor pointer. By following the chain of predecessor pointers backwards from a destination to the source, we will be able to 
construct the shortest path from the source to the destination.

The objective of this program is to implement Prim's algorithm in order to use the vertices of a certain graph and find the shortest path.

<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

Things you need to use the software.
* MacOS
* Xcode

### Installation

Clone this repo.
   ```sh
   git clone https://github.com/vmthanh-bi/Prim-s-Algorithm.git
   ```

<!-- Help -->
## Help

See the [open issues](https://github.com/vmthanh-bi/Prim-s-Algorithm/issues) for a list of proposed features (and known issues).

<!-- CONTACT -->
## Contact

Tony Vu - [@vmthanh.bi](https://github.com/vmthanh-bi) - vmthanh.bi@gmail.com

Project Link: [https://github.com/vmthanh-bi/Prim-s-Algorithm](https://github.com/vmthanh-bi/Prim-s-Algorithm)

<!-- MARKDOWN LINKS & IMAGES -->

