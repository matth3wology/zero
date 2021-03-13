#include <stdio.h>
#include <zmq.h>
#include <person.h>

int main(int argc, char *argv[]) {

    // Create a context and socket
    void *context = zmq_ctx_new();
    void *requester = zmq_socket(context, ZMQ_REQ);
    zmq_connect(requester, "tcp://localhost:5555");

    person_t *person = malloc(sizeof(person_t));

    if(argc > 4){
        set_person(argv, person);
    }

    zmq_send(requester, person, sizeof(person_t), 0);

    // Shutdown Client
    zmq_close(requester);
    zmq_ctx_destroy(context);
    
    return 0;
}