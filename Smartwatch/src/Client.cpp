
#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// #include <ESP8266WiFi.h>

#define PORT 4444

int main() {

    // create socket
    int s = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    struct hostent *en;
    
    // // Block user input
    // char username[10] = "";
    // printf("Enter your username: ");
    // fgets(username,10, stdin);

    // Block server input
    char serveraddr[15] = "";
    printf("Enter your server: ");
    fgets(serveraddr,15, stdin);
    
    // Bind the IP address and the port to a socket
    addr.sin_addr.s_addr= inet_addr(serveraddr);
    addr.sin_port = htons(PORT);
    addr.sin_family = AF_INET;

    // connect to server
    if (connect(s, (struct sockaddr*) &addr, sizeof(struct sockaddr)) == -1) {
        perror("Error connecting");
        return EXIT_FAILURE;
    }

  while (true){

  // Waiting for server to send data
    unsigned short bytesReceived = recv(s, 4096);
    int read_callback(int bytesReceived){
//    bytesReceived = struct.unpack('<4H', bytesReceived);      // Convert bytesarray readed into bytes (for each line). '<' shows le sens de lecture

    struct_unpack(buf1, "i", &rval);
    struct_unpack(buf2, fmt, rstr);


    int id_value = bytesReceived[0];
    float timer_value = round(bytesReceived[1] / 10**3, 1);
    float temperature_value = bytesReceived[2] / 10;
    float V0 = N0/D0 * bytesReceived[3] - X0;              // V0 is the voltage readout
    float I = -V0 * N1/D1;                               // Current
    float cg = I/N2}                                     // Glucose concentration
    if (bytesReceived == SOCKET_ERROR){
      cerr << "Error in recv(). Quitting" <<end1;
    
    }

  }




