#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main ( int argc, char* argv[] )
{
	std::cout << "running....\n";
	
	try
    {
		// Create the socket
		// ServerSocket server ( 30000 );
		ServerSocket server (12354);
		
		while ( true )
		{

	  ServerSocket new_sock;
	  server.accept ( new_sock );

	  try
	    {
	      while ( true )
		{
		  std::string data;
		  new_sock >> data;
		  std::cout << data << std::endl;

		  ofstream outfile("/home/kora/桌面/log.txt", ios::app);
		  outfile << data << endl;
		  outfile.close();

		  new_sock << data;
		}
	    }
	  catch ( SocketException& ) {}

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}
