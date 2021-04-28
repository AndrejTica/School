#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment (lib, "Ws2_32.lib")

int main(int argc, char** argv) {

    WSADATA data;
    WSAStartup(MAKEWORD(2, 2), &data);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_info;
    server_info.sin_family = AF_INET;
    server_info.sin_port = htons(5950);
    server_info.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*) & server_info, sizeof(server_info));
    listen(server_socket, 1);

    int client_socket = accept(server_socket, NULL, NULL);

    char received_text[50];
    recv(client_socket, received_text, sizeof(received_text), 0);

    char response[50] = " Pong";
    strcat(received_text, response);
    send(client_socket, received_text, sizeof(received_text), 0);
    closesocket(server_socket);
    WSACleanup();

    return 0;
}