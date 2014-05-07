*********
*  ZIA  *
*********

Language: C++
Notes: third year project
Platform: Linux, Windows

The goal of this project is to provide a modular and RFC compliant HTTP server (web server)
following a common API to all our students.

We have to provide two mandatory modules: a SSL module and a PHP-CGI module.

The project is divided in several steps:
- The complete reading in comprehension of the RFC 2616 (HTTP 1.1)
- The realization of an API which will be submitted to all students as a competition.
  The API defined all hook points of the server, as client socket initialisation, data
  reception and sending, data parsing, and so on.
  We need to promote our API and then, every student can vote for its favourite API.
- When all the votes are closed, we all have to build our server following the winning API,
comporting the PHP and SSL modules.
- In theory, because we are using the same API, all modules from any other student should be
compatible to our core server, and vice versa.

The original API was very simple and aimed to allow every student to build a simple, fast and
solid server without much difficulty.
It is designed following 10 hookpoints:
- Socket, to add some features on a client connexion (used for the SSL module)
- Parse, to modify the request parsing
- RequestMod, to modify the request of the client
- ResponseHeader, to replace the response header
- ResponseHeaderMod, to modify the response header
- AddDataBegin, to add some data at the beginning of the response body
- ExecutionMod, to execute the script (used for the php-cgi module)
- AddDataEnd, to add some data at the end of the response body
- DataModIn, to modify the incoming data (can be used for some compression module for example)
- DataModOut, to modify the outgoing data

This server is designed once again to be stable, simple and fast.

The main features of the architecture are the following:
- A Windows/Unix abstraction is used for any type of system call, which allows the server to be
  Windows and UNIX compatible with the same core
- The "controller" class is the main instance, launching a defined number of servers and watching
  for incoming connection
- The "descriptor controller" listen the incoming port for some new clients and add this client
  to the most available server
- The "server" class represent an instance of a server. Several server instances could exists
  and are managed by the "controller" object
  Each server is launched in a separated thread. The number of server can be modified in the
  configuration file according to the CPU architecture (number of cores ...)
  Each server contains a circular fixed size buffer to divide the read and write load fairly
  on each client.
- Both descriptor controller and server are instanced by the controller
- The "client" class contains all the client information as well as the read and write functions.
  Each client contains its own in/out variable buffer containing its queued data.
  A client is instanced by the selected server, using a "socket" instance created by the
  controller after a client connection.
- When a client connects to the server, the descriptor watcher analyses the connection port,
  and uses the controller to assign it to the most available server.
  Then, the server read the incoming data from the client using a fixed-size circular buffer and
  stores the received data into the client buffer.
  When all data are read, the server first parses the header describing the request, then the body
  if any.
  Then, the server select the desired response (header+body) to send to the user, which could be a
  file (html or anything else) or the result of an external module (php ...).
  All the execution is threaded (forked for the modules) and nothing can block a server.
  The response is sent to the client using the server circular buffers to divide it fairly between
  each client.
