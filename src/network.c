/*
    This file should contain the necessary code to run the server on a socket that will manage
    the data sent between programs as a subprocess

    This code should run asynchronously and multi-threaded in order to operate as fast as possible with 
    consistency regardless of duration.
*/

#include <stdio.h>
#include <stdbool.h>

#include "system.c"
#include "security.c"

#define ADDRESS "192.168.0.21"
#define PORT 8080
#define HEADER 64
#define FORMAT "utf-8"

/*
multithreading in c
https://www.tutorialspoint.com/multithreading-in-c

socket programming in c
https://www.educative.io/edpresso/how-to-implement-tcp-sockets-in-c

look through the above links to combine and create a server using tcp socket connections that is also
multithreaded and can handle asynchronous function calls
*/
void start_server() {
    /*
    start the server and when a connection is accepted,
    hash their ip and set that as the thread id upon the opening of the thread.
    */
}