#include <zmq.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <person.h>

int main (void)
{

    printf("Starting the server..\n");

    //  Socket to talk to clients
    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REP);
    int rc = zmq_bind (responder, "tcp://*:5555");

    person_t *person = malloc(sizeof(person_t));

    zmq_recv(responder, person, sizeof(person_t), 0);

    if(person->isSet>0){
        print_person(person);
    }else{
        printf("Received bad data.");

        return -1;
    }

    return 0;
}