/*
    This file should contain the necessary code to run the server on a socket that will manage
    the data sent between programs as a subprocess

    This code should run asynchronously and multi-threaded in order to operate as fast as possible with 
    consistency regardless of duration.
*/

#include <stdio.h>
#include <stdbool.h>

#include "system.c"

#define ADDRESS "192.168.0.21"
#define PORT 8080
#define HEADER 64
#define FORMAT "utf-8"

// https://www.tutorialspoint.com/multithreading-in-c
// https://www.educative.io/edpresso/how-to-implement-tcp-sockets-in-c

void start_server() {
    
}