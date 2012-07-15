#include "Server.h"
#include <QtGui>
#include <iostream>
#ifdef Q_OS_UNIX
  #include <unistd.h>
#endif

int main(int argc, char **argv) {
#ifdef Q_OS_UNIX
  if (setpgid(0, 0) < 0) {
    std::cerr << "Unable to set new process group." << std::endl;
    return 1;
  }
#endif

  QApplication app(argc, argv);
  app.setApplicationName("webkit_server");

  Server server(0);

  if (server.start()) {
    std::cout << "webkit_server server started, listening on port: " << server.server_port() << std::endl;
    return app.exec();
  } else {
    std::cerr << "Couldn't start webkit_server." << std::endl;
    return 1;
  }
}

