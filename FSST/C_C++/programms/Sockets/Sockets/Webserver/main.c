#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment (lib, "Ws2_32.lib")

int main(int argc, char** argv) {

    FILE* file = fopen("C:\\Temp\\index.html", "r");
    char html[500];
    memset(html, 0, sizeof(html));
    fread(html, 1, sizeof(html), file);
    fclose(file);

    char response[500] = "response";
    strcat(response, html);

    WSADATA data;
    WSAStartup(MAKEWORD(2, 2), &data);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_info;
    server_info.sin_family = AF_INET;
    server_info.sin_port = htons(5950);
    server_info.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*) & server_info, sizeof(server_info));
    listen(server_socket, 1);

    while (1)
    {
        int client_socket = accept(server_socket, NULL, NULL);
        send(client_socket, response, sizeof(response), 0);
    }

    closesocket(server_socket);
    WSACleanup();

    return 0;
}