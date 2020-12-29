// trustcenter.h

#pragma once

#include <map>
#include <string>

#include "ServerSocket.h"
#include "SocketException.h"

#include <iostream>
#include <sstream>

using namespace std;

class TrustCenter {
private:
  int port;
  string n, g;
  map<string, string> pkmap;
  ServerSocket *tc_server;

public:
  TrustCenter(int port = 4444, string n = "5", string g = "7") {
    this->port = port;
    this->n = n;
    this->g = g;

    tc_server = new ServerSocket(port);
  }
  ~TrustCenter() { delete tc_server; }

  string getN() { return n; }
  string getG() { return g; }

  string getPK(string name) {
    map<string, string>::iterator it = pkmap.find(name);

    if (it != pkmap.end())
      return it->second;
    else
      return "";
  }

  void addPK(string name, string pk) { pkmap[name] = pk; }

  void accept() {
    cout << "TrustCenter running on port " << port << "...." << endl;

    while (true) {
      ServerSocket new_sock;
      tc_server->accept(new_sock);

      try {
        string cmd;

        new_sock >> cmd;

        /*
        "GET:NG"
                "123:456"

        "ADD:PK:BOB:123"
                "200 OK"

        "GET:PK:BOB"
                "123"
                "-402"

        "?"
                "-401"

        */
        cout << "SERVER got <" << cmd << ">" << endl;
        unsigned found = cmd.find_last_of("\r\n");
        cmd = cmd.substr(0, found - 1);
        cout << "SERVER got <" << cmd << ">" << endl;

        stringstream ss(cmd);
        string part;

        std::getline(ss, part, ':');

        if (part == "ADD") {
          string name;
          string pk;

          std::getline(ss, part, ':'); // PK
          std::getline(ss, name, ':');
          std::getline(ss, pk, ':');

          this->addPK(name, pk);

          new_sock << "200 OK";

        } else if (part == "GET") {
          std::getline(ss, part, ':'); // PK or NG
          if (part == "NG") {
            std::ostringstream out;
            out << this->getN() << ":" << this->getG();
            new_sock << out.str();

          } else if (part == "PK") {
            std::getline(ss, part, ':'); // name
            string pk = this->getPK(part);
            if (pk == "")
              new_sock << "-401";
            else
              new_sock << pk;

          } else {
            new_sock << "-401";
          }
        } else {
          new_sock << "-401";
        }

        cout << "Server closing connection..." << std::endl;

      } catch (SocketException &e) {
        std::cout << "Exception was caught:" << e.description()
                  << "\nExiting.\n";
      }

    } // while
  }   // accept()
};
