#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <Windows.h>

int main (void)
{
    printf ("Connecting to hello world server…\n");
    void *context = zmq_ctx_new ();
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://localhost:5555");

    int request_nbr;
    while (1) {
        char output[10] = "Abcdefghi\0";
        fgets(output, 10, stdin);
        char buffer [10];
        zmq_send (requester, output, 10, 0);
        zmq_recv (requester, buffer, 10, 0);
    }
    zmq_close (requester);
    zmq_ctx_destroy (context);
    return 0;
}