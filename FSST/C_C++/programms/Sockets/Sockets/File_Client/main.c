#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment (lib, "Ws2_32.lib")

int main(int argc, char** argv) {

    WSADATA data;
    WSAStartup(MAKEWORD(2, 2), &data);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_info;
    server_info.sin_family = AF_INET;
    server_info.sin_port = htons(5950);
    server_info.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(client_socket, (struct sockaddr*) & server_info, sizeof(server_info));

    char text[] = "C:\\temp\\test.txt";
    send(client_socket, text, sizeof(text), 0);
    char received_text[5000];
    recv(client_socket, received_text, sizeof(received_text), 0);
    printf("Empfangener Text: %s", received_text);

    closesocket(client_socket);
    WSACleanup();

    return 0;
}