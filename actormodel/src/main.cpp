#include <iostream>
#include "application.h"

int main(int argc, char** argv)
{
  MessageDispatcher::Application app(argc, argv);
  return app.exec();
}
