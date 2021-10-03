### Overview
This project is split into two modules: **Container** and **Sort**. Each provides an interface
exposing the common functions available from any class derived from either of these two
top-level classes.

## Container
A container is a versitile data structure. Depending on the implementation, it may be backed
by an array, a linked list, graph, etc.

Containers must be searchable and sortable. Containers so not need to have a uniform type,
however, all elements in the container should be comparable in a way that is semantically
correct.

## Sort
Sort exposes different strategies for ordering elements in a container. For graph or tree-like
structures, sort may return an array or a list of ordered values (it must return a container,
or throw an exception)
