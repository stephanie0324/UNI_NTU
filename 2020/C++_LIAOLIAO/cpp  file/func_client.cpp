# include "func_client.h"
using namespace std;

ClientDuan::ClientDuan()
{
    printf("Part I: set socket\n");
    // socket declaration
    int clientSockfd = 0;
    clientSockfd = socket(AF_INET, SOCK_STREAM , 0);

    if (clientSockfd == -1)
        printf("\tFail to create a socket.");

    // socket initialization
    printf("\tinitializing connecting to server!\n");
    bzero(&serverInfo, sizeof(serverInfo)); // initialize
    serverInfo.sin_family = PF_INET;  // ipv4

    /* local */
    serverInfo.sin_addr.s_addr = inet_addr("127.0.0.1");     // local IP address
    serverInfo.sin_port = htons(8700);                       // local port */

    /* csie server (net0)
    serverInfo.sin_addr.s_addr = inet_addr("140.112.30.40"); // net0 IP address
    serverInfo.sin_port = htons(2400);                       // net0 port */
}

void ClientDuan::connectToServer()
{
    // socket connection
    printf("\ttry to connect to server, result ==> ");
    int err = connect(clientSockfd, (struct sockaddr *)& serverInfo, sizeof(serverInfo));

    if (err == -1)
        printf("ERROR\n");
    else
    {
        printf("SUCCESS\n\n");

        // Part II: I/O
        printf("Part II: starting I/O\n");

        // pthread
        pthread_t thread[JOBS];

        // set pthread Argument
        bool connect = true;
        Argument args;
        args.clientSockfd = clientSockfd;
        args.serverInfo = serverInfo;
        args.connectPtr = &connect;

        // keep client alive
        while (true)
        {
            // receiving all others' chat record
            pthread_create(&thread[0], nullptr, othersMessage, (void*)& args);
            pthread_create(&thread[1], nullptr, myMessage, (void*)& args);
            if (*args.connectPtr == false)
                break;
        }

        // close client socket
        close(clientSockfd);
        printf("Client close Socket\n");
    }
}

// waiting for othres' message
void* ClientDuan::othersMessage(void* argsVoid)
{
    // parse args
    Argument* args = (Argument*) argsVoid;
    int clientSockfd = args->clientSockfd;
//	struct sockaddr_in serverInfo = args->serverInfo;

    while (true)
    {
        char receiveMessage[MAXSTR];
        bool check = *((Argument*) argsVoid)->connectPtr;
        if (check == false)
            break;

        recv(clientSockfd, receiveMessage, sizeof(receiveMessage), 0);
        printf("%s\n", receiveMessage);

        if (strcmp(receiveMessage, ULE_MESSAGE) == 0)
        {
            // ULE exceed
            *( ((Argument*) argsVoid )->connectPtr ) = false;
            break;
        }
    }

    return nullptr;
}

// send my message
void* ClientDuan::myMessage(void* argsVoid)
{
    // parse args
    Argument* args = (Argument*) argsVoid;
    int clientSockfd = args->clientSockfd;
//	struct sockaddr_in serverInfo = args->serverInfo;

    // line
    char myWord[MAXSTR];
    while (cin.getline(myWord, MAXSTR))
    {
        // Send a message to server
        // char receiveMessage[MAXSTR];
        send(clientSockfd, myWord, sizeof(myWord), 0);

        // receive message from server
        // recv(clientSockfd, receiveMessage, sizeof(receiveMessage), 0);
        // printf("%s\n", receiveMessage);

        if (strcmp(myWord, "exit") == 0)
        {
            // want to quit
            *( ((Argument*) argsVoid )->connectPtr ) = false;
            break;
        }
    }

    return nullptr;
}
